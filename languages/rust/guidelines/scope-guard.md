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

```rust
use std::mem::DropGuard;

#[derive(Debug, Clone)]
enum Mode {
    Blocking,
    NonBlocking,
}

#[derive(Debug)]
struct MyStruct {
    #[allow(unused)]
    value: i32,
    #[allow(unused)]
    mode: Mode,
}

impl MyStruct {
    fn test(&mut self) {
        let mut self_ = {
            let restore_mode = self.mode.clone();
            DropGuard::new(self, move |x| x.mode = restore_mode)
        };

        self_.mode = Mode::NonBlocking;
        println!("{self_:?}");
    }
}

fn main() {
    let mut s = MyStruct {
        value: 42,
        mode: Mode::Blocking,
    };

    println!("{s:?}");
    s.test();
    println!("{s:?}");
}
```
