# Named, optional and default arguments

[We Have Named Arguments at Home](https://corrode.dev/blog/named-arguments-at-home/)

## Using `Option<T>`

### Optional arguments

```rust
fn connect(host: &str, port: u16, timeout_ms: Option<u64>) {}

connect("google.com", 443, None);
connect("google.com", 443, Some(200));
```

### Default arguments

```rust
fn greet(name: Option<&str>) {
    let user_name = name.unwrap_or("Guest");
    println!("Hello, {user_name}!");
}

greet(None);
greet(Some("Alex"));
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

fn crop_image(crop_options: CropOptions) {}

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

### Optional arguments

```rust
struct RequestOptions {
    timeout: Option<Duration>,
    proxy: Option<Proxy>,
    redirect: Option<RedirectPolicy>,
}

fn main() {
    let options = RequestOptions {
        timeout: some_timeout,
        proxy: detect_proxy(),
        redirect: None,
    };
    
    request(url, options);
}
```

### Default arguments

```rust
struct Config {
    port: u16,
    timeout: u64,
}

impl Default for Config {
    fn default() -> Self {
        Config {
            port: 8080,   // Default value
            timeout: 30,  // Default value
        }
    }
}

fn connect(host: &str, config: Config) {}

fn main() {
    connect("localhost", Config::default());

    connect("google.com", Config {
        port: 443,
        ..Config::default()
    });
}
```

### Required and Default arguments

```rust
struct Config {
    host: String,
    port: u16,
    timeout: u64,
}

impl Config {
    fn new(host: &str) -> Self {
        Config {
            host: host.to_string(),  // Required
            port: 8080,              // Default value
            timeout: 30,             // Default value
        }
    }
}

fn connect(config: Config) {}

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
    host: String,
    port: u16,
}

struct ServerBuilder {
    host: String,
    port: u16,
}

impl ServerBuilder {
    fn new(host: &str) -> Self {
        ServerBuilder {
            host: host.to_string(),  // Required
            port: 80,                // Default value
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

let request = request.build();
```

Rust crates like [bon](https://bon-rs.com/) allow you to generate builders automatically using macros:

```rust
#[bon::builder]
fn greet1(name: &str, age: u32, language: Option<&str>) {
    let lang = language.unwrap_or("English");
    println!("Hello, {name} (age {age}), speaks {lang}");
}

#[bon::builder]
fn greet2(
    name: &str,
    #[builder(default = 18)]
    age: u32,
) {
    println!("Hello, {name} (age {age})");
}

fn main() {
    greet1()
        .name("Alex")
        .age(30)
        // 'language' can be omitted because it's an Option (defaults to None)
        .call(); 

    greet2()
        .name("Alex")
        // 'age' can be omitted because it has a default value
        .call(); 
}
```
