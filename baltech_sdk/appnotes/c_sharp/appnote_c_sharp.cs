/* This file demonstrates how to access a Reader via C#.
 * 
 * As currently Baltech does not provide language bindings for C#
 * the bindings for the required functions have to be declared manually.
 * 
 * Please ensure, that C# JIT's wordsize matches the wordsize of the
 * brp_lib. This means the 32bit dll has to be used on the 32bit JIT and
 * the same with 64bit. This samplecode is only for 32bit!
 */ 

using System;
using System.Text;
using System.Runtime.InteropServices;

using brp_protocol = System.IntPtr;
using brp_errcode = System.UInt32;
using brp_time = System.UInt32;
using size_t = System.UIntPtr;

namespace csharp_sample
{
    class Program
    {
        const int BRP_OK = 0x00000000;

        [DllImport("brp_lib.dll", CallingConvention=CallingConvention.Cdecl)]
        static extern brp_protocol brp_create();

        [DllImport("brp_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern brp_protocol brp_create_usb_hid(long snr);

        [DllImport("brp_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern brp_protocol brp_create_tcpip(string ipaddr);

        [DllImport("brp_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern brp_errcode brp_set_io(brp_protocol protocol, brp_protocol io_protocol);

        [DllImport("brp_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern brp_errcode brp_open(brp_protocol protocol);

        [DllImport("brp_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern brp_errcode brp_close(brp_protocol protocol);

        [DllImport("brp_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern brp_errcode brp_exec_cmd(
            brp_protocol protocol, int cmd_code, byte[] param_buf, size_t param_len,
            byte[] resp_buf, size_t max_resp_len, ref size_t resp_len, brp_time cmd_timeout);

        static void Main()
        {
            brp_protocol brpDev = brp_create();
            if (brp_set_io(brpDev, brp_create_usb_hid(0)) != BRP_OK)
                throw new Exception("Failed to create communication object");

            if (brp_open(brpDev) != BRP_OK)
                throw new Exception("Failed to open connection");

            size_t respLen = (size_t)0;
            byte[] respBuf = new byte[100];
            if (brp_exec_cmd(brpDev, 0x0004, new byte[1], (size_t)0,
                             respBuf, (size_t)respBuf.Length, ref respLen, 100)
               != BRP_OK)
                throw new Exception("Failed to execute command");
            if (respLen.ToUInt32() != 41)
                throw new Exception("Excpected Sys.GetInfo to return 41 Bytes");

            if (brp_close(brpDev) != BRP_OK)
                throw new Exception("Failed to close connection");

            Console.WriteLine("Firmwarestring: " + Encoding.ASCII.GetString(respBuf));
        }
    }
}
