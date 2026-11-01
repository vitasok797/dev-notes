# Float range

▶️[**Run**](https://godbolt.org/z/d9dnhs3v5)

```rust
#![feature(range_into_bounds)]

fn main() {
    // ------------------------------------------------------

    let a = 0.0;
    let b = 1.0;

    assert!(!(a..b).contains(&-0.1));

    assert!((a..b).contains(&0.0));
    assert!((a..b).contains(&0.5));

    assert!(!(a..b).contains(&1.0));
    assert!((a..=b).contains(&1.0));

    assert!(!(a..b).contains(&1.1));

    // ------------------------------------------------------

    let rng = a..b;
    assert!(rng.contains(&0.5));

    // ------------------------------------------------------

    assert!(!(0.0..1.0).is_empty());
    assert!((2.0..1.0).is_empty());

    // ------------------------------------------------------

    // unstable
    use std::ops::IntoBounds;
    let (_, _) = (0.0..1.0).into_bounds();

    // ------------------------------------------------------
}
```
