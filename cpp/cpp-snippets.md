# C++ / Snippets

## Class

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
<summary>Static/const fields</summary>

```cpp
struct BriefExample
{
    // static mutable
    static inline ...

    // static const
    static inline const ...

    // non-static const
    const ...
};
```

```cpp
#include <iostream>

struct Static
{
    // static mutable
    static inline std::string mutable_str{"static mutable str"};

    // static const
    static inline const int const_int = 11;
    static constexpr    int constexpr_int = 11 * 2;

    // static const (heap allocated)
    static inline const std::string const_str{"static const str"};
    /* DON'T
    static constexpr    std::string constexpr_str{"static constexpr str"}; */

    // static const (cstr for string constants)
    static inline const auto const_cstr = "static const cstr";
    static constexpr    auto constexpr_cstr = "static constexpr cstr";
};

struct NonStatic
{
    // non-static mutable
    std::string mutable_str{"non-static mutable str"};

    // non-static const
    const std::string const_str{"non-static const str"};

    NonStatic() = default;
    NonStatic(std::string addition):
        mutable_str(std::string("non-static mutable str (") + addition + ")"),
        const_str(std::string("non-static const str (") + addition + ")")
        {};
};

int main()
{
    auto print = [](const auto& val) { std::cout << "[" << val << "]" << std::endl; };

    Static::mutable_str += " + mod";

    print(Static::mutable_str);
    print(Static::const_int);
    print(Static::constexpr_int);
    print(Static::const_str);
    print(Static::const_cstr);
    print(Static::constexpr_cstr);

    std::cout << std::endl;

    Static static_inst{};
    print(static_inst.mutable_str);
    print(static_inst.const_int);
    print(static_inst.constexpr_int);
    print(static_inst.const_str);
    print(static_inst.const_cstr);
    print(static_inst.constexpr_cstr);

    std::cout << std::endl;

    NonStatic non_static{};
    non_static.mutable_str += " + mod";
    print(non_static.mutable_str);
    print(non_static.const_str);

    std::cout << std::endl;

    NonStatic non_static_custom{"custom"};
    non_static_custom.mutable_str += " + mod";
    print(non_static_custom.mutable_str);
    print(non_static_custom.const_str);
}
```
</details>

<details>
<summary>Virtual</summary>

```cpp
struct A
{
    virtual void foo() = 0;
    virtual ~A() = default;
};

struct B : A
{
    void foo() override;
    ~B() override;
};

struct C final : B
{
    void foo() final;
    ~C() final;
};
```
</details>

## Function

<details>
<summary>Apply</summary>

```cpp
#include <iostream>
#include <tuple>
 
int sum(int a, int b, int c)
{ 
    return a + b + c; 
}

int main()
{
    std::tuple numbers{1, 2, 3};
    std::cout << std::apply(sum, numbers) << std::endl;
}
```
</details>

## Lambda

<details>
<summary>Generalized capture</summary>

[(StackOverflow) What is a generalized lambda capture and why was it created?](https://stackoverflow.com/questions/41519450/what-is-a-generalized-lambda-capture-and-why-was-it-created/41520537#41520537)

```cpp
p_nums = std::make_unique<std::vector<int>>(nums);
auto lam = [ptr=std::move(p_nums)]() { /* use ptr */ };
```

```cpp
auto lam = [i=0](const std::string &s) mutable
{
    return std::to_string(i++) + ":" + s;
};

std::cout << lam("aaa") << std::endl;  // 0:aaa
std::cout << lam("bbb") << std::endl;  // 1:bbb
std::cout << lam("ccc") << std::endl;  // 2:ccc
```
</details>

## Math

<details>
<summary>Clamp</summary>

```cpp
#include <algorithm>
#include <iostream>

int main()
{
    std::cout << std::clamp(0.5, 1.0, 2.0) << std::endl;  // 1
    std::cout << std::clamp(1.5, 1.0, 2.0) << std::endl;  // 1.5
    std::cout << std::clamp(2.5, 1.0, 2.0) << std::endl;  // 2
}
```
</details>

## Namespace

<details>
<summary>Namespace alias</summary>

```cpp
namespace fbz = foo::bar::baz;
```
</details>

<details>
<summary>Nested namespace</summary>

```cpp
namespace A::B::C
{
   // ...
}
```
</details>

<details>
<summary>Using namespace</summary>

[(Reference) Using namespace](https://en.cppreference.com/w/cpp/language/namespace#Using-directives)

```cpp
namespace A {...}
 
namespace B
{
    using namespace A;
}
```
</details>

## Statement with initializer

<details>
<summary>If statement with initializer</summary>

[(Article) C++17 If statement with initializer](https://skebanga.github.io/if-with-initializer/)

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

<details>
<summary>Range-based for loop with initializer (C++20)</summary>

```cpp
for (init; decl : expr)
```

```cpp
for (size_t i = 0; const auto& x : container)
{
    std::cout << i++ << ": " << x << std::endl;
}
```

```cpp
for (auto& x : foo().items()) {...}  // undefined behavior if foo() returns by value
for (T thing = foo(); auto& x : thing.items()) {...}  // OK
```
</details>

## Structured Binding

<details>
<summary>Syntax</summary>

[(Reference) Structured binding](https://en.cppreference.com/w/cpp/language/structured_binding)

```cpp
auto [a, b, c] =
const auto [a, b, c] =

auto& [a, b, c] =
const auto& [a, b, c] =

auto&& [a, b, c] =
```

```cpp
auto [_, b, c] =
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

## Type

<details>
<summary>Type alias</summary>

[(Reference) Type alias](https://en.cppreference.com/w/cpp/language/type_alias)

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
<summary>Show "auto" type deduction</summary>

[(StackOverflow) Using 'auto' type deduction - how to find out what type the compiler deduced?](https://stackoverflow.com/questions/38820579/using-auto-type-deduction-how-to-find-out-what-type-the-compiler-deduced)

```cpp
struct {} bad = 123;
```
</details>
