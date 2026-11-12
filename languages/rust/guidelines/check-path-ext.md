# Check `Path` extensions

```rust
let is_match = path.extension()
    .is_some_and(|ext| ext.eq_ignore_ascii_case("gz"));
```

```rust
let extensions = ["PNG", "JPG", "JPEG"];
let is_match = path.extension()
    .is_some_and(|ext| {extensions.iter().any(|e| ext.eq_ignore_ascii_case(e))});
```
