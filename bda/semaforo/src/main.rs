use semaforo::ThreadPool;
use std::{
    fs,
    io::{prelude::*, BufReader},
    net::{TcpListener, TcpStream},
    path,
    rc::Rc,
    thread,
    time::Duration,
};

fn main() {
    let listener = TcpListener::bind("0.0.0.0:8080").unwrap();
    let pool = ThreadPool::new(4);
    for stream in listener.incoming() {
        let stream = stream.unwrap();

        pool.execute(|| {
            handle_connection(stream);
        });
    }
    println!("Shutting down.");
}

fn handle_connection(mut stream: TcpStream) {
    let buf_reader = BufReader::new(&mut stream);
    let request_line = buf_reader.lines().next().unwrap().unwrap();

    println!(
        "request path: '{}'",
        &request_line[4..request_line.len() - 9]
    );

    let (status_line, filename) = match &request_line[..] {
        "GET / HTTP/1.1" => {
            modify_file();
            ("HTTP/1.1 200 OK", "hello.html")
        }
        _ => ("HTTP/1.1 404 NOT FOUND", "404.html"),
    };

    let contents = fs::read_to_string(filename).unwrap();
    let length = contents.len();
    let response = format!("{status_line}\r\nContent-Length: {length}\r\n\r\n{contents}");

    stream.write_all(response.as_bytes()).unwrap();
}

fn modify_file() {
    let mut lock_existe = true;
    while lock_existe {
        lock_existe = intentar_adquirir();
        thread::sleep(std::time::Duration::from_millis(200));
    }

    let file = fs::read_to_string("hello.html").unwrap();
    println!("'{}'", file);
    let mut val: i32 = file.trim().parse().unwrap();
    val += 1;
    fs::write("hello.html", val.to_string());
    liberar_lock();
}

fn block_lock() {
    fs::write("mut.lock", "");
}

fn liberar_lock() {
    fs::remove_file("mut.lock");
}

fn intentar_adquirir() -> bool {
    if path::Path::new("mut.lock").exists() {
        true
    } else {
        block_lock();
        false
    }
}
