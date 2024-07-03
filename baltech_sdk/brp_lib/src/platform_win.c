#include "brp_lib/platform.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wincrypt.h>
#include <shlobj.h>


BRP_LIB brp_time brp_get_time(void)
{
	return (brp_time) GetTickCount();
}


BRP_LIB bool brp_get_random(brp_buf buf, size_t len)
{
    HCRYPTPROV prov;
    if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL,
    		CRYPT_VERIFYCONTEXT)) {
        return false;
    }

    CryptGenRandom(prov, (DWORD) len, (BYTE *)buf);
    CryptReleaseContext(prov, 0);
	return true;
}


BRP_LIB bool brp_get_home_dir(char * result)
{
	return SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0,result));
}


BRP_LIB bool brp_get_process_name(char * result)
{
	return ERROR_INSUFFICIENT_BUFFER !=
			GetModuleFileNameA(NULL, result, MAX_PATH);
}
