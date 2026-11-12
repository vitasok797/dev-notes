# Default for generic structs

Use `#[derive(Default)]` when generic type parameters genuinely need to implement `Default`. Otherwise, implement `Default` manually to avoid unnecessary trait bounds.

## Use `derive` when the bound is necessary

```rust
#[derive(Default)]
struct Point<T> {
    x: T,
    y: T,
}
```

Here, `T: Default` is required because both fields contain values of type `T`.

## Implement manually when the bound is unnecessary

```rust
struct Container<T> {
    items: Vec<T>,
}

impl<T> Default for Container<T> {
    fn default() -> Self {
        Self {
            items: Vec::new(),
        }
    }
}
```

Here, `Vec<T>` implements `Default` regardless of whether `T` does.

## Example of a compilation failure caused by `derive`

```rust
#[derive(Default)]
struct Container<T> {
    items: Vec<T>,
}

struct NoDefault;

fn main() {
    // ERROR: NoDefault does not implement Default
    let container = Container::<NoDefault>::default();
}
```

The compiler rejects this because `#[derive(Default)]` adds an unnecessary `T: Default` bound.
