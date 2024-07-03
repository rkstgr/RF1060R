use rf1060r::ReaderSession;

fn main() {
    let session = ReaderSession::open().expect("Failed to create session");
    println!("Session created");
    // let info = session.get_info().expect("Failed to get info");
    // println!("Firmware: {}", info);
}