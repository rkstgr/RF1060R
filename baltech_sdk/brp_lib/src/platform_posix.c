#include "brp_lib/platform.h"

#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>

#ifndef O_CLOEXEC
    #define O_CLOEXEC 0
#endif


BRP_LIB brp_time brp_get_time(void)
{
	struct timespec spec;
	clock_gettime(CLOCK_MONOTONIC, &spec);
	return (brp_time) (spec.tv_sec * 1000 + spec.tv_nsec / 1000000);
}


BRP_LIB bool brp_get_random(brp_buf buf, size_t len)
{
    int fd = open("/dev/urandom", O_RDONLY | O_CLOEXEC);
    if (fd == -1) {
        fd = open("/dev/random", O_RDONLY | O_CLOEXEC);
        if (fd == -1) {
            return false;
        }
    }

    char *ptr = (char *)buf;
    size_t left = len;
    while (left > 0) {
        ssize_t bytes_read = read(fd, ptr, left);
        if (bytes_read <= 0) { // read failed
            close(fd);
            return false;
        }
        left -= bytes_read;
        ptr += bytes_read;
    }

    close(fd);
    return true;
}


BRP_LIB bool brp_get_home_dir(char * result)
{
	const char *homedir;
	struct passwd pwd, *pwd_result;
	size_t buflen;
	char * buf;
	
	homedir = getenv("HOME");
	if (homedir != NULL)
	{
		strncpy(result, homedir, PATH_MAX);
		return true;
	}
	
	buflen = sysconf(_SC_GETPW_R_SIZE_MAX);
	if (buflen == -1) buflen = 1024;
	buf = malloc(buflen);
	if (buf == NULL)
		return false;
	getpwuid_r(getuid(), &pwd, buf, buflen, &pwd_result);
	if (pwd_result != NULL)
		strncpy(result, pwd_result->pw_dir, PATH_MAX);
	free(buf);
	return pwd_result != NULL;
}


BRP_LIB bool brp_get_process_name(char * result)
{
	const char * progname;
#if defined(__APPLE__)
	progname = getprogname();
#else
	extern char * __progname;
	progname = __progname;
#endif
	if (progname == NULL)
		return false;
	else
	{
		strncpy(result, progname, PATH_MAX);
		result[PATH_MAX-1] = '\0';
		return true;
	}
}
