/**
 * @file
 * Defines generic, platform specific functions which are required for
 * the SDK internally.
 *
 * @internal
 *
 * @defgroup brp_lib BRP Communication Library
 * @{
 */

#ifndef __PLATFORM_H__
#define __PLATFORM_H__



#include "common.h"


#ifdef _WIN32
	#if ! defined(PATH_MAX)
		#define PATH_MAX    _MAX_PATH
	#endif
#else
	#include <limits.h>
#endif


/**
 * Retrieves a monotonic timer since powerup
 *
 * @return time in ms
 */
BRP_LIB brp_time brp_get_time(void);



/**
 * Retrieve random data and store it into a buffer
 */
BRP_LIB bool brp_get_random
(
	brp_buf buf,   ///< buffer to store random data into
	size_t len     ///< length of @em buf
);


/**
 * Retrieves the HOME directory of the current user.
 *
 * @return true on success.
 */
BRP_LIB bool brp_get_home_dir
(
	char * result    ///< pointer to buffer where directory shall be stored.
	                 ///  Must be prepared to store PATH_MAX bytes.
	                 ///  Is undefined if return value is false.
);


/**
 * Retrieves the (file-)name of the current process.
 *
 * @return true on success
 */
BRP_LIB bool brp_get_process_name
(
	char * result    ///< pointer to buffer where processname shall be stored.
	                 ///  Must be prepared to store PATH_MAX bytes.
	                 ///  Is undefined if return value is false.
);


#endif

/** @} */ // end of defgroup brp_lib
