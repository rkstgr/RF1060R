#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

use std::ptr;
use std::ffi::c_void;
use std::os::raw::{c_char, c_int, c_uint};
use std::error::Error;
use std::fmt;

#[derive(Debug)]
pub enum ReaderError {
    Busy,
    GeneralIo,
    BufferOverflow,
    NoMoreHandles,
    InsufficientMem,
    Unknown(c_int),
}

impl fmt::Display for ReaderError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            ReaderError::Busy => write!(f, "Reader is busy"),
            ReaderError::GeneralIo => write!(f, "General I/O error"),
            ReaderError::BufferOverflow => write!(f, "Buffer overflow"),
            ReaderError::NoMoreHandles => write!(f, "No more handles available"),
            ReaderError::InsufficientMem => write!(f, "Insufficient memory"),
            ReaderError::Unknown(code) => write!(f, "Unknown error code: {}", code),
        }
    }
}

impl Error for ReaderError {}

pub struct ReaderSession {
    handle: *mut brp_protocol_t
}

impl ReaderSession {
    // Create a new ReaderSession
    pub fn open() -> Result<Self,ReaderError> {
        unsafe {
            let brp_protocol = brp_create_usb_hid(0);
            println!("brp_create_usb_hid: {:?}", brp_protocol);
            
            return Ok(ReaderSession{
                handle: brp_protocol
            });
        }
        
    }

    // Other methods to interact with the reader can be added here
}

impl Drop for ReaderSession {
    fn drop(&mut self) {
        unsafe {
            brp_close(self.handle);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_brp_get_driver_version() {
        unsafe {
            let version = brp_get_driver_version();
            let version_str = std::ffi::CStr::from_ptr(version).to_str().unwrap();
            assert_eq!(version_str, "3.18.00");
        }
    }
}