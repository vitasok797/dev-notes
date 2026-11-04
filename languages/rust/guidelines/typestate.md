# Typestate pattern

[(Youtube) "Type-Driven API Design in Rust" by Will Crichton](https://www.youtube.com/watch?v=bnnacleqg6k) ([code](https://godbolt.org/z/fGvhjcbhd))

The **Typestate pattern** in Rust is an API design approach that **encodes the states of a finite state machine directly into the type system**. This shifts business logic and protocol validation from runtime checks to compile-time guarantees, making invalid object states physically unrepresentable.

Thanks to Rust’s **move semantics** and strict ownership model, the language is uniquely suited for this pattern. When a method transitions an object to a new state, it consumes the current state (`self` by value) and returns a completely new type representing the next state.

## Two Common Implementations

### 1. Explicit Structs (Distinct Types)
Each state is represented by a completely separate struct. Methods for transitions are implemented exclusively on the valid state types, ensuring that illegal actions don't even exist as methods on wrong states.

```rust
// State definitions
struct EmptyCart;
struct ActiveCart { items: Vec<String> }
struct PaidCart { receipt_id: u32 }

impl EmptyCart {
    fn new() -> Self { EmptyCart }
    
    // Transition: EmptyCart -> ActiveCart (consumes self)
    fn add_item(self, item: String) -> ActiveCart {
        ActiveCart { items: vec![item] }
    }
}

impl ActiveCart {
    fn add_item(mut self, item: String) -> Self {
        self.items.push(item);
        self
    }
    
    // Transition: ActiveCart -> PaidCart (consumes self)
    fn checkout(self) -> PaidCart {
        // Payment processing logic...
        PaidCart { receipt_id: 42 }
    }
}
```

### 2. Generic Typestate (Using PhantomData)
A single main struct leverages a generic marker parameter to enforce states. This prevents code duplication when multiple states share the same internal fields.

```rust
use std::marker::PhantomData;

// State marker types
struct Draft;
struct Reviewed;
struct Published;

// Core container
struct Post<State> {
    content: String,
    _state: PhantomData<State>, // Necessary because State is not used in data fields
}

// Methods available to ALL states
impl<State> Post<State> {
    fn content(&self) -> &str { &self.content }
}

// Methods only for Draft state
impl Post<Draft> {
    fn new(content: String) -> Self {
        Post { content, _state: PhantomData }
    }

    // Transition: Draft -> Reviewed
    fn review(self) -> Post<Reviewed> {
        Post { content: self.content, _state: PhantomData }
    }
}

// Methods only for Reviewed state
impl Post<Reviewed> {
    // Transition: Reviewed -> Published
    fn publish(self) -> Post<Published> {
        Post { content: self.content, _state: PhantomData }
    }
}
```

## Key Benefits

*   **Compile-Time Safety:** You cannot call `.checkout()` on a draft or empty cart. The compiler stops you immediately with a `no method named... found for struct...` error.
*   **Prevention of Stale State Use:** Rust's move semantics invalidate the previous variable after a state transition occurs.
    ```rust
    let cart = EmptyCart::new();
    let active = cart.add_item("Rust Book".to_string());
    // cart.add_item(...); // Compile error: value moved!
    ```
*   **Self-Documenting Code & IDE Support:** Auto-completion options dynamically adjust depending on the current state variable, leading to highly discoverable APIs.
*   **Zero-Cost Abstraction:** The compiler optimizes types and `PhantomData` away completely, producing zero runtime overhead.

## When Should You Use It?

1.  **Type-Safe Builders:** Ensuring that mandatory fields are provided in a precise sequence before an object can be built.
2.  **Network/Protocol State Machines:** Modeling states like `Disconnected` → `Connecting` → `Connected` → `Authenticated`.
3.  **Hardware Drivers (Embedded Rust):** Restricting pin configurations (e.g., ensuring a pin cannot write data while in `Input` mode).
