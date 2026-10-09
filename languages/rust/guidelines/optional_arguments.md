# Optional arguments

In Rust, there is no built-in support for optional arguments in function signatures like you would find in Python, C++, or JavaScript. Every function requires a fixed number of arguments of specified types.
However, you can easily achieve this functionality using common Rust idioms. Here are the 4 main ways to handle this.

## 1. Using Option<T> (Base Approach)
To make an argument optional, wrap its type in an `Option<T>`. Callers must explicitly pass `Some(value)` or `None`. Inside the function, you provide a default value using `.unwrap_or()`.

```rust
fn greet(name: Option<&str>) {
    // If no name is provided, default to "Guest"
    let user_name = name.unwrap_or("Guest");
    println!("Hello, {}!", user_name);
}

fn main() {
    greet(Some("Alex")); // Passing a value
    greet(None);         // Simulating an omitted argument
}
```

## 2. Using Into<Option<T>> (Cleaner Function Calls)
To avoid writing `Some(...)` every time you call the function, you can use generics and the `Into` trait. Rust automatically implements `Into<Option<T>>` for any type `T`.

```rust
fn greet<S: Into<Option<&'static str>>>(name: S) {
    let user_name = name.into().unwrap_or("Guest");
    println!("Hello, {}!", user_name);
}

fn main() {
    greet("Alex"); // Pass directly as &str, converts to Some automatically
    greet(None);   // You can still pass None explicitly
}
```

## 3. Using Structs and the Default Trait (For Multiple Arguments)
When a function accepts many parameters and most should have default values, it is idiomatic to group them into a configuration struct that implements the `Default` trait. You can then use the struct update syntax (`..`).

```rust
struct Config {
    port: u16,
    timeout: u64,
}

impl Default for Config {
    fn default() -> Self {
        Config {
            port: 8080,
            timeout: 30,
        }
    }
}

fn connect(host: &str, config: Config) {
    println!("Connecting to {}:{} (timeout: {}s)", host, config.port, config.timeout);
}

fn main() {
    connect("localhost", Config::default());

    connect("google.com", Config {
        port: 443,
        ..Config::default()
    });
}
```

```rust
struct Config {
    host: String,  // required
    port: u16,     // optional
    timeout: u64,  // optional
}

impl Config {
    fn new(host: &str) -> Self {
        Config {
            host: host.to_string(),
            port: 8080, // default
            timeout: 30, // default
        }
    }
}

fn connect(config: Config) {
    println!("Connecting to {}:{} (timeout: {}s)", config.host, config.port, config.timeout);
}

fn main() {
    let config1 = Config::new("localhost");
    connect(config1);

    let config2 = Config {
        port: 443,
        ..Config::new("127.0.0.1")
    };
    connect(config2);
}
```

## 4. The Builder Pattern
For complex object initialization or functions with a large number of optional settings, the Builder Pattern is the most flexible and scalable solution in Rust.

```rust
struct Server {
    host: String,
    port: u16,
}

struct ServerBuilder {
    host: String,
    port: u16,
}

impl ServerBuilder {
    fn new() -> Self {
        ServerBuilder {
            host: String::from("127.0.0.1"), // default
            port: 80,                        // default
        }
    }

    fn host(mut self, host: &str) -> Self {
        self.host = host.to_string();
        self
    }

    fn port(mut self, port: u16) -> Self {
        self.port = port;
        self
    }

    fn build(self) -> Server {
        Server { host: self.host, port: self.port }
    }
}

fn main() {
    // Configure only what you need
    let server = ServerBuilder::new()
        .port(3000)
        .build();
    
    println!("Server running on {}:{}", server.host, server.port);
}
```
