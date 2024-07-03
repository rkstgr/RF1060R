
#if ! defined(__OPERATING_SYSTEM_WRAPPER__)
#define __OPERATING_SYSTEM_WRAPPER__

#include "compiler.h"

//if a function should work without timer
#define OSWRAP_NO_TIMEOUT      0xFFFFFFFF

#if defined(__cplusplus)
extern "C" {
#endif

dword oswrap_get_time(void);

void oswrap_sleep(dword time);

#if defined(__cplusplus)
}
#endif

#endif
