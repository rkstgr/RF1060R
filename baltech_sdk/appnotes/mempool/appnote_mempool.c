/* This file demonstrates how to use the memory pool (mempool) object
 * of the Baltech SDK.
 */
 
 
#include <stdio.h>
#include <baltech_api.h>


/**
 * Check if an error occurred and stop immediately if so showing an error text.
 *
 * if errcode != BRP_OK then errormessage including errcode is shown and the
 * execution of the program is stopped.
 */
static void exit_on_error(brp_errcode errcode, char *errormessage,
						  brp_protocol dev)
{
	if (errcode != BRP_OK)
	{
		char * errname = brp_map_errcode(errcode);
		if (errname == NULL)
			fprintf(stderr, "%s [brp_errcode:%08X]\n", errormessage, errcode);
		else
			fprintf(stderr, "%s [%s]\n", errormessage, errname);
		brp_destroy(dev);
		exit(EXIT_FAILURE);
	}
}


/**
 * Example of receiving complex data structures without extra memory management.
 *
 * Passes NULL to the mempool parameter of the BRP commands. This makes the
 * according API calls to rely on the "dev" objects internal memory pool.
 * Please notice that a side effect of this method is, that the memory pool
 * is freed when calling the next API function on that "dev" object.
 * This means you must not use any (non-scalar) parameters returned from
 * the previous API function after calling the next API function!
 */
void simple_mempool_usage(brp_protocol dev)
{
	brp_errcode errcode;
	char * fws;
	brp_FeatureID * features, max_featureid;
	size_t features_len, cnt;
	
	printf("\nSIMPLE MEMPOOL USAGE:\n");
	
	errcode = brp_Sys_GetFeatures(dev, &features, &features_len, &max_featureid,
							      NULL);
	exit_on_error(errcode, "failed to retrieve List of Features", dev);
	printf("  supported features: ");
	for (cnt = 0; cnt < features_len; cnt++) printf("0x%04X, ", features[cnt]);
	printf("\n");
	
	errcode = brp_Sys_GetInfo(dev, &fws, NULL);
	exit_on_error(errcode, "failed to retrieve Firmwarestring", dev);
	printf("  firmware: %s\n", fws);
	
	// "features" must not be used any more, as brp_Sys_GetInfo() has
	// overwritten the underlying buffer.
	// On how to avoid this please refer to advanced_mempool_usage().
}


/**
 * Example of receiving complex data structures with manual memory management.
 *
 * Create our own memory pool and pass it to the mempool parameter of the
 * BRP commands. This gives you much more control on the life-cycle of the
 * non-scalar returned data.
 */
void advanced_mempool_usage(brp_protocol dev)
{
	brp_errcode errcode;
	char * fws;
	brp_FeatureID * features, max_featureid;
	size_t features_len, cnt;

	printf("\nADVANCED MEMPOOL USAGE:\n");
	
	brp_mempool my_mempool = NULL;
	
	errcode = brp_Sys_GetFeatures(dev, &features, &features_len, &max_featureid,
							      &my_mempool);
	exit_on_error(errcode, "failed to retrieve List of Features", dev);
	
	errcode = brp_Sys_GetInfo(dev, &fws, &my_mempool);
	exit_on_error(errcode, "failed to retrieve Firmwarestring", dev);

	printf("  supported features: ");
	for (cnt = 0; cnt < features_len; cnt++) printf("0x%04X, ", features[cnt]);
	printf("\n");
	printf("  firmware: %s\n", fws);
	
	// this call finaly releases the underlying buffers referred by "features"
	// and "fws"
	brp_mempool_free(&my_mempool);
}


int main(int argc, char *argv[])
{
	brp_protocol dev = brp_create();
	brp_set_io(dev, brp_create_usb_hid(0));
	exit_on_error(brp_open(dev), "failed to create/connect to device", dev);
	
	simple_mempool_usage(dev);
	advanced_mempool_usage(dev);
	
	brp_destroy(dev);
	return EXIT_SUCCESS;
}
