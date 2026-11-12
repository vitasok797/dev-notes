# Check `Path` extensions

```rust
let is_match = path.extension()
    .is_some_and(|ext| ext.eq_ignore_ascii_case("gz"));
```

```rust
let is_match = path.extension()
    .and_then(|ext| ext.to_str())
    .is_some_and(|ext| matches!(ext.to_lowercase().as_str(), "png" | "jpg" | "jpeg"));
```

```rust
let extensions = ["PNG", "JPG", "JPEG"];
let is_match = path.extension()
    .is_some_and(|ext| {extensions.iter().any(|e| ext.eq_ignore_ascii_case(e))});
```
