# Rust / Guidelines

[*Godbolt*](https://godbolt.org/z/W1xT841hz) \
[*Rust Playground*](https://play.rust-lang.org/)

## Cargo
* [Cargo offline usage](guidelines/cargo-offline.md)

## Crates and Modules
* [Module visibility & encapsulation strategy](guidelines/module-visibility.md)
* [Test organization](guidelines/test-organization.md)

## Functions
* Arguments:
  * [Flexible argument types](guidelines/arg-flexible-types.md)
  * [Named, optional and default](guidelines/arg-named-optional-default.md)
  * [Trait: AsRef](guidelines/arg-asref.md)
  * [Trait: Into\<*numeric*\>](guidelines/arg-into-numeric.md)
  * [Trait: Into\<String\>](guidelines/arg-into-string.md)
* [Lambda type inference](guidelines/lambda-type-inference.md)

## Math
* [Float range](guidelines/float-range.md)

## Patterns
* [Decorator](guidelines/decorator.md)
* [Typestate](guidelines/typestate.md)

## String
* [String creation from literal](guidelines/string-creation.md)

## Traits
* [Default for generic structs](guidelines/default-for-generic-structs.md)
* [FromStr vs From<&str>](guidelines/fromstr.md)

## Types
* [Container cheat sheet](guidelines/img/container-cheat-sheet.png)
* [Newtype](guidelines/newtype.md)
* [Object extension](guidelines/object-extension.md)
* [Ownership and smart pointers](guidelines/ownership-and-smart-pointers.md)
* [Smart pointers with slices](guidelines/smart-pointers-with-slices.md)

## Var
* [Block expressions](guidelines/block-expressions.md)
* [Check number in range](guidelines/check-number-in-range.md)
* [Check value in list](guidelines/check-value-in-list.md)
* [matches! macro](guidelines/matches.md)
* [Platform specific](guidelines/platform-specific.md)
