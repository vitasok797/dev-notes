# Into<*numeric*> function argument

Accepts any type that can be **safely** converted into a target type:

```rust
fn process_number(value: impl Into<i64>) {
    let value: i64 = value.into();
    println!("Processing: {}", value);
}

fn main() {
    let num1: u32 = 42;
    let num2: i64 = 100;
    let num3: u64 = 333;

    process_number(num1); // OK
    process_number(num2); // OK
    // process_number(num3); // Compile error

    let safe_num = i64::try_from(num3).unwrap();
    process_number(safe_num);

    let safe_num: i64 = num3.try_into().unwrap();
    process_number(safe_num);

    let safe_num = num3.try_into().unwrap_or(0_i64);
    process_number(safe_num);
}
```
