use rf1060r::ReaderSession;

fn main() {
    let product_id = 0xf001; // Example product ID
    match ReaderSession::open() {
        Ok(session) => {
            println!("Session opened successfully!");
            // Use the session here
        }
        Err(e) => eprintln!("Failed to open session: {}", e),
    }
}