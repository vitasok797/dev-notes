# Scope guard

```rust
use std::mem::DropGuard;

let guard = DropGuard::new((), |_| println!("guard"));
```

```rust
use std::mem::DropGuard;

let guard = DropGuard::new((), |_| println!("guard"));
DropGuard::dismiss(guard);
```
