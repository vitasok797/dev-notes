# Block expressions

```rust
let x = {
    let y = 5;
    let z = y + 1;
    z * 2
};

assert_eq!(x, 12);
```

```rust
let condition1 = true;
let condition2 = false;

let res = {
    let mut s = String::from("");
    s += "[";
    s += if condition1 { "1" } else { "" }; // using block expressions
    s += if condition2 { "2" } else { "" };
    s += "]";
    s
};

assert_eq!(res, "[1]");
```

```rust
fn add(x: i32, y: i32) -> i32 {
    x + y
}

fn test() {
    let add = "something else";

    let x = {
        // using `add` inside this block
        use crate::add;
        add(1, 2)
    };
    assert_eq!(x, 3);

    // `add` refers to "something else" again
    assert_eq!(add, "something else");
}
```

▶️[**Demo**](https://godbolt.org/z/4xjKceh8E)
