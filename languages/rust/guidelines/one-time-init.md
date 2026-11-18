# One-time initialization

## Thread-Safe

- [LazyLock](https://doc.rust-lang.org/std/sync/struct.LazyLock.html)
  - **Data container**: Yes
  - **Initialization method**: Implicit (Automatic via Deref on first access)
  - **Best used for**: Global static variables that compute their value automatically when first needed (replaces the lazy_static crate).
- [OnceLock](https://doc.rust-lang.org/beta/std/sync/struct.OnceLock.html)
  - **Data container**: Yes
  - **Initialization method**: Explicit (Manual via .get_or_init() or .set())
  - **Best used for**: Global static variables where you need to control when or how the data is initialized during runtime.
- [Once](https://doc.rust-lang.org/beta/std/sync/struct.Once.html)
  - **Data container**: No (Executes initialization logic only)
  - **Initialization method**: Explicit (Manual via .call_once())
  - **Best used for**: Running a one-time initialization function (e.g., FFI C-library setup or global logger configuration) without storing data inside the primitive.

## Single-threaded only

- [LazyCell](https://doc.rust-lang.org/beta/std/cell/struct.LazyCell.html)
  - **Data container**: Yes
  - **Initialization method**: Implicit (Automatic via Deref on first access)
  - **Best used for**: Heavy fields inside local structs or functions that should be lazily evaluated without atomic overhead.
- [OnceCell](https://doc.rust-lang.org/std/cell/struct.OnceCell.html)
  - **Data container**: Yes
  - **Initialization method**: Explicit (Manual via .get_or_init() or .set())
  - **Best used for**: Storing a single-threaded value that is set exactly once later in the program, avoiding atomic overhead.
