# String creation from literal

In Rust, a string literal (e.g., `"Hello"`) is of type `&'static str`, which is an immutable reference to a string slice stored directly in the compiled binary.
To convert a literal into a dynamic, heap-allocated, and growable `String` type that your code can own and modify, use one of the following standard methods:

## Ways to create a `String` from a Literal

```rust
fn main() {
    // 1. String::from() — The most explicit and readable way
    let s1 = String::from("Hello");

    // 2. .to_string() — A universal method from the ToString trait
    let s2 = "Hello".to_string();

    // 3. .into() — Uses the Into trait; requires an explicit type annotation
    let s3: String = "Hello".into();

    // 4. .to_owned() — Clones the literal data to create an owned String
    let s4 = "Hello".to_owned();
}
```

## Comparison

| Method | Performance & Behavior | When to Use |
|---|---|---|
| `String::from(...)` | Idiomatic and highly readable. Clearly communicates the intention to build a String from a slice. | Use by default for clean and expressive code. |
| `.to_string()` | Generic conversion. Converts any type implementing ToString (like numbers) into a string. | Convenient if you prefer consistent syntax across different types. |
| `.into()` | Type-driven conversion. Works seamlessly when the compiler already expects a String. | Great for shortening code when passing arguments to functions. |
| `.to_owned()` | Highly efficient. Directly allocates heap memory and copies bytes. | Preferred in performance-critical code or when duplicating references. |
