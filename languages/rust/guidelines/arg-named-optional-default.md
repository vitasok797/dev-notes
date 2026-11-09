# Named, optional and default arguments

[We Have Named Arguments at Home](https://corrode.dev/blog/named-arguments-at-home/)

## Named arguments using Newtype pattern

```rust
struct Width(pub u32);
struct Height(pub u32);

fn set_size(w: Width, h: Height) {}

set_size(Width(800), Height(600)); 
```

## Optional arguments using `Option<T>`

```rust
fn greet(name: Option<&str>) {
    let user_name = name.unwrap_or("Guest");
    println!("{user_name}");
}

greet(None);
greet(Some("Alex"));
greet(Some(&String::from("John")));
```

## Structs

## Builder pattern
