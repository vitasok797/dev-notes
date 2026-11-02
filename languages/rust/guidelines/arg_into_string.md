# Into\<String\> function argument

**When to use**: Use this pattern only if the function **needs to take ownership** of the data (e.g., storing it in a struct). If the function only needs to read the text, use `&str` instead to avoid unnecessary allocations.

Accepts types:

- String (move);
- &String (clone);
- &str (clone);
- Anything that can be converted into a String (`From<> for String` is implemented).

```rust
#[allow(unused)]
struct User {
    name: String,
}

impl User {
    // Accepts anything that can be converted into a String
    fn new(name: impl Into<String>) -> Self {
        Self { name: name.into() }
    }
}

fn main() {
    // Works with &str
    let _user = User::new("Alex");

    // Works with String
    let _user = User::new(String::from("Maria"));

    // Works with &String
    let user_name = String::from("John");
    let _user = User::new(&user_name);
}
```
