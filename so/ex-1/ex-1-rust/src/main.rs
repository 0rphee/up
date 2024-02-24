use std::sync::{Arc, Mutex};
use std::thread;
use std::time;

fn main() {
    println!("Inicio, main thread!");

    let val = Arc::new(Mutex::new(1));
    let first = Arc::clone(&val);

    thread::spawn(move || loop {
        let mut v = first.lock().unwrap();
        *v += 1;
        println!("Modificado: {}", v);
        drop(v);
        thread::sleep(time::Duration::from_millis(100));
    });
    loop {
        let a = val.lock().unwrap();

        println!("Lectura: {}", *a);
        if *a >= 100 {
            break;
        }
        drop(a);
        thread::sleep(time::Duration::from_millis(100));
    }
}
