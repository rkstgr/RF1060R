#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

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