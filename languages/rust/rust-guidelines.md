# Rust / Guidelines

[*Godbolt*](https://godbolt.org/z/W1xT841hz) \
[*Rust Playground*](https://play.rust-lang.org/)

## Cargo
* [Cargo configuration](guidelines/cargo-configuration.md)
* [Cargo offline usage](guidelines/cargo-offline.md)

## Crates and Modules
* ⚠️ [Module visibility & encapsulation strategy](guidelines/module-visibility.md)
* [Test organization](guidelines/test-organization.md)

## File
* [Check `Path` extensions](guidelines/check-path-ext.md)

## Functions
* Arguments:
  * [`AsRef<>`](guidelines/arg-asref.md)
  * [`Into<*numeric*>`](guidelines/arg-into-numeric.md)
  * [`Into<String>`](guidelines/arg-into-string.md)
  * [Flexible argument types](guidelines/arg-flexible-types.md)
  * [Named, optional and default](guidelines/arg-named-optional-default.md)
* ⚠️ [Lambda type inference](guidelines/lambda-type-inference.md)

## Iterators
* [Filter `Result`](guidelines/filter-result.md)

## Math
* [Float range](guidelines/float-range.md)

## Patterns
* ⚠️ [Decorator](guidelines/decorator.md)
* [Scope guard](guidelines/scope-guard.md)
* ⚠️ [Typestate](guidelines/typestate.md)

## String
* [`String` creation from literal](guidelines/string-creation.md)

## Traits
* [`Default` for generic structs](guidelines/default-for-generic-structs.md)
* ⚠️ [`Deref`, `Index`, method resolution, type coercions](guidelines/deref.md)
* ⚠️ [`FromStr` vs `From<&str>`](guidelines/fromstr.md)

## Types
* [Containers layout cheat sheet](guidelines/img/container-cheat-sheet.png)
* ⚠️ [Newtype](guidelines/newtype.md)
* [Object extension](guidelines/object-extension.md)
* [Ownership and smart pointers](guidelines/ownership-and-smart-pointers.md)
* [Smart pointers with slices](guidelines/smart-pointers-with-slices.md)

## Var
* [`matches!` macro](guidelines/matches.md)
* [Block expressions](guidelines/block-expressions.md)
* [Check number in range](guidelines/check-number-in-range.md)
* [Check value in list](guidelines/check-value-in-list.md)
* [Environment variables](guidelines/environment-variables.md)
* [One-time initialization](guidelines/one-time-init.md)
* [Platform specific](guidelines/platform-specific.md)
