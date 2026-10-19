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
