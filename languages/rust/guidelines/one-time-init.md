# One-time initialization

## Thread-Safe

- [LazyLock](https://doc.rust-lang.org/std/sync/struct.LazyLock.html)
  - **Initialization method**: Implicit (automatic via Deref on first access)
  - **Best used for**: Global static variables that compute their value automatically when first needed
- [OnceLock](https://doc.rust-lang.org/beta/std/sync/struct.OnceLock.html)
  - **Initialization method**: Explicit (manual via .get_or_init() or .set())
  - **Best used for**: Global static variables where you need to control when or how the data is initialized during runtime

## Single-threaded only

- [LazyCell](https://doc.rust-lang.org/beta/std/cell/struct.LazyCell.html)
  - **Initialization method**: Implicit (automatic via Deref on first access)
  - **Best used for**: Heavy fields inside local structs or functions that should be lazily evaluated without atomic overhead
- [OnceCell](https://doc.rust-lang.org/std/cell/struct.OnceCell.html)
  - **Initialization method**: Explicit (manual via .get_or_init() or .set())
  - **Best used for**: Storing a single-threaded value that is set exactly once later in the program, avoiding atomic overhead
