# Check path extensions

```rust
let has_ext = path.extension().is_some_and(|ext| ext.eq_ignore_ascii_case("gz"));
```

```rust
let has_one_of_ext = path.extension()
    .and_then(|ext| ext.to_str())
    .is_some_and(|ext| matches!(ext.to_lowercase().as_str(), "png" | "jpg" | "jpeg" | "gz"));
```
