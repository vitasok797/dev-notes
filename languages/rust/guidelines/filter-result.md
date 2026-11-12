# Filter Result

## Using `flatten()`

Iterate by ref:

```rust
let entries = vec![Ok(1), Err("error"), Ok(2)];

let ok_entries: Vec<&i32> = entries
    .iter()
    .flatten()
    .collect();

println!("{ok_entries:?}"); // [1, 2]
```

Iterate by value:

```rust
let entries = vec![Ok(1), Err("error"), Ok(2)];

let ok_entries: Vec<i32> = entries
    .into_iter()
    .flatten()
    .collect();

println!("{ok_entries:?}"); // [1, 2]
```

## Using `filter_map()`

Iterate by ref:

```rust
let entries = vec![Ok(1), Err("error"), Ok(2)];

let ok_entries: Vec<&i32> = entries
    .iter()
    .filter_map(|r| r.as_ref().ok())
    .collect();

println!("{ok_entries:?}"); // [1, 2]
```

Iterate by value:

```rust
let entries = vec![Ok(1), Err("error"), Ok(2)];

let ok_entries: Vec<i32> = entries
    .into_iter()
    .filter_map(Result::ok)
    .collect();

println!("{ok_entries:?}"); // [1, 2]
```
