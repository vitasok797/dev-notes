# Test organization

[Test Organization (The Book)](https://doc.rust-lang.org/book/ch11-03-test-organization.html)

```rust
pub fn add(a: i32, b: i32) -> i32 {
    a + b
}

pub fn sub(a: i32, b: i32) -> i32 {
    a - b
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn add() {
        assert_eq!(add(2, 2), 4);
    }

    #[test]
    fn sub() {
        assert_eq!(sub(5, 3), 2);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    mod authentication {
        use super::*;
        #[test] fn login() {}
        #[test] fn logout() {}
    }

    mod data_processing {
        use super::*;
        #[test] fn parse() {}
    }
}
```

Catch panic:

```rust
#[test]
#[should_panic]
fn panic() {
    divide(10, 0);
}
```

Catch panic with message substring:

```rust
#[test]
#[should_panic(expected = "by zero")]
fn panic_with_message() {
    divide(10, 0);
}
```

Catch panic at specific line:

```rust
#[test]
fn specific_line_panic() {
    let setup_value = 10;

    let result = std::panic::catch_unwind(|| {
        divide(setup_value, 0);
    });
    assert!(result.is_err());
}
```
