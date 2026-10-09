# Named arguments

Rust does not support named arguments (also known as keyword arguments) at the syntax level for functions. This is a conscious design choice by the language maintainers to keep the type system and function signatures simple.
However, Rust provides several idiomatic workarounds that achieve the same result.

## 1. Passing a Configuration Structure
The simplest way to mimic named arguments is to pass a struct to the function. Rust's Field Init Shorthand makes this code clean when your variable names match the struct fields:

```rust
struct CropOptions {
    x: u32,
    y: u32,
    width: u32,
    height: u32,
}

fn crop_image(opts: CropOptions) {
    // Implementation
}

fn main() {
    let x = 0;
    let y = 0;
    
    // Simulating named arguments using a struct
    crop_image(CropOptions {
        x,
        y,
        width: 800,
        height: 600,
    });
}
```

## 2. Structs with Default (For Optional Arguments)
If your function accepts many parameters but most have sensible defaults, you can derive or implement the Default trait and use the Struct Update Syntax (..):

```rust
#[derive(Default)]
struct ConnectionOptions {
    host: String,
    port: u16,
    timeout: u32,
    retry_attempts: u8,
}

fn connect(opts: ConnectionOptions) { /* ... */ }

fn main() {
    connect(ConnectionOptions {
        host: String::from("localhost"),
        port: 8080,
        ..Default::default() // timeout and retry_attempts are filled automatically
    });
}
```

## 3. The Builder Pattern
This is the most popular approach in Rust ecosystem for complex functions. While you can write builders manually, modern Rust crates like [bon](https://bon-rs.com/) allow you to generate them automatically using macros:

```rust
#[bon::builder]
fn greet(name: &str, age: u32, language: Option<&str>) {
    let lang = language.unwrap_or("English");
    println!("Hello, {} (age {}), speaks {}", name, age, lang);
}

fn main() {
    // Calling the function with "named" arguments via the generated builder
    greet()
        .name("Alex")
        .age(30)
        // language can be omitted because it's an Option
        .call(); 
}
```

## 4. The Newtype Pattern (To Prevent Argument Swapping)
If your goal is simply to prevent mixing up arguments of the same type (e.g., passing height where width is expected), you can wrap basic types into distinct structures:

```rust
struct Width(pub u32);
struct Height(pub u32);

fn set_size(w: Width, h: Height) { /* ... */ }

fn main() {
    // Compile-time safety: you cannot accidentally swap these arguments
    set_size(Width(800), Height(600)); 
}
```
