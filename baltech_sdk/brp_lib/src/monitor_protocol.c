#include "brp_lib/monitor_protocol.h"
#include "brp_lib/brp_protocol.h"
#include "brp_lib/platform.h"
#include "brp_lib/frames.h"
#include "brp_lib/names.h"
#include "stdio.h"
#include "time.h"

#if defined(MOCK_TIME)
	time_t mockedtime(time_t *);
	#define time mockedtime
#endif

// ensure crossplatform compatibility
#if defined(WIN32)
	#if _MSC_VER >= 1900
		#define timezone _timezone
		#define tzset _tzset
	#endif
	#define localtime_r(timer, buf) localtime_s(buf, timer)
#endif

typedef long long abs_time;

typedef struct monitor_protocol_t
{
	struct brp_protocol_t p;
	FILE * log_file;
	abs_time session_start_timestamp;
	abs_time last_cmd_timestamp;
	abs_time last_time_retrieval; // last time a timestamp was retrieved
	unsigned log_entry_id;
	abs_time base_time;           // ms since 1970 to where brp_get_time() was 0
} * monitor_protocol;


static abs_time get_abs_time(monitor_protocol protocol)
{
	abs_time now = protocol->base_time + brp_get_time();
	if (now < protocol->last_time_retrieval)
	{
		// rollover of 32bit timer
		protocol->base_time += 0x100000000LL;
		now += 0x100000000LL;
	}
	protocol->last_time_retrieval = now;
	return now;
}


static bool copy_frame(brp_frame dst_frame, brp_frame src_frame)
{
	brp_frame_reader src_frame_rdr;
	brp_frame_read_start(&src_frame_rdr, src_frame);
	brp_frame_read_frm_rest(&src_frame_rdr, dst_frame);
	return brp_frame_read_eof(&src_frame_rdr);
}


static void remove_slash(char * str)
{
	char *src = str, *dst = str;
	while (*src != '\0') {
		if (*src == '/' || *src == '\\')
			dst = str;
		else
		{
			*dst = *src;
			dst++;
		}
		src++;
	}
	*dst = '\0';
}


static bool get_log_path(brp_protocol protocol, time_t date, char * log_path)
{
	char home_dir[PATH_MAX];
	char log_filename[PATH_MAX];
	char * intf_name;
	char intf_name_cpy[11];  // length of "YYYY-MM-DD\0"
	struct brp_frame_t instance_id;
	struct tm datetime_struct;
	char datetime_str[11];  // length of "YYYY-MM-DD\0"
	
	if (! brp_get_home_dir(home_dir))
		return false;
	
	localtime_r(&date, &datetime_struct);
	strftime(datetime_str, sizeof(datetime_str), "%Y-%m-%d", &datetime_struct);
	
	brp_frame_init(&instance_id);
	if (brp_get_io_id(protocol, &intf_name, &instance_id) != BRP_OK)
		return false;
	
	strcpy(intf_name_cpy, intf_name);
	remove_slash(intf_name_cpy);
	remove_slash((char*)BRP_FRAME_PTR(&instance_id));
	snprintf(log_filename, PATH_MAX, "%s-%s.html",
			 intf_name_cpy, BRP_FRAME_PTR(&instance_id));
	if (PATH_MAX < snprintf(log_path, PATH_MAX,
			"%s/" BRP_LOG_DIR_PREFIX "%s/%s",
			home_dir, datetime_str, log_filename))
		return false;
	
	brp_frame_deinit(&instance_id);
	return true;
}


static void log_file_header(monitor_protocol protocol)
{
	struct tm dt;
	time_t today;
	char * intf_name;
	struct brp_frame_t instance_id;

	brp_frame_init(&instance_id);
	if (brp_get_io_id((brp_protocol)protocol,&intf_name,&instance_id) != BRP_OK)
	{
		brp_frame_write_int8(&instance_id, '?');
		brp_frame_write_int8(&instance_id, '\0');
	}
	time(&today);
	localtime_r(&today, &dt);

	fprintf(protocol->log_file,
			"<head>\n"
			"<title>%s on %04i-%02i-%02i</title>\n"
			"<style>\n"
			"body {"
			"	font-family: monospace;"
			"	font-size: 17px;"
			"	margin: 0;"
			"}\n"
			"p {"
			"	color: darkgray;"
			"	margin: 1px;"
			"	border: 0.3em solid white;"
			"	padding-left: 14em;"
			"	display: flow-root;"
			"}\n"
			".open, .close {"
			"	background: lightblue;"
			"	border-color: lightblue;"
			"	color: black;"
			"}"
			".open {"
			"	margin-top: 3em;"
			"}\n"
			".open a:hover, .close a:hover {"
			"	background: #9FC6D4;"
			"}\n"
			".send {"
			"	background: #E0E0E0;"
			"	border-color: #E0E0E0;"
			"}\n"
			".send, .recv {"
			"	color: black;"
			"}\n"
			".break {"
			"	background: mistyrose;"
			"	border-color: mistyrose;"
			"}\n"
			".break a:hover {"
			"	background: #f1d6d3;"
			"}\n"
			".recv a:hover, .poll a:hover {"
			"	background: #efefef;"
			"}\n"
			":target {"
			"	background: yellow;"
			"	border-color: yellow;"
			"}\n"
			":target a:hover, :target a:hover {"
			"	background: #E0E000"
			"}\n"
			"a:first-child {"
			"	position: absolute;"
			"	left: 5px;"
			"}\n"
			"a:first-child span {"
			"	color: grey;"
			"	margin-left: 1em;"
			"}\n"
			".payload {"
			"	margin-left: 2em;"
			"}\n"
			".delay {"
			"	color: black;"
			"	font-weight: bold;"
			"}\n"
			".to {"
			"	float: right;"
			"	color: grey;"
			"}\n"
			".ok {"
			"	color: #00C000;"
			"	font-weight: bold;"
			"	margin-left: 0;"
			"}\n"
			"a {"
			"	text-decoration: unset;"
			"	color: black;"
			"}\n"
			"a:hover {"
			"	background: #D0D0D0;"
			"}\n"
			".err {"
			"	font-weight: bold;"
			"	color: red;"
			"}\n"
			".cmd {"
			"	font-weight: bold;"
			"}\n"
			".mode {"
			"	background: burlywood;"
			"	border-color: burlywood;"
			"	border-style: solid;"
			"	border-width: 3px 0.8em;"
			"	font-weight: bold;"
			"	border-radius: 4px;"
			"	margin-left: 0.8em;"
			"	margin-right: 0.8em;"
			"}\n"
			"#livemode-activate {"
			"    margin: 10px 0px;"
			"    padding: 10px;"
			"    width: 100%%;"
			"    font-weight: bold;"
			"}\n"
			"#livemode-state {"
			"    position: fixed;"
			"    right: 3px;"
			"    bottom: 3px;"
			"    background: lightgreen;"
			"    padding: 6px;"
			"    animation: blinker 1s linear infinite;"
			"}\n"
			".invisible {"
			"    visibility: hidden;"
			"}\n"
			"@keyframes blinker {"
			"  50%% {opacity: 0;}"
			"}\n"
			"</style>\n"
			"<script type=\"text/javascript\">\n"
			"//<![CDATA[\n"
			"    livemodeButton = null;\n"
			"    livemodeState = null;\n"
			"    LIVEMODE_KEY = 'baltech_sdk_monitor_livemode';\n"
			"    window.onload = function(){\n"
			"        livemodeButton = document.getElementById('livemode-activate');\n"
			"        livemodeState = document.getElementById('livemode-state');\n"
			"        livemodeButton.parentNode.appendChild(livemodeButton);\n"
			"        window.scrollTo(0,document.body.scrollHeight);\n"
			"        if (location.origin !== 'file://' && location.origin !== 'null' &&\n"
			"            location.origin != null)\n"
			"            livemodeButton.parentNode.removeChild(livemodeButton);\n"
			"        else {\n"
			"            livemodeButton.parentNode.appendChild(livemodeButton);\n"
			"            window.scrollTo(0,document.body.scrollHeight);\n"
			"            if (isLivemode())\n"
			"                enableLivemode();\n"
			"            else\n"
			"                disableLivemode();\n"
			"        }\n"
			"    };\n"
			"    function enableLivemode() {\n"
			"        livemodeButton.classList.add('invisible');\n"
			"        livemodeState.classList.remove('invisible');\n"
			"        sessionStorage.setItem(LIVEMODE_KEY, true);\n"
			"        window.setTimeout(reload, 1000);\n"
			"        if (location.hash !== '')\n"
			"            location.href = location.href.split('#')[0];\n"
			"    }\n"
			"    function disableLivemode() {\n"
			"        livemodeButton.classList.remove('invisible');\n"
			"        livemodeState.classList.add('invisible');\n"
			"        sessionStorage.setItem(LIVEMODE_KEY, false);\n"
			"    }\n"
			"    function isLivemode() {\n"
			"        return sessionStorage.getItem(LIVEMODE_KEY) && location.hash === '';\n"
			"    }\n"
			"    function reload(){\n"
			"        if (isLivemode() && isAtBottom())\n"
			"            location.replace(location.href.split('#')[0]);\n"
			"        else\n"
			"            disableLivemode();\n"
			"    }\n"
			"    function isAtBottom(){\n"
			"        var d = document;\n"
			"        var docheight = Math.max(\n"
			"            d.body.scrollHeight, d.documentElement.scrollHeight,\n"
			"            d.body.offsetHeight, d.documentElement.offsetHeight,\n"
			"            d.body.clientHeight, d.documentElement.clientHeight);\n"
			"        var winheight =\n"
			"            window.innerHeight || (d.documentElement ||d.body).clientHeight;\n"
			"        var scrolltop = window.pageYOffset ||\n"
			"            (d.documentElement || d.body.parentNode || d.body).scrollTop;\n"
			"        return docheight - winheight - scrolltop < 20;\n"
			"    }\n"
			"//]]>\n"
			"</script>\n"
			"</head>\n"
			"<div id=\"livemode-state\" class=\"invisible\">Live View</div>\n"
			"<button id=\"livemode-activate\" class=\"invisible\" onclick=\"enableLivemode()\">Activate Live View</button>\n",
			BRP_FRAME_PTR(&instance_id),
			dt.tm_year+1900, dt.tm_mon+1, dt.tm_mday);

	fprintf(protocol->log_file,
			"<h1>Monitored Data at %s on %04i-%02i-%02i</h1>",
			BRP_FRAME_PTR(&instance_id),
			dt.tm_year+1900, dt.tm_mon+1, dt.tm_mday);
}


static void log_entry_start(monitor_protocol protocol,
		char * action, abs_time now)
{
	FILE * log_file = protocol->log_file;
	fprintf(log_file, "<p class=\"%s\" id=\"_%x\"><a href=\"#_%x\">", action,
			protocol->log_entry_id, protocol->log_entry_id);
	protocol->log_entry_id++;
	if (protocol->session_start_timestamp == 0)
		fprintf(log_file, "(new)");
	else
	{
		abs_time rel_time;
		rel_time = now - protocol->session_start_timestamp;
		fprintf(log_file, "%1lld.%03llds", rel_time / 1000, rel_time % 1000);
		rel_time = now - protocol->last_cmd_timestamp;
		fprintf(log_file, "<span>%1lld.%03llds</span>",
				rel_time / 1000, rel_time % 1000);
	}
	fprintf(log_file, "</a>");
}


static void log_errcode(monitor_protocol protocol, brp_errcode errcode)
{
	if (errcode != BRP_OK)
	{
		char * errname = brp_map_errcode(errcode);
		if (errname == NULL)
			fprintf(protocol->log_file,
					"<span class=\"err\">Errcode:0x%08X</span>", errcode);
		else
		{
			char *errurl = brp_map_errcode_to_docurl(errcode);
			// omit prefix "BRP_ERR_" if available
			if (strncmp(errname, "BRP_ERR_", 8) == 0)
				errname += 8;
			if (errurl == NULL)
				fprintf(protocol->log_file,
						"<a class=\"err\" title=\"Errcode:0x%08X\">%s</a>",
						errcode, errname);
			else
			{
				fprintf(protocol->log_file,
						"<a class=\"err\" title=\"Errcode:0x%08X\" "
						    "href=\"%s\">%s</a>",
						errcode, errurl, errname);
			}
		}
	}
}


static void log_frame(monitor_protocol protocol, brp_frame_reader * rdr)
{
	if (!brp_frame_read_eof(rdr) && !brp_frame_read_err(rdr))
	{
		fprintf(protocol->log_file, "%02X", brp_frame_read_int8(rdr));
		while (!brp_frame_read_eof(rdr) && !brp_frame_read_err(rdr))
			fprintf(protocol->log_file, " %02X", brp_frame_read_int8(rdr));
	}
}


static void log_entry_finish(monitor_protocol protocol)
{
	fprintf(protocol->log_file, "</p>\n");
	fflush(protocol->log_file);
}


void log_send_frame(monitor_protocol protocol, unsigned int mode,
		unsigned int cmd_code, brp_errcode errcode, unsigned int timeout,
		brp_frame_reader *rdr)
{
	// log command code
	char * cmd_name = brp_map_cmdcode(cmd_code);
	if (cmd_name == NULL)
		fprintf(protocol->log_file,
				"<span class=\"cmd\">Command Code: 0x%04X</span>", cmd_code);
	else
	{
		char * cmd_docurl = brp_map_cmdcode_to_docurl(cmd_code);
		if (cmd_docurl == NULL)
			fprintf(protocol->log_file,
					"<a class=\"cmd\" title=\"Command Code: %04X\">%s</a>",
					cmd_code, cmd_name);
		else
			fprintf(protocol->log_file,
					"<a class=\"cmd\" title=\"Command Code: 0x%04X\" "
					    "href=\"%s\">%s</a>", cmd_code, cmd_docurl, cmd_name);
	}
	
	// log mode (if available)
	if (mode != BRP_MODE_STD)
	{
		char * mode_str;
		if (mode == BRP_MODE_CONTINUOUS) mode_str = "Continuous";
		else if (mode == BRP_MODE_REPEAT) mode_str = "Repeat";
		else mode_str = "Invalid";
		fprintf(protocol->log_file,
				"<span class=\"mode\">%s Mode</span>", mode_str);
	}
	
	// log payload (if available)
	if (! brp_frame_read_eof(rdr))
	{
		fprintf(protocol->log_file, "<span class=\"payload\">&lt;");
		log_frame(protocol, rdr);
		fprintf(protocol->log_file, "&gt;</span>");
	}
	
	// log errcode (if available)
	if (errcode != BRP_OK)
		log_errcode(protocol, errcode);
	
	// log command timeout
	if (timeout != BRP_INFINITE)
		fprintf(protocol->log_file,
				"<span class=\"to\">(Cmd Timeout: %d.%03ds)</span>",
				timeout / 1000, timeout % 1000);
}


static unsigned to_day(time_t time)
{
	return (unsigned) (time - timezone) / 86400;
}


static bool ensure_log_opened(monitor_protocol protocol, abs_time now)
{
	unsigned today = to_day(now / 1000);
	unsigned day_of_last_cmd = to_day(protocol->last_cmd_timestamp / 1000);
	if (today != day_of_last_cmd || protocol->log_file == NULL)
	{
		char log_path[PATH_MAX];
		time_t now_in_realtime;
		
		if (protocol->log_file != NULL)
		{
			fclose(protocol->log_file);
			protocol->log_file = NULL;
		}
		
		now_in_realtime = now / 1000;
		if (get_log_path(protocol->p.base_protocol, now_in_realtime, log_path))
		{
			protocol->log_file = fopen(log_path, "a+t");
			if (protocol->log_file != NULL)
			{
				long int file_size;
				fseek(protocol->log_file, 0, SEEK_END);
				file_size = ftell(protocol->log_file);
				if (file_size == 0)
				{
					log_file_header(protocol);
					protocol->log_entry_id = 1;
				}
				else
					protocol->log_entry_id = (unsigned) file_size;
			}
		}
	}

	return protocol->log_file != NULL;
}


static brp_errcode open(monitor_protocol protocol)
{
	abs_time now = get_abs_time(protocol);

	if (ensure_log_opened(protocol, now))
	{
		char proc_name[PATH_MAX];
		time_t now_in_realtime;
		struct tm now_struct;
		char now_str[9];

		if (! brp_get_process_name(proc_name))
			strcpy(proc_name, "?");
		
		now_in_realtime = now / 1000;
		localtime_r(&now_in_realtime, &now_struct);
		strftime(now_str, sizeof(now_str), "%H:%M:%S", &now_struct);
		
		log_entry_start(protocol, "open", now);
		fprintf(protocol->log_file,
				"Connection opened by %s (%s.%03i)",
                  					proc_name, now_str, (int)(now % 1000) );
		log_entry_finish(protocol);
	}
	
	protocol->session_start_timestamp = now;
	protocol->last_cmd_timestamp = now;
	return BRP_OK;
}


static brp_errcode close(monitor_protocol protocol)
{
	abs_time now = get_abs_time(protocol);
	if (ensure_log_opened(protocol, now))
	{
		log_entry_start(protocol, "close", now);
		fprintf(protocol->log_file, "Connection closed");
		log_entry_finish(protocol);
		fclose(protocol->log_file);
		protocol->log_file = NULL;
	}
	protocol->session_start_timestamp = now;
	protocol->last_cmd_timestamp = now;
	return BRP_OK;
}


static brp_errcode send_frame(monitor_protocol protocol)
{
	brp_errcode errcode;
	abs_time now;
	unsigned mode, cmd_code, timeout;
	brp_frame_reader rdr;
	
	if (protocol->p.base_protocol == NULL)
		return BRP_ERR_NOT_IMPLEMENTED;
	if(!copy_frame(&protocol->p.base_protocol->send_frame,
			&protocol->p.send_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	
	errcode = brp_send_frame(protocol->p.base_protocol);
	now = get_abs_time(protocol);
	
	brp_frame_read_start(&rdr, &protocol->p.send_frame);
	mode = brp_frame_read_int8(&rdr);
	cmd_code = brp_frame_read_int16(&rdr);
	timeout = brp_frame_read_int32(&rdr);

	if (ensure_log_opened(protocol, now))
	{
		if (brp_frame_read_err(&rdr))
		{
			log_entry_start(protocol, "send", now);
			fprintf(protocol->log_file, "Invalid Frame: ");
			brp_frame_read_start(&rdr, &protocol->p.send_frame);
			log_frame(protocol, &rdr);
			log_errcode(protocol, errcode);
		}
		else if (mode == BRP_MODE_BREAK)
		{
			log_entry_start(protocol, "break", now);
			fprintf(protocol->log_file, "Break Continuous/Repeat Mode");
		}
		else
		{
			log_entry_start(protocol, "send", now);
			log_send_frame(protocol, mode, cmd_code, errcode, timeout, &rdr);
			
		}
		log_entry_finish(protocol);
		
		if (mode != BRP_MODE_BREAK)
			protocol->last_cmd_timestamp = now;
	}
	
	return errcode;
}


static brp_errcode recv_any_frame(monitor_protocol protocol, brp_time timeout)
{
	brp_errcode errcode;
	abs_time now;
	
	errcode = brp_recv_any_frame(protocol->p.base_protocol, timeout);
	now = get_abs_time(protocol);
	if (! copy_frame(&protocol->p.recv_frame,
			&protocol->p.base_protocol->recv_frame))
		return BRP_ERR_OUT_OF_MEMORY;
	
	if (ensure_log_opened(protocol, now))
	{
		log_entry_start(protocol, "recv", now);
		
		if (errcode == BRP_OK)
			fprintf(protocol->log_file, "<span class=\"ok\">OK</span>");
		else
			log_errcode(protocol, errcode);
		
		if (BRP_FRAME_SIZE(&protocol->p.recv_frame) > 0)
		{
			brp_frame_reader rdr;
			fprintf(protocol->log_file, "<span class=\"payload\">&lt;");
			brp_frame_read_start(&rdr, &protocol->p.recv_frame);
			log_frame(protocol, &rdr);
			fprintf(protocol->log_file, "&gt;</span>");
		}
		
		if (timeout != BRP_INFINITE)
			fprintf(protocol->log_file,
					"<span class=\"to\">(Poll Timeout: %ld.%03lds)</span>",
					timeout / 1000, timeout % 1000);
		
		log_entry_finish(protocol);
	}
	
	return errcode;
}


brp_protocol brp_create_monitor(void)
{
	tzset();
	monitor_protocol protocol = malloc(sizeof(struct monitor_protocol_t));
	memset(protocol, 0, sizeof(struct monitor_protocol_t));
	brp_frame_init(&protocol->p.recv_frame);
	brp_frame_init(&protocol->p.send_frame);
	protocol->p.protocol_id = BRP_PROTID_MONITOR;
	protocol->p.cb_open = (brp_cb_generic_t) open;
	protocol->p.cb_send_frame = (brp_cb_generic_t) send_frame;
	protocol->p.cb_recv_any_frame = (brp_cb_recv_any_frame_t) recv_any_frame;
	protocol->p.cb_close = (brp_cb_generic_t) close;
	protocol->p.cb_destroy = (brp_cb_generic_t) brp_protocol_free;
	protocol->session_start_timestamp = 0;
	protocol->last_cmd_timestamp = 0;
	protocol->base_time = (time(NULL) * 1000LL) - brp_get_time();
	protocol->last_time_retrieval = 0;
	return (brp_protocol) protocol;
}
