use std::env;
use std::path::{Path, PathBuf};

fn main() {
    let dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let lib_dir = Path::new(&dir).join("baltech_sdk");
    println!("cargo:rustc-link-search=native={}", lib_dir.display());

    let bindings = bindgen::Builder::default()
        .header("wrapper.h")
        .clang_arg(format!("-I{}", lib_dir.display()))
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
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