# Smart pointers with slices

Replacing a `Vec<T>` or a vector-wrapped smart pointer (like `Arc<Vec<T>>` or `Rc<Vec<T>>`) with a slice-based alternative is a powerful optimization for read-only data collections:

- `Vec<T>` -> `Box<[T]>`;
- `Arc<Vec<T>>` -> `Arc<[T]>`;
- `Rc<Vec<T>>` -> `Rc<[T]>`.

[Habr](https://habr.com/ru/articles/801125/)

## Core Benefits

- Eliminates the "Double Pointer Hop": Standard vectors store data via a pointer to another location in the heap. Slices (`[T]`) combined with smart pointers allocate the metadata (counters/headers) and the actual elements together in a single contiguous block of heap memory. This improves CPU cache locality;
- Reduces Memory Overhead: Slices do not have a capacity field (which vectors use for dynamic resizing). This saves 8 bytes of stack/heap space per allocation and prevents over-allocating unused memory;
- Enforces Immutability: Moving data into a fixed-size slice guarantees at the type level that the collection length cannot be accidentally modified.

## Ownership & threading selection

The underlying memory optimization is identical for all three types, but they serve different concurrency needs:

- `Box<[T]>`: Use for single ownership when data is read-only and no longer needs to grow;
- `Rc<[T]>`: Use for shared ownership within a single thread (cheaper, non-atomic counters);
- `Arc<[T]>`: Use for shared ownership across multiple threads (uses atomic counters).
