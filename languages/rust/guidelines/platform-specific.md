# Platform specific

- [std::env::consts](https://doc.rust-lang.org/stable/std/env/consts/)
- [std::path Сonstants](https://doc.rust-lang.org/std/path/index.html#constants)
- Conditional compilation ([cfg attribute](https://doc.rust-lang.org/reference/conditional-compilation.html#the-cfg-attribute), [cfg macro](https://doc.rust-lang.org/std/macro.cfg.html)):
  - [target_os](https://doc.rust-lang.org/reference/conditional-compilation.html#target_os)
  - [target_family](https://doc.rust-lang.org/reference/conditional-compilation.html#target_family)
  - [unix and windows](https://doc.rust-lang.org/reference/conditional-compilation.html#unix-and-windows) (target_family shortcuts)

```rust
#[cfg(windows)]
#[cfg(unix)]
```

```rust
#[cfg(windows)]
mod platform_consts {
	pub const VAR_STR: (&str, &str) = ("CARGO_PKG_NAME", "playground");
	pub const VAR_INT: (&str, i32) = ("CARGO_PKG_VERSION_PATCH", 1);
	pub const VAR_UNKNOWN: &str = "UNKNOWN";
}

#[cfg(unix)]
mod platform_consts {
	pub const VAR_STR: (&str, &str) = ("CARGO_PKG_NAME", "playground");
	pub const VAR_INT: (&str, i32) = ("CARGO_PKG_VERSION_PATCH", 1);
	pub const VAR_UNKNOWN: &str = "UNKNOWN";
}

use platform_consts::*;
```
