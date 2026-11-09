# Optional arguments

In Rust, there is no built-in support for optional arguments in function signatures like you would find in Python, C++, or JavaScript. Every function requires a fixed number of arguments of specified types.
However, you can easily achieve this functionality using common Rust idioms. Here are the 4 main ways to handle this.

## 3. Using structs (for multiple arguments)
Pass required parameters directly into the function signature, while keeping the optional ones grouped inside a config struct.

```rust
struct Config {
    port: u16,     // Optional
    timeout: u64,  // Optional
}

impl Default for Config {
    fn default() -> Self {
        Config {
            port: 8080,   // Default value
            timeout: 30,  // Default value
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
If you prefer passing a single config object into your function, you can enforce required fields by passing them as arguments to a `new()` constructor function. Optional fields are assigned defaults inside this constructor.

```rust
struct Config {
    host: String,  // Required
    port: u16,     // Optional
    timeout: u64,  // Optional
}

impl Config {
    fn new(host: &str) -> Self {
        Config {
            host: host.to_string(),
            port: 8080,   // Default value
            timeout: 30,  // Default value
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

## 4. The Builder pattern
For complex object initialization or functions with a large number of optional settings, the Builder Pattern is the most flexible and scalable solution in Rust.

```rust
struct Server {
    host: String,  // Required
    port: u16,     // Optional
}

struct ServerBuilder {
    host: String,  // Required
    port: u16,     // Optional
}

impl ServerBuilder {
    fn new(host: &str) -> Self {
        ServerBuilder {
            host: host.to_string(),
            port: 80,  // Default value
        }
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
    let server1 = ServerBuilder::new("127.0.0.1").build();

    let server2 = ServerBuilder::new("localhost")
        .port(3000)
        .build();
}
```
