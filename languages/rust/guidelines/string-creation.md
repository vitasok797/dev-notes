# String creation from literal

## Ways to create a `String` from a literal (`&'static str`)

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

| Method | When to use |
|---|---|
| `String::from(...)` | Recommended default when explicitly creating a `String` from a string literal or `&str` |
| `.to_string()` | When converting different types (numbers, booleans, etc.) to strings or when consistent syntax is preferred |
| `.into()` | When the target type is already known from context. Useful for concise, idiomatic code |
| `.to_owned()` | When emphasizing the conversion from borrowed to owned data, especially in generic code |
