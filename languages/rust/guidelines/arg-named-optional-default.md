# Named, optional and default arguments

[We Have Named Arguments at Home](https://corrode.dev/blog/named-arguments-at-home/)

## Named arguments using Newtype pattern

```rust
struct Width(pub u32);
struct Height(pub u32);

fn set_size(w: Width, h: Height) {}

set_size(Width(800), Height(600)); 
```

## Optional arguments using `Option<T>`

```rust
fn greet(name: Option<&str>) {
    let user_name = name.unwrap_or("Guest");
    println!("{user_name}");
}

greet(None);
greet(Some("Alex"));
greet(Some(&String::from("John")));
```

## Using structs

### Named arguments

```rust
struct CropOptions {
    x: u32,
    y: u32,
    width: u32,
    height: u32,
}

fn crop_image(opts: CropOptions) {}

fn main() {
    let x = 0;
    let y = 0;

    crop_image(CropOptions {
        x,
        y,
        width: 800,
        height: 600,
    });
}
```

### Optional/default arguments

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

### Required + optional/default arguments

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

## Builder pattern

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

Each “argument” is an ordinary method call:

```rust
let mut request = Request::builder(url);

if let Some(timeout) = config.timeout {
    request = request.timeout(timeout);
}

let request = request.build()?;
```

Rust crates like [bon](https://bon-rs.com/) allow you to generate builders automatically using macros:

```rust
#[bon::builder]
fn greet(name: &str, age: u32, language: Option<&str>) {
    let lang = language.unwrap_or("English");
    println!("Hello, {} (age {}), speaks {}", name, age, lang);
}

fn main() {
    greet()
        .name("Alex")
        .age(30)
        // language can be omitted because it's an Option
        .call(); 
}
```

## Flexible argument types

```rust
enum Redirect {
    Url(Url),
    Post(Post),
    Action {
        action: String,
        id: u64,
    },
}

fn redirect_to(target: Redirect) {}

fn main() {
    redirect_to(Redirect::Url(url));
    
    redirect_to(Redirect::Post(post));
    
    redirect_to(Redirect::Action {
        action: "show".into(),
        id: 5,
    });
}
```
