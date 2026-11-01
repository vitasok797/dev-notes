# Object extension

## 1. Extension Traits
If you only need to add new methods to an existing type (even a built-in or third-party one), you create a new trait and implement it for that type.

* Pros: Clean, no wrapper required, original interface remains fully intact.
* Cons: You cannot add new data fields.

## 2. Newtype pattern + Deref
If you need to add new fields (aggregation) but want to avoid writing manual boilerplate to forward original methods, wrap the type and implement the `Deref` trait.

* Pros: The compiler automatically forwards all original method calls from the wrapper to the inner type.
* Cons: It does not automatically forward other trait implementations (like `Clone` or `Display`). For full trait forwarding, Rust developers usually use derive macros like [derive_more](https://crates.io/crates/derive_more) or [ambassador](https://crates.io/crates/ambassador).

------------------------------

| Approach | Use case | Data fields | Boilerplate level |
|---|---|---|---|
| Extension Traits | Just adding behavior | ❌ No new fields | Zero |
| Newtype + Deref | Full aggregation | New fields allowed | Low (automatic for methods) |
