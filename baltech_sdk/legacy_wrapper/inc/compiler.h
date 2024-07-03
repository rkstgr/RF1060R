
#if ! defined(__COMPILER__)
#define __COMPILER__

#if defined(__cplusplus)
extern "C" {
#endif

typedef unsigned char byte;    //8bit
typedef unsigned short word;   //16bit
typedef unsigned int dword;   //32bit

#if (__STDC_VERSION__ >= 199901L)
	#include <stdbool.h>
#else
	#define false   0
	#define true    1
	#define bool    unsigned char
#endif


#if ! defined(FALSE)
#define FALSE  0
#endif

#if ! defined(TRUE)
#define TRUE   (!FALSE)
#endif

#if defined(__cplusplus)
}
#endif

#endif