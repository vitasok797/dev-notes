# FromStr vs From<&str>

| **Feature** | **FromStr** | **From<&str>** |
| --- | --- | --- |
| **Purpose** | Parsing a value from a string (e.g., converting «123» into an `i32`) | Infallible conversion where the type is essentially a subset or a direct allocation of the string data (e.g., `&str` to `String`) |
| **Fallibility** | Returns `Result<Self, Self::Err>` (can fail) | Returns `Self` (cannot fail) |
| **Usage** | Used with the `.parse()` method on `&str` | Used with the `From::from()` method, or implicitly through `Into::into()` |
| **Lifetimes** | Cannot borrow the input string; the resulting type must own all its data (no lifetime parameters) | Can use lifetimes, allowing the new type to borrow the input string data |
