/*
    Cross-platform serial / RS232 library
    Version 0.21, 11/10/2015
    -> WIN32 implementation
    -> rs232-win.c
    
    The MIT License (MIT)

    Copyright (c) 2013-2015 Fr�d�ric Meslin, Florent Touchard
    Email: fredericmeslin@hotmail.com
    Website: www.fredslab.net
    Twitter: @marzacdev

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifdef _WIN32

#include "rs232.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*****************************************************************************/

#define TTYDEV_MAXNAME    12

struct comPortList_t
{
    char internalName[TTYDEV_MAXNAME];
    struct comPortList_t * next;
};

struct comPort_t
{
    void* handle;
};

/*****************************************************************************/

#if !defined(COM_MINDEVNAME)
    #define COM_MINDEVNAME 16384
#endif
const char * comPtn = "COM???";

/*****************************************************************************/
const char * findPattern(const char * string, const char * pattern, int * value);

/*****************************************************************************/
typedef struct _COMMTIMEOUTS {
    uint32_t ReadIntervalTimeout;
    uint32_t ReadTotalTimeoutMultiplier;
    uint32_t ReadTotalTimeoutConstant;
    uint32_t WriteTotalTimeoutMultiplier;
    uint32_t WriteTotalTimeoutConstant;
} COMMTIMEOUTS;

typedef struct _DCB {
    uint32_t DCBlength;
    uint32_t BaudRate;
    uint32_t fBinary  :1;
    uint32_t fParity  :1;
    uint32_t fOutxCtsFlow  :1;
    uint32_t fOutxDsrFlow  :1;
    uint32_t fDtrControl  :2;
    uint32_t fDsrSensitivity  :1;
    uint32_t fTXContinueOnXoff  :1;
    uint32_t fOutX  :1;
    uint32_t fInX  :1;
    uint32_t fErrorChar  :1;
    uint32_t fNull  :1;
    uint32_t fRtsControl  :2;
    uint32_t fAbortOnError  :1;
    uint32_t fDummy2  :17;
    uint16_t wReserved;
    uint16_t XonLim;
    uint16_t XoffLim;
    uint8_t  ByteSize;
    uint8_t  Parity;
    uint8_t  StopBits;
    int8_t  XonChar;
    int8_t  XoffChar;
    int8_t  ErrorChar;
    int8_t  EofChar;
    int8_t  EvtChar;
    uint16_t wReserved1;
} DCB;

/*****************************************************************************/
/** Windows system constants */
#define ERROR_INSUFFICIENT_BUFFER   122
#define INVALID_HANDLE_VALUE        ((void *) -1)
#define GENERIC_READ                0x80000000
#define GENERIC_WRITE               0x40000000
#define OPEN_EXISTING               3
#define MAX_DWORD                   0xFFFFFFFF

#define SETRTS                      3
#define CLRRTS                      4
#define SETDTR                      5
#define CLRDTR                      6

/*****************************************************************************/
/** Windows system functions */
void * __stdcall CreateFileA(const char * lpFileName, uint32_t dwDesiredAccess, uint32_t dwShareMode, void * lpSecurityAttributes, uint32_t dwCreationDisposition, uint32_t dwFlagsAndAttributes, void * hTemplateFile);
bool __stdcall WriteFile(void * hFile, const void * lpBuffer, uint32_t nNumberOfBytesToWrite, uint32_t * lpNumberOfBytesWritten, void * lpOverlapped);
bool __stdcall ReadFile(void * hFile, void * lpBuffer, uint32_t nNumberOfBytesToRead, uint32_t * lpNumberOfBytesRead, void * lpOverlapped);
bool __stdcall CloseHandle(void * hFile);

uint32_t __stdcall GetLastError(void);
void __stdcall SetLastError(uint32_t dwErrCode);

uint32_t  __stdcall QueryDosDeviceA(const char * lpDeviceName, char * lpTargetPath, uint32_t ucchMax);

bool __stdcall GetCommState(void * hFile, DCB * lpDCB);
bool __stdcall GetCommTimeouts(void * hFile, COMMTIMEOUTS * lpCommTimeouts);
bool __stdcall SetCommState(void * hFile, DCB * lpDCB);
bool __stdcall SetCommTimeouts(void * hFile, COMMTIMEOUTS * lpCommTimeouts);
bool __stdcall SetupComm(void * hFile, uint32_t dwInQueue, uint32_t dwOutQueue);
bool __stdcall EscapeCommFunction(void * hFile, uint32_t dwFunc);


#define WRITE_TIMEOUT 10


/*****************************************************************************/
int comEnumerate(comPortList * portList)
{
// Get devices information text
    int noDevices = 0;
    int port;
    size_t size = COM_MINDEVNAME;
    char * list = (char *) malloc(size);
    SetLastError(0);
    QueryDosDeviceA(NULL, list, (uint32_t) size);
    while (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
        size *= 2;
        char * nlist = realloc(list, size);
        if (!nlist) {
            free(list);
            return 0;
        }
        list = nlist;
        SetLastError(0);
        QueryDosDeviceA(NULL, list, (uint32_t) size);
    }
// Gather all COM ports
    *portList = NULL;
    const char * nlist = findPattern(list, comPtn, &port);
    while(port > 0) {
        comPortList newEntry = malloc(sizeof(struct comPortList_t));
        if (newEntry == NULL)
        {
            comFreePortList(*portList);
            return 0;
        }
        sprintf(newEntry->internalName, "\\\\.\\COM%i", port);
        newEntry->next = *portList;
        *portList = newEntry;
        noDevices++;
        
        nlist = findPattern(nlist, comPtn, &port);
    }
    free(list);
    return noDevices;
}

void comFreePortList(comPortList portList)
{
    while (portList != NULL)
    {
        comPortList delEntry = portList;
        portList = portList->next;
        free(delEntry);
    }
}

/*****************************************************************************/
const char * comGetNextPortName(comPortList * portListIter)
{
    comPortList curEntry = *portListIter;
    if (*portListIter == NULL)
        return NULL;
    *portListIter = curEntry->next;
    return curEntry->internalName + 4;  // skip "\\.\"
}

const char * comGetNextFullName(comPortList * portListIter)
{
    comPortList curEntry = *portListIter;
    if (*portListIter == NULL)
        return NULL;
    *portListIter = curEntry->next;
    return curEntry->internalName;
}

/*****************************************************************************/
comPort comOpen(const char * portName, int baudrate, int parity)
{
    DCB config;
    COMMTIMEOUTS timeouts;
    comPort newPort = malloc(sizeof(struct comPort_t));
    if (newPort == NULL)
        return NULL;
// Open COM port
    newPort->handle = CreateFileA(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (newPort->handle == INVALID_HANDLE_VALUE)
    {
        free(newPort);
        return NULL;
    }
// Prepare read / write timeouts
    SetupComm(newPort->handle, 64, 64);
    timeouts.ReadIntervalTimeout = MAX_DWORD;
    timeouts.ReadTotalTimeoutConstant = 0;
    timeouts.WriteTotalTimeoutConstant = 0;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutMultiplier = WRITE_TIMEOUT;
    SetCommTimeouts(newPort->handle, &timeouts);
// Prepare serial communication format
    GetCommState(newPort->handle, &config);
    config.BaudRate = baudrate;
    config.fBinary = 1;
    config.fParity = 1;
    config.fErrorChar = 0;
    config.fNull = 0;
    config.fAbortOnError = 0;
    config.ByteSize = 8;
    switch (parity)
    {
        case PARITY_NONE:  config.Parity = 0; break;
        case PARITY_ODD:   config.Parity = 1; break;
        case PARITY_EVEN:  config.Parity = 2; break;
        case PARITY_SPACE: config.Parity = 3; break;
        case PARITY_MARK:  config.Parity = 4; break;
    }
    config.StopBits = 0;
    config.EvtChar = '\n';
// Set the port state
    if (SetCommState(newPort->handle, &config) == 0) {
        CloseHandle(newPort->handle);
        free(newPort);
        return NULL;
    }
    return newPort;
}

void comClose(comPort port)
{
    CloseHandle(port->handle);
    free(port);
}

/*****************************************************************************/
int comWrite(comPort port, const char * buffer, size_t len)
{
    uint32_t bytes = 0;
    WriteFile(port->handle, buffer, (uint32_t) len, &bytes, NULL);
    return bytes;
}

int comRead(comPort port, char * buffer, size_t len)
{
    uint32_t bytes = 0;
    ReadFile(port->handle, buffer, (uint32_t) len, &bytes, NULL);
    return bytes;
}

int comReadBlocking(comPort port, char * buffer, size_t len, unsigned timeout)
{
    COMMTIMEOUTS timeouts;
    uint32_t initial_read_actlen = 0, rest_read_actlen = 0;

    timeouts.ReadIntervalTimeout = MAX_DWORD;
    timeouts.ReadTotalTimeoutConstant = (uint32_t) timeout;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.WriteTotalTimeoutConstant = 0;
    timeouts.WriteTotalTimeoutMultiplier = WRITE_TIMEOUT;
    SetCommTimeouts(port->handle, &timeouts);

    ReadFile(port->handle, buffer, (uint32_t) 1, &initial_read_actlen, NULL);

    if (len > 1  &&  initial_read_actlen == 1)
    {
        timeouts.ReadIntervalTimeout = 20;
        timeouts.ReadTotalTimeoutConstant = 0;
        timeouts.ReadTotalTimeoutMultiplier = 20;
        timeouts.WriteTotalTimeoutConstant = 0;
        timeouts.WriteTotalTimeoutMultiplier = WRITE_TIMEOUT;
        SetCommTimeouts(port->handle, &timeouts);
    
        ReadFile(port->handle, buffer+1, (uint32_t) len-1, &rest_read_actlen, NULL);
    }

    timeouts.ReadIntervalTimeout = MAX_DWORD;
    timeouts.ReadTotalTimeoutMultiplier = 0;
    timeouts.ReadTotalTimeoutConstant = 0;
    timeouts.WriteTotalTimeoutConstant = 0;
    timeouts.WriteTotalTimeoutMultiplier = WRITE_TIMEOUT;
    SetCommTimeouts(port->handle, &timeouts);

    return (int) (initial_read_actlen + rest_read_actlen);
}

/*****************************************************************************/
const char * findPattern(const char * string, const char * pattern, int * value)
{
    char c, n = 0;
    const char * sp = string;
    const char * pp = pattern;
// Check for the string pattern
    while (1) {
        c = *sp ++;
        if (c == '\0') {
            if (*pp == '?') break;
            if (*sp == '\0') break;
            n = 0;
            pp = pattern;
        }else{
            if (*pp == '?') {
            // Expect a digit
                if (c >= '0' && c <= '9') {
                    n = n * 10 + (c - '0');
                    if (*pp ++ == '\0') break;
                }else{
                    n = 0;
                    pp = comPtn;
                }
            }else{
            // Expect a character
                if (c == *pp) {
                    if (*pp ++ == '\0') break;
                }else{
                    n = 0;
                    pp = comPtn;
                }
            }
        }
    }
// Return the value
    * value = n;
    return sp;
}


int comSetDtr(comPort port, int state)
{
    return EscapeCommFunction(port->handle, state ? SETDTR :CLRDTR);
}


int comSetRts(comPort port, int state)
{
    return EscapeCommFunction(port->handle, state ? SETRTS :CLRRTS);
}


#endif // _WIN32
