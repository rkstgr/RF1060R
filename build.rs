use std::env;
use std::path::{Path, PathBuf};
use std::process::Command;

fn main() {
    // Get the path to the project's root directory
    let dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let sdk_dir = Path::new(&dir).join("baltech_sdk");
    let build_dir = sdk_dir.join("binaries/linux64");

    // Run CMake to generate build files
    let cmake_status = Command::new("cmake")
        .current_dir(&sdk_dir)
        .arg("-DCMAKE_BUILD_TYPE=Release")
        .status()
        .expect("Failed to run CMake");
    assert!(cmake_status.success(), "CMake failed");

    // Build the SDK libraries with Release configuration
    let build_status = Command::new("cmake")
        .current_dir(&sdk_dir)
        .arg("--build")
        .arg(".")
        .arg("--config")
        .arg("Release")
        .status()
        .expect("Failed to build the SDK");
    assert!(build_status.success(), "Build failed");

    // Add the search path for the shared library
    println!("cargo:rustc-link-search=native={}", build_dir.display());
    println!("cargo:rustc-link-search=native={}", sdk_dir.display());
    println!("cargo:rustc-link-search=native={}", sdk_dir.join("binaries/linux64").display());

    // Link the necessary shared libraries
    println!("cargo:rustc-link-lib=dylib=BrpDriver");
    println!("cargo:rustc-link-lib=dylib=brp_lib");

    // Specify additional include paths for bindgen
    let bindings = bindgen::Builder::default()
        .header("wrapper.h")
        .clang_arg(format!("-I{}", sdk_dir.display()))
        .blocklist_var("IPPORT_.*")
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files change.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
