# Float range

```rust
(0.0..=1.0).contains(&0.5)
```

```rust
let rng = 0.0..=1.0; // core::range::legacy::RangeInclusive
rng.contains(&0.5)

let rng = core::range::RangeInclusive::from(0.0..=1.0);
rng.contains(&0.5)
```

```rust
assert!(!(0.0..1.0).is_empty());
assert!((2.0..1.0).is_empty());
```

```rust
#![feature(range_into_bounds)]
use std::ops::IntoBounds;

fn main() {
    let (_, _) = (0.0..1.0).into_bounds();
}
```
