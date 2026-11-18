# Deref, Index, and method resolution

## 1. The Dereference Operator `*` (`Deref` trait)
Designed to allow smart pointers (like `Box`, `Vec`, `String`) to syntactically behave exactly like regular, primitive references.

- **On the Syntax Level:** The `*s` expression returns the **"naked" `Target` type** (which can be an unsized type, such as `[T]` or `str`).
- **Under the Hood (Desugaring):** The compiler expands `*s` into a strict structural pipeline: `*( Deref::deref(&s) )`.
  1. The `deref()` method always returns a **standard primitive reference** `&Target`.
  2. The outer asterisk `*` (built natively into the compiler) "strips" this reference away to reveal the naked type.
- **For Primitive References (e.g., `&i32`):** The `Deref` trait is completely bypassed. The compiler directly generates a raw CPU instruction to read memory from that address (e.g., a `mov` instruction on x86/x64).

## 2. The Index and Slicing Operator `[...]` (`Index` trait)
Used to access elements within a collection or to extract a cheap "window" (slice) of data.

- **On the Syntax Level:** The slice expression `v[1..3]` returns a **"naked" unsized type `[T]`**. To store it in a variable or pass it to a function, it *must* be immediately wrapped in an ampersand (`&v[1..3]`).
- **Under the Hood (Desugaring):** The expression `&v[1..3]` unfolds into: `&( *Index::index(&v, 1..3) )`.
  1. The `index()` method returns a **standard reference** `&[T]`.
  2. The inner hidden asterisk `*` strips it down to the naked `[T]` type.
  3. Your outer ampersand `&` instantly wraps it back into a 16-byte fat pointer on the stack (`pointer + length`).
- **Annihilation:** In the final compiled machine code, the inner asterisk and the outer ampersand annihilate each other, leaving nothing but a clean, optimized function call: `Index::index(...)`.

## 3. The Dot Operator Method Call `object.method()`
A built-in ergonomics mechanism that saves the developer from having to manually juggle reference types when calling functions. A method *always* belongs strictly to the `impl T` block it was written in, but the compiler dynamically adjusts the object before the dot to match the signature.

The **Method Resolution** algorithm works as follows:

1. **Layer 1 (Direct Match):** The compiler checks the type `T` itself, as well as direct borrowing variations: `&T` and `&mut T`. If a method expects `&self` (i.e., `self: &T`), the compiler automatically inserts an ampersand before the object (**Autoref**).
2. **Layer 2 (Dereferencing):** If no match is found, the compiler takes a step through the `Deref` trait to the `Target` type (the `*Deref::deref(&object)` expression) and repeats Layer 1 entirely for `Target`, `&Target`, and `&mut Target`.
3. This evaluation chain continues down the dereference pipeline until a matching method is found or the compiler hits a dead end.

## 4. Automatic Type Coercion (`Deref Coercion`)
This mechanism applies **strictly to function and method arguments**. If a function expects a reference to one type (e.g., `&[T]`), but you pass a reference to another type (e.g., `&Vec<T>`), the compiler will implicitly invoke the `Deref` trait as many times as necessary to make the types match.

- Coercing `&Vec<T>` instantly yields `&[T]` because `Vec` implements `Deref<Target = [T]>`.
- Coercing `&String` instantly yields `&str` because `String` implements `Deref<Target = str>`.

---

## The Ultimate Summary: Rust's Core Syntactic Paradox
Built-in language operators (`*`, `[...]`) and dot method lookups (`.`) **are grand illusionists**. They syntactically leave a "naked" type behind for one explicit reason: to allow you, the programmer, to **use a single character on the left (`&` or `&mut`) to decide exactly what kind of reference (shared or exclusive) you want to obtain**.

--------------

If  `T`  implements  `Deref<Target = U>`, and  `v`  is a value of type  `T`, then:
- In immutable contexts,  `*v`  (where  `T`  is neither a reference nor a raw pointer) is equivalent to  `*Deref::deref(&v)`.
- Values of type  `&T`  are coerced to values of type  `&U`
- `T`  implicitly implements all the methods of the type  `U`  which take the  `&self`  receiver.
([Deref coercion](https://doc.rust-lang.org/std/ops/trait.Deref.html#deref-coercion))

If T implements DerefMut<Target = U>, and v is a value of type T, then:

- In mutable contexts, *v (where T is neither a reference nor a raw pointer) is equivalent to *DerefMut::deref_mut(&mut v).
- Values of type &mut T are coerced to values of type &mut U
- T implicitly implements all the (mutable) methods of the type U.

`container[index]` is actually syntactic sugar for `*container.index(index)`, but only when used as an immutable value. If a mutable value is requested, [`IndexMut`](https://doc.rust-lang.org/std/ops/trait.IndexMut.html "trait std::ops::IndexMut") is used instead. This allows nice things such as `let value = v[index]` if the type of `value` implements [`Copy`](https://doc.rust-lang.org/std/marker/trait.Copy.html "trait std::marker::Copy").
([Trait  Index](https://doc.rust-lang.org/std/ops/trait.Index.html))

container[index] is actually syntactic sugar for *container.index_mut(index), but only when used as a mutable value. If an immutable value is requested, the Index trait is used instead. This allows nice things such as v[index] = value.

- https://doc.rust-lang.org/book/ch15-02-deref.html#implementing-the-deref-trait
- https://doc.rust-lang.org/reference/expressions/operator-expr.html#the-dereference-operator
- https://doc.rust-lang.org/reference/expressions/method-call-expr.html
- https://doc.rust-lang.org/reference/type-coercions.html
