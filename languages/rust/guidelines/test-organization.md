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
    fn test_add() {
        assert_eq!(add(2, 2), 4);
    }

    #[test]
    fn test_sub() {
        assert_eq!(sub(5, 3), 2);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    mod authentication {
        use super::*;
        #[test] fn test_login() {}
        #[test] fn test_logout() {}
    }

    mod data_processing {
        use super::*;
        #[test] fn test_parse() {}
    }
}
```

Catch panic:

```rust
#[test]
#[should_panic]
fn test_divide_by_zero() {
    divide(10, 0);
}
```

Catch panic with message substring:

```rust
#[test]
#[should_panic(expected = "by zero")]
fn test_divide_by_zero_with_message() {
    divide(10, 0);
}
```

Catch panic at specific line:

```rust
#[test]
fn test_specific_line_panic() {
    let setup_value = 10;

    let result = std::panic::catch_unwind(|| {
        divide(setup_value, 0);
    });
    assert!(result.is_err());
}
```
