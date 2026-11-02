# AsRef\<\> function argument

`AsRef` (`AsMut`) is typically used to make functions more flexible in the argument types they accept.
When a type implements `AsRef<T>`, that means you can borrow a `&T` from it efficiently (`AsMut` is the analogue for mutable references). 

For example, the `std::fs::File::open` function is declared like this:

```rust
fn open<P: AsRef<Path>>(path: P) -> Result<File>
```

What open really wants is a `&Path`.
But with this signature, open accepts anything it can borrow a `&Path` from:

- `String`;
- `str`;
- `OsString`;
- `OsStr`;
- `PathBuf`;
- `Path`.

But this can’t be the whole story. A string literal is a `&str`, but the type that implements `AsRef<Path>` is `str`, without an `&`.
Fortunately, the standard library includes the blanket implementation: for any types `T` and `U`, if `T: AsRef<U>`, then `&T: AsRef<U>` as well.
In particular, since `str: AsRef<Path>`, then `&str: AsRef<Path>` as well.
