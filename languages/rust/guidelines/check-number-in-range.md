# Check number in range

## 1. Using the `.contains()` method (recommended)

```rust
(1..10).contains(&number)
(1..=10).contains(&number)
(..10).contains(&number)
(5..).contains(&number)
```

## 2. Pattern matching with `match`

If you need to execute different logic based on multiple ranges, use a `match` expression. Note that `match` only supports inclusive ranges (`..=`) for values.

```rust
match score {
    1..=50 => ...,
    51..=80 => ...,
    81..=100 => ...,
    _ => println!("Out of bounds"),
}
```

## 3. Using the `matches!` macro

If you prefer the pattern matching syntax but just want a quick `bool` value, the `matches!` macro is highly readable and clean.

```rust
let is_valid = matches!(number, 1..=10);
```

## 4. Comparison operators (classic approach)

This is a standard low-level option that works universally without instantiating a range object. It is useful when your bounds are dynamic variables.

```rust
if number >= min && number <= max {...}
```
