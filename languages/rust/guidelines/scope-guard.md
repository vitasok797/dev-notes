# Scope guard

```rust
use std::mem::DropGuard;

let _guard = DropGuard::new((), |_| println!("guard"));
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

#[allow(unused)]
#[derive(Debug)]
struct MyStruct {
    value: i32,
    mode: Mode,
}

impl MyStruct {
    fn option_1(&mut self) {
        let mut self_ = {
            let restore_mode = self.mode.clone();
            DropGuard::new(self, |x| x.mode = restore_mode)
        };

        self_.mode = Mode::NonBlocking;

        // SOME CODE

        println!("{self_:?}");
    }

    fn option_2(&mut self) {
        let self_ = {
            let restore_mode = std::mem::replace(&mut self.mode, Mode::NonBlocking);
            DropGuard::new(self, |x| x.mode = restore_mode)
        };

        // SOME CODE

        println!("{self_:?}");
    }
}

fn main() {
    let mut s = MyStruct {
        value: 42,
        mode: Mode::Blocking,
    };

    println!("--------------");

    println!("{s:?}");
    s.option_1();
    println!("{s:?}");

    println!("--------------");

    println!("{s:?}");
    s.option_2();
    println!("{s:?}");

    println!("--------------");
}
```
