# C++ / Snippets

## Aliases
<details>
<summary>Type aliases</summary>

[Type aliases reference](https://en.cppreference.com/w/cpp/language/type_alias)

```cpp
using UserId = int;
using UserAccounts = std::map<UserId, std::vector<Account>>;
```

```cpp
// identical to: typedef void (*func)(int, int);
using func = void (*) (int, int);
```

```cpp
template<typename T>
using UserAccounts = std::map<UserId, std::vector<T>>;
```
</details>

<details>
<summary>Namespace aliases</summary>

[Namespace aliases reference](https://en.cppreference.com/w/cpp/language/namespace_alias)

```cpp
namespace fbz = foo::bar::baz;
```
</details>

## Classes

[Language / Classes](cpp-language.md#classes)

<details>
<summary>Class template</summary>

```cpp
class MyClass
{
public:
    // Types and type aliases
    // Static constants

    MyClass() = default;

    MyClass(const MyClass&) = default;
    MyClass(MyClass&&) = default;
    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) = default;

    virtual ~MyClass() = default;

    // Functions
    // Data members

protected:
    // Types and type aliases
    // Static constants
    // Functions
    // Data members

private:
    // Types and type aliases
    // Static constants
    // Functions
    // Data members
};
```
</details>

<details>
<summary>Virtual</summary>

```cpp
struct Base
{
    virtual void foo() = 0;
    virtual ~Base() = default;
};

struct A : Base
{
    void foo() override;
    ~A() override;
};

struct B final : A
{
    void foo() final;
    ~B() final;
};
```
</details>

## If statement with initializer (C++17)

[(Article) C++17 If statement with initializer](https://skebanga.github.io/if-with-initializer/)

<details>
<summary>Examples</summary>

```cpp
if (init; condition) {...}
```

```cpp
if (auto a = getval(); a < 10) {...}
```

```cpp
switch (auto ch = getnext(); ch)
{
    // case statements
}
```

```cpp
if (auto [itelem, success] = mymap.insert(std::pair('a', 100)); success) {...}
```
</details>

## Namespace using

[Namespace using reference](https://en.cppreference.com/w/cpp/language/namespace#Using-directives)

<details>
<summary>Examples</summary>

```cpp
namespace A {...}
 
namespace B
{
    using namespace A;
}
```
</details>

## Structured Bindings (C++17)

[Structured bindings reference](https://en.cppreference.com/w/cpp/language/structured_binding)

<details>
<summary>Syntax</summary>

```cpp
auto [a, b, c] = ...
const auto [a, b, c] = ...

auto& [a, b, c] = ...
const auto& [a, b, c] = ...

auto&& [a, b, c] = ...
```
</details>

<details>
<summary>Unpack tuple</summary>

```cpp
#include <tuple>

std::tuple tuple{1, 'a', 2.3};

auto [a, b, c] = tuple;
```
</details>

<details>
<summary>Unpack struct</summary>

```cpp
struct Foo
{
    int i;
    char c;
    double d;
};

Foo f {1, 'a', 2.3};

auto [i, c, d] = f;
```
</details>

<details>
<summary>Unpack map</summary>

```cpp
#include <map>

for (const auto& [k, v] : mymap) {...}

for (auto&& [k, v] : std::map<std::string, int>{{"hello", 1}, {"world", 2}}) {...}
```
</details>
