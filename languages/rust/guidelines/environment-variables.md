# Environment variables

[Function `var`](https://doc.rust-lang.org/std/env/fn.var.html) \
[Function `var_os`](https://doc.rust-lang.org/std/env/fn.var_os.html) \
[Enum `VarError`](https://doc.rust-lang.org/std/env/enum.VarError.html)

## Exists

```rust
let exists = std::env::var_os("name").is_some();
```

```rust
let exists = std::env::var("name").is_ok()
```

## Get as string

```rust
let value: String = std::env::var("name").unwrap();
```

## Get as string or

```rust
let value: String = std::env::var("name").unwrap_or_else(|_| "default".to_owned());
```

## Get and parse

```rust
let value: i32 = std::env::var("name").unwrap().parse().unwrap();
```

## Get and parse or

```rust
let value: i32 = std::env::var("name").unwrap().parse().unwrap_or(123);
```
