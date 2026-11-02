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
  * [AsRef](guidelines/arg-asref.md)
  * [Into\<*numeric*\>](guidelines/arg-into-numeric.md)
  * [Into\<String\>](guidelines/arg-into-string.md)
  * [Named](guidelines/named-arguments.md)
  * [Optional](guidelines/optional-arguments.md)
* [Lambda type inference](guidelines/lambda-type-inference.md)

## Math
* [Float range](guidelines/float-range.md)

## Patterns
* [Decorator](guidelines/decorator.md)

## String
* [String creation from literal](guidelines/string-creation.md)

## Traits
* [FromStr vs From<&str>](guidelines/fromstr.md)

## Types
* [Newtype](guidelines/newtype.md)
* [Object extension](guidelines/object-extension.md)

## Var
* [Block expressions](guidelines/block-expressions.md)
* [Check number in range](guidelines/check-number-in-range.md)
* [Check value in list](guidelines/check-value-in-list.md)
* [matches! macro](guidelines/matches.md)
