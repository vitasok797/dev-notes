# `matches!` macro

[matches!](https://doc.rust-lang.org/std/macro.matches.html)

```rust
let foo = 'f';
assert!(matches!(foo, 'A'..='Z' | 'a'..='z'));
```

```rust
let bar = Some(4);
assert!(matches!(bar, Some(x) if x > 2));
```

```rust
let count = values.iter()
    .filter(|x| matches!(x, Some(n) if *n > 10))
    .count();
```

```rust
if let Ok(_) = result {...}

// replaced by
if matches!(result, Ok(_)) {...}
```

```rust
let mut cnt = 0;
for s in states {
    if let State::Running = s {
        cnt += 1;
    }
}

// replaced by
let cnt = states.iter().filter(|s| matches!(s, State::Running)).count();
```

[assert_matches!](https://doc.rust-lang.org/std/macro.assert_matches.html)

```rust
let a = Some(345);
assert_matches!(a, Some(_));
assert_matches!(a, Some(345));
assert_matches!(a, Some(x) if x > 100);
```
