# Check value in list

```rust
if [1, 2, 3].contains(&x) { ... }
```

```rust
if matches!(x, 1 | 2 | 3) { ... }
```

```rust
match x {
    1 | 2 | 3 => ...,
    _ => ...,
}
```
