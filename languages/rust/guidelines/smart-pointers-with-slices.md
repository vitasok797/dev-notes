# Smart pointers with slices

[Article](https://habr.com/ru/articles/801125/)

Replacing a `Vec<T>` or a vector-wrapped smart pointer (like `Arc<Vec<T>>` or `Rc<Vec<T>>`) with a slice-based alternative is a powerful optimization for read-only data collections:

- `Vec<T>` -> `Box<[T]>`;
- `Rc<Vec<T>>` -> `Rc<[T]>`;
- `Arc<Vec<T>>` -> `Arc<[T]>`.

The underlying memory optimization is identical for all three types, but they serve different concurrency needs:

- `Box<[T]>`: Use for single ownership when data is read-only and no longer needs to grow;
- `Rc<[T]>`: Use for shared ownership within a single thread (cheaper, non-atomic counters);
- `Arc<[T]>`: Use for shared ownership across multiple threads (uses atomic counters).

## Core Benefits

- Eliminates the extra pointer indirection for `Rc` and `Arc`;
- Reduces memory overhead. Slices do not have a capacity field. This saves 8 bytes of stack/heap space per allocation;
- Enforces immutability.

## Creating

### `Box<[T]>`:

```rust
// From array
let a: Box<[i32]> = Box::new([1, 2, 3]);

// From Vec<T> (may reallocate if len != capacity)
let b: Box<[i32]> = vec![1, 2, 3].into_boxed_slice();
let c: Box<[i32]> = vec![1, 2, 3].into();
```

### `Rc<[T]>` (same for `Arc<[T]>`):

```rust
use std::rc::Rc;

// From array
let a: Rc<[i32]> = Rc::new([1, 2, 3]);

// From Vec<T> (moving items)
let b: Rc<[i32]> = Rc::from(vec![1, 2, 3]);

// From &[T] (cloning  items)
let c: Rc<[i32]> = Rc::from(&[1, 2, 3][..]);

// Using Box<[T]> (moving items)
let d: Rc<[i32]> = Rc::from(
    vec![1, 2, 3].into_boxed_slice()
);
```
