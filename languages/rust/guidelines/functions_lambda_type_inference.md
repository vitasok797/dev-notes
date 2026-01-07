# Lambda type inference

## Inference from usage

```rust
let add = |x, y| x + y; // Types of x and y are unknown here

let result = add(5, 10); // Now Rust infers: x and y are i32
// add(1.0, 2.0);        // ERROR: types were already fixed as i32
```

## Inference from iterators

```rust
let nums = vec![1, 2, 3];

// x is inferred as &i32 because .iter() yields references
nums.iter().for_each(|x| println!("{}", x));

// x is inferred as i32 (value) because .into_iter() transfers ownership
nums.into_iter().for_each(|x| println!("{}", x));
```

## Inference via destructuring (pattern matching)

```rust
let nums = vec![1, 2, 3];

// We know .iter() yields &i32
// By using |&x|, we destructure the reference and get the value x: i32 directly
let incremented: Vec<i32> = nums.iter().map(|&x| x + 1).collect();
```

## Inference limitations

```rust
// ERROR: Rust doesn't know the type of x to call .len() (String? Vec? &[u8]?)
// let get_len = |x| x.len();

// SOLUTION: Annotate the type explicitly
let get_len = |x: String| x.len();
```
