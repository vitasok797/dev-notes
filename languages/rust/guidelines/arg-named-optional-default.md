# Named, optional and default arguments

[We Have Named Arguments at Home](https://corrode.dev/blog/named-arguments-at-home/)

## Named arguments

## Optional arguments

### Using Option<T>

```rust
fn greet(name: Option<&str>) {
    let user_name = name.unwrap_or("Guest");
    ...
}

fn main() {
    greet(Some("Alex"));
    greet(None);
}
```

```rust
fn greet<S: Into<Option<&'static str>>>(name: S) {
    let user_name = name.into().unwrap_or("Guest");
    ...
}

fn main() {
    greet("Alex");
    greet(None);
}
```

## Default arguments
