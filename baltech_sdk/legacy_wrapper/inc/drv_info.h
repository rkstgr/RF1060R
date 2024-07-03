
#if ! defined(__DRIVER_INFO__)
#define __DRIVER_INFO__

#if defined(__cplusplus)
extern "C" {
#endif

void info_get_version( int *Major, int *Minor, int *Release);

#define INFO_ERROR_DESC_MAX_LEN	80

char* info_get_error_desc( int Error, char* description );

char* info_get_status_desc( int Status, char* description );

#if defined(__cplusplus)
}
#endif

#endif