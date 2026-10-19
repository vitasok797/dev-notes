# Module visibility & encapsulation strategy

In Rust, managing module visibility is a powerful tool for enforcing encapsulation, maintaining data invariants, and designing clean APIs.
This strategy is critical when developing **libraries (library crates)**, where exposing internal implementation details can lock you into rigid APIs and cause breaking changes for downstream users.

## The Rule of Thumb for library design

When designing your codebase, always apply the **Principle of least privilege**. Start with the most restrictive visibility modifier and expand access only when explicitly required by your architecture.

### The recommended default ordering (from restrictive to permissive):

```text
[Strict private] ─> [Parent only] ─> [Internal shared] ─> [Public API]
```

1. **`No modifier` (default private)**
   * **Scope:** Visible only within the current file/module.
   * **Intent:** Use this for 90% of your code. It provides maximum isolation and allows you to rewrite internal logic safely without breaking anything outside the file.

2. **`pub(super)`**
   * **Scope:** Visible only to the immediate parent module.
   * **Intent:** Ideal for micro-modules and internal file splitting. Use this when breaking down a massive file into smaller, logical sub-files without polluting the rest of the project.

3. **`pub(crate)`**
   * **Scope:** Visible anywhere within the current Cargo crate (project).
   * **Intent:** The ultimate tool for internal teamwork. Use this to share foundational data structures, traits, and utilities across distinct modules (e.g., database, network, logging) while completely hiding them from external library users.

4. **`pub`**
   * **Scope:** Fully public to the entire world.
   * **Intent:** This is your official, stable API contract. Apply this sparingly only to the final types, methods, and traits that your users are supposed to interact with.

## Chain-of-visibility

> ⚠️ The final visibility of any item is limited by the **strictest (narrowest) link** in its module path tree.

If a fully `pub` function is buried inside a `pub(crate)` module, it remains hidden from the outside world. This design characteristic allows you to aggressively use explicit visibility markers internally, giving you full architectural control over what gets exposed through deliberate re-exports (`pub use`).
