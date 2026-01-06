# Newtype

[The ultimate guide to Rust newtypes](https://www.howtocodeit.com/guides/ultimate-guide-rust-newtypes) \
[The Newtype Pattern in Rust](https://www.worthe-it.co.za/blog/2020-10-31-newtype-pattern-in-rust.html)

▶️[**Run**](https://godbolt.org/z/z5Ea7j49W)

```rust
use std::fmt;

#[derive(Debug, Clone, Eq, PartialEq)]
struct Password(String);

impl fmt::Display for Password {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", '*'.to_string().repeat(self.0.len()))
    }
}

fn print_password_string(pass: &str) {
    println!("pass (string): {}", pass);
}

fn print_password_newtype(pass: &Password) {
    println!("pass (newtype): {}", pass.0);
    println!("pass (newtype, debug): {:?}", pass);
    println!("pass (newtype, display): {}", pass);
}

fn main() {
    let pass_string = "mysecret_string".to_string();
    print_password_string(&pass_string);
    // print_password_newtype(&pass_string); // compile error

    let pass_newtype = Password("mysecret_newtype".to_string());
    print_password_newtype(&pass_newtype);
    // print_password_string(&pass_newtype); // compile error
}
```
