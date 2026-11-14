# Scope guard

```rust
use std::mem::DropGuard;

fn main() {
    {
        println!("+++");

        let _guard_1 = DropGuard::new((), |_| println!("guard 1"));

        let guard_2 = DropGuard::new((), |_| println!("guard 2"));
        DropGuard::dismiss(guard_2);

        println!("---");
    }
}
```
