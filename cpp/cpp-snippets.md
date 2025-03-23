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

Class template:
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

Virtual:
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

## If statement with initializer (C++17)

[C++17 If statement with initializer](https://skebanga.github.io/if-with-initializer/)

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

## Namespace using

[Namespace using directives](https://en.cppreference.com/w/cpp/language/namespace#Using-directives)

```cpp
namespace A {...}
 
namespace B
{
    using namespace A;
}
```

## Structured Bindings (C++17)

[Structured binding declaration](https://en.cppreference.com/w/cpp/language/structured_binding)

Unpack tuple:
```cpp
#include <tuple>

std::tuple tuple{1, 'a', 2.3};

auto [i, c, d] = tuple;
auto& [i, c, d] = tuple;
```

Unpack struct:
```cpp
struct Foo
{
    int i;
    char c;
    double d;
};

Foo f {1, 'a', 2.3};

auto [i, c, d] = f;
auto& [i, c, d] = f;
```

Unpack map:
```cpp
#include <map>

for (const auto& [k, v] : mymap) {...}

for (auto&& [k, v] : std::map<std::string, int>{{"hello", 1}, {"world", 2}}) {...}
```
