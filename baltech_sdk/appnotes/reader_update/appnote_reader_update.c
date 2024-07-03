/**
 * This app note demonstrates how to implement a configuration and/or
 * firmware update via wired upload.
 *
 * @attention error handling is oversimplified in this code by exiting on
 * failure without releasing resources. This is not recommended in production
 * software!
 */


#include <stdio.h>
#include <stdint.h>
#include <baltech_api.h>


/**
 * Timeout needed to reconnect to a reader after reboot, even if the reader
 * restarts instantly.
 */
#define BASE_RECONNECT_TIMEOUT        10000

/**
 * Specify if the OS port vanishes for a short period of time on reader reboot.
 *
 * has to set to 0 for "real" RS232 (non-virtual COM port)
 */
#define RECONNECT_UNREGISTERS_OS_PORT    1

/**
 * This is the speed (bytes/second) of the reader-host interface.
 * It is only required for accurate progress bars
 */
#define TRANSFER_SPEED               10000


/**
 * If condition is TRUE, the process is stopped immediately and an error is
 * displayed.
 *
 * @attention For simplicity and readabilty this app note relies on the OS
 * to release resources when exit_if() stops due to failure.
 * In production code this is bad practice and should be done explicitly
 * instead!
 */
static void exit_if(bool condition, char *errormessage)
{
	if (condition)
	{
		fprintf(stderr, "\n%s\n", errormessage);
		exit(EXIT_FAILURE);
	}
}


/**
 * Check if an error has occurred. If yes, stop process immediately and show
 * an error message.
 *
 * @attention For simplicity and readabilty this app note relies on the OS
 * to release resources when exit_if() stops due to failure.
 * In production code this is bad practice and should be done explicitly
 * instead!
 */
static void exit_on_error(brp_errcode errcode, char *errormessage)
{
	if (errcode != BRP_OK)
	{
		char * errname = brp_map_errcode(errcode);
		if (errname == NULL)
			fprintf(stderr, "\n%s [brp_errcode:%08X]\n", errormessage, errcode);
		else
			fprintf(stderr, "\n%s [%s]\n", errormessage, errname);
		exit(EXIT_FAILURE);
	}
}


static int parse_hex_byte(FILE * file)
{
	int result;
	if (feof(file) || ferror(file))
		return EOF;
	while (fscanf(file, "%02X", &result) == 0)
	{
		// ignore newlines
		if (getc(file) != '\n')
			return EOF;
	}
	return result;
}


/**
 * Parses the BEC2/BF3 file
 */
static brp_buf load_bec2_bf3_file(char * filepath, size_t * blob_size)
{
	brp_buf blob;
	int byte;
	FILE * file = fopen(filepath, "rt");
	size_t act_blob_size;
	exit_if(file == NULL, "cannot open file");
	
	/* skip header lines */
	while (!feof(file) && !ferror(file))
	{
		int chr = getc(file);
		/* empty line? => end of header */
		if (chr == '\n')
			break;
		/* skip characters until end of line */
		while (chr != '\n' && chr != EOF)
			chr = getc(file);
	}
	
	/* read payload */
	*blob_size = 0;
	act_blob_size = 0x1000;
	blob = malloc(act_blob_size);
	exit_if(blob == NULL, "out of memory");
	while ((byte = parse_hex_byte(file)) != EOF)
	{
		if (*blob_size == act_blob_size)
		{
			act_blob_size *= 2;
			blob = realloc(blob, act_blob_size);
			exit_if(blob == NULL, "out of memory");
		}
		blob[*blob_size] = byte;
		(*blob_size)++;
	}
	
	exit_if(ferror(file), "failed to read file completely");
	fclose(file);
	return blob;
}

typedef struct {
	unsigned estimated_number_of_bytes;
	unsigned estimated_time_overhead;
	brp_time transferred_bytes;
	brp_time waited_time;
} progress_t;

static void show_progress(progress_t * progress)
{
	unsigned estimated_time = progress->estimated_time_overhead
			+ 1000 * progress->estimated_number_of_bytes / TRANSFER_SPEED;
	unsigned actual_time =
			(unsigned) (1000 * progress->transferred_bytes / TRANSFER_SPEED)
			+ (unsigned) progress->waited_time;
	unsigned progress_in_percent = 0;
	if (estimated_time != 0)
		progress_in_percent = min(100 * actual_time/estimated_time, 100);
	printf("Transferred %i Bytes (%i%%)\r",
		   (int)progress->transferred_bytes,
		   progress_in_percent);
}

#if RECONNECT_UNREGISTERS_OS_PORT

	/**
	 * Disconnect with the reader's port and try to reconnect within timeout
	 */
	static void reconnect_reader(brp_protocol dev, unsigned timeout,
								 progress_t * progress)
	{
		brp_time starttime, last_loop_time;
		brp_errcode errcode;
		bool dev_was_unregistered = false;
		
		errcode = brp_close(dev);
		exit_on_error(errcode, "failed to close reader connection");
		
		// wait until reader is unregistered from host OS and then wait until
		// it is rebooted and registered at host OS again again
		last_loop_time = starttime = brp_get_time();
		do
		{
			brp_time now = brp_get_time();
			exit_if(now - starttime > BASE_RECONNECT_TIMEOUT + timeout,
					"failed to reconnect within timeout");
			progress->waited_time += now - last_loop_time;
			last_loop_time = now;
			
			errcode = brp_open(dev);
			if (errcode != BRP_OK)
				dev_was_unregistered = true;
			else {
				if (dev_was_unregistered)
					errcode = brp_Sys_GetBootStatus(dev, NULL);
				else
					brp_close(dev);
			}
			
			show_progress(progress);
		}
		while (! (dev_was_unregistered && errcode == BRP_OK));
	}

#else

	/**
	 * reboots reader within timeout
	 */
	static brp_time reconnect_reader(brp_protocol dev, unsigned timeout,
									 progress_t * progress)
	{
		brp_time start;
		brp_errcode errcode;
		
		// wait until reader is unregistered from host OS and then wait until
		// it is rebooted and registered at host OS again again
		start = brp_get_time();
		do
		{
			exit_if(brp_get_time() - start > BASE_RECONNECT_TIMEOUT + timeout,
					"failed to reconnect within timeout");
			errcode = brp_Sys_GetBootStatus(dev, NULL);
			
			progress->waited_time += brp_get_time() - starttime;
			show_progress(progress);
		}
		while (errcode != BRP_OK));
	}

#endif


/**
 * Run the configuration/firmware update
 */
static void update_reader(
		brp_protocol dev, brp_buf update_blob, size_t update_blob_size)
{
	unsigned requested_data_adr, requested_data_len;
	progress_t progress = {
		.transferred_bytes=0,
		.waited_time=0,
		.estimated_time_overhead=0,
		.estimated_number_of_bytes=0
	};
	brp_errcode errcode;
	bool continue_upload;
	
	errcode = brp_Main_Bf3UploadStart(
			dev,
			&requested_data_adr,
			&requested_data_len);
	exit_on_error(errcode, "Failed to start BEC2/BF3 Upload");
	
	do
	{
		bool reconnect;
		unsigned reconnect_retry_timeout = 0;
		bool contains_estimation, contains_reconnect_retry_timeout;
		
		progress.transferred_bytes += requested_data_len;
		
		exit_if(requested_data_adr + requested_data_len > update_blob_size,
				"Update file is too small");
		errcode = brp_Main_Bf3UploadContinue(
				dev,
				requested_data_adr,
				update_blob + requested_data_adr,
				requested_data_len,
				&reconnect,
				&continue_upload,
				&requested_data_adr,
				&requested_data_len,
				&contains_estimation,
				&contains_reconnect_retry_timeout,
				&reconnect_retry_timeout,
				&progress.estimated_number_of_bytes,
				&progress.estimated_time_overhead);
		exit_on_error(errcode, "Failed to transfer BF3/BEC2 file");
		
		show_progress(&progress);
		
		if (reconnect)
			reconnect_reader(dev, reconnect_retry_timeout, &progress);
		
	}
	while (continue_upload);
	
	printf("\n");
}


void show_reader_info(brp_protocol dev)
{
	char * fws, *cfgid, *cfgname;
	brp_errcode errcode;
	
	errcode = brp_Sys_GetInfo(dev, &fws, NULL);
	exit_on_error(errcode, "Failed to retrieve firmwarestring");
	printf("FIRMWARE: %s\n", fws);
	
	errcode = brp_Sys_CfgGetId(dev, &cfgid, &cfgname, NULL);
	exit_on_error(errcode, "Failed to retrieve firmwarestring");
	printf("CONFIG: %s %s\n", cfgname, cfgid);
}


int main(int argc, char *argv[])
{
	brp_errcode errcode;
	size_t update_blob_size;
	brp_buf update_blob;
	
	exit_if(argc < 2,
			"filename of BEC2/BF3 file needs to be passed via command line");
	update_blob = load_bec2_bf3_file(argv[1], &update_blob_size);
	
	brp_protocol dev = brp_create();
	brp_set_io(dev, brp_create_usb_hid(0));
	errcode = brp_open(dev);
	exit_on_error(errcode, "failed to connect to USB/HID reader");
	
	update_reader(dev, update_blob, update_blob_size);
	
	show_reader_info(dev);
	
	free(update_blob);
	brp_destroy(dev);
	
	return EXIT_SUCCESS;
}
