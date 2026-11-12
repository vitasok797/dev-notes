# String creation from literal

## Ways to create a `String` from a literal (of type `&'static str`)

1. `String::from()`:

```rust
let s = String::from("Hello");
```

2. `.to_string()`:

```rust
let s = "Hello".to_string();
```

3. `.into()`:

```rust
let s: String = "Hello".into();
```

4. `.to_owned()`:

```rust
let s = "Hello".to_owned();
```

## Comparison

| Method | Performance & behavior | When to use |
|---|---|---|
| `String::from(...)` | Idiomatic and highly readable. Clearly communicates the intention to build a `String` from a slice. | Use by default for clean and expressive code. |
| `.to_string()` | Generic conversion. Converts any type implementing `ToString` (like numbers) into a string. | Convenient if you prefer consistent syntax across different types. |
| `.into()` | Type-driven conversion. Works seamlessly when the compiler already expects a `String`. | Great for shortening code when passing arguments to functions. |
| `.to_owned()` | Highly efficient. Directly allocates heap memory and copies bytes. | Preferred in performance-critical code or when duplicating references. |
