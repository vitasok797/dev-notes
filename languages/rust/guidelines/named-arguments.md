# Named arguments

## 1. Passing a configuration structure
The simplest way to mimic named arguments is to pass a struct to the function. Rust's **Field Init Shorthand** makes this code clean when your variable names match the struct fields:

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

## 2. The Builder pattern
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
