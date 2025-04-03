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

:arrow_forward:[**Run**](https://godbolt.org/z/MEdMY1b9e)

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
<summary>Template constructors/methods</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/WdTab8MeT)

```cpp
#include <iostream>
#include <utility>

template<typename T>
class TestClass1
{
public:
    TestClass1(const T& x) : x_{x}
    {
        std::cout << "TestClass1 [const T&]" << std::endl;
    }

    // SURPRISE
    // Catches only rvalues
    // T&& is rvalue ref of type T (not forwarding/universal ref)
    // Both std::move and std::forward are acceptable
    TestClass1(T&& x) : x_{std::forward<T>(x)}
    {
        std::cout << "TestClass1 [T&&]";
        std::cout << (std::is_rvalue_reference<decltype(x)>::value ? " rvalue_ref" : "");
        std::cout << std::endl;
    }

    T x_;
};

template<typename T>
class TestClass2
{
public:
    TestClass2(auto&& x) : x_{std::forward<decltype(x)>(x)}
    {
        std::cout << "TestClass2 [T&&]";
        std::cout << (std::is_rvalue_reference<decltype(x)>::value ? " rvalue_ref" : "");
        std::cout << std::endl;
    }

    T x_;
};

int main()
{
    double val = 0.0;

    TestClass1{val};
    TestClass1{0.0};

    std::cout << std::endl;

    TestClass2<double>{val};
    TestClass2<double>{0.0};
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

## Debug

<details>
<summary>Object Watcher</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/9Kr9a6YWY)

```cpp
#include <atomic>
#include <iostream>

class ObjWatcher
{
public:
    ObjWatcher() : index_(++counter_)
    {
        std::cout << "ObjWatcher: created (" << index_ << ")" << std::endl;
    };

    ObjWatcher(const ObjWatcher& other) : index_(++counter_)
    {
        std::cout << "ObjWatcher: created (" << index_ << ") copy from (" << other.index_ << ")" << std::endl;
    };

    ObjWatcher(ObjWatcher&& other) : index_(++counter_)
    {
        other.moved_ = true;
        std::cout << "ObjWatcher: created (" << index_ << ") move from (" << other.index_ << ")" << std::endl;
    };

    ObjWatcher& operator=(const ObjWatcher& other)
    {
        moved_ = false;
        std::cout << "ObjWatcher: (" << index_ << ") copy assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    };

    ObjWatcher& operator=(ObjWatcher&& other)
    {
        moved_ = false;
        other.moved_ = true;
        std::cout << "ObjWatcher: (" << index_ << ") move assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    };

    virtual ~ObjWatcher()
    {
        std::cout << "ObjWatcher: destroyed (" << index_ << ")";
        if (moved_) std::cout << " [moved]";
        std::cout << std::endl;
    };

private:
    static inline std::atomic<size_t> counter_ = 0;
    size_t index_;
    bool moved_ = false;
};
```

Demo:
```cpp
#include <iostream>

int main()
{
    std::cout << "--- ctor ---" << std::endl;
    ObjWatcher A;

    std::cout << "--- copy ctor ---" << std::endl;
    ObjWatcher B = A;

    std::cout << "--- copy assignement ---" << std::endl;
    ObjWatcher C;
    C = A;

    std::cout << "--- move ctor ---" << std::endl;
    ObjWatcher D = std::move(A);

    std::cout << "--- move assignement ---" << std::endl;
    ObjWatcher E;
    E = std::move(B);

    std::cout << "--- end ---" << std::endl;
}
```
</details>

## Functional

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

<details>
<summary>Function object</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/TbKEG4fr9)

```cpp
#include <iostream>

struct compare_fn
{
    constexpr bool operator()(const int& a, const int& b) const
    {
        return a < b;
    }
};

inline constexpr compare_fn compare{};

int main()
{
    std::cout << compare(1, 2) << std::endl;
    std::cout << compare(2, 2) << std::endl;
    std::cout << compare(3, 2) << std::endl;
}
```
</details>

<details>
<summary>Projection</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/bWYxcbKb8)

```cpp
#include <functional>
#include <iostream>
#include <vector>

struct S
{
    std::string name;
    double a = 0.0;
    double b = 0.0;

    double area() const { return a * b; }
};

// const Proj&  proj: NO (doesn't accept mutable lambdas)
//       Proj&  proj: NO (doesn't accept rvalue refs)
//       Proj&& proj: OK
//       Proj   proj: OK
template<typename T, typename Proj = std::identity>
void print_range_with_proj(const T& range, Proj&& proj = {})
{
    std::cout << "---------------" << std::endl;
    for(const auto& x : range)
    {
        std::cout << std::invoke(proj, x) << std::endl;
    }
};

int main()
{
    std::vector<S> v1
    {
        {"bbb", 1.0, 2.0},
        {"aaa", 11.0, 220.0},
        {"ccc", 12.0, 22.0}
    };

    print_range_with_proj(v1, &S::name);
    print_range_with_proj(v1, &S::area);
    print_range_with_proj(v1, [](const auto& s) { return s.a + s.b; });

    std::vector<std::string> v2
    {
        "xxx",
        "yyyyy",
        "z"
    };

    print_range_with_proj(v2);
    print_range_with_proj(v2, &std::string::length);
}
```
</details>

## Initialization

<details>
<summary>Statement with initializer: if</summary>

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
<summary>Statement with initializer: range-based for (C++20)</summary>

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

<details>
<summary>Structured Binding</summary>

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

Unpack tuple:
```cpp
#include <tuple>

std::tuple tuple{1, 'a', 2.3};

auto [a, b, c] = tuple;
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
```

Unpack map:
```cpp
#include <map>

for (const auto& [k, v] : mymap) {...}

for (auto&& [k, v] : std::map<std::string, int>{{"hello", 1}, {"world", 2}}) {...}
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

## Operators

<details>
<summary>ostream <<</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/EqjfMKhav)

```cpp
#include <iostream>

// ----------------------------------------------------------------------------------------------

struct Person
{
    std::string firstname;
    std::string surname;
    int year;
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    return os << person.surname << " " << person.firstname << " was born in " << person.year;
}

// ----------------------------------------------------------------------------------------------

class PrivatePerson
{
private:
    std::string alias_;
    int year_;

public:
    PrivatePerson(const std::string& alias, int year) : alias_{alias}, year_{year} {};

    friend std::ostream& operator<<(std::ostream& os, const PrivatePerson& person);
};

std::ostream& operator<<(std::ostream& os, const PrivatePerson& person)
{
    return os << person.alias_ << " was born in " << person.year_;
}

// ----------------------------------------------------------------------------------------------

int main()
{
    std::cout << Person{"Smith", "John", 1980} << std::endl;
    std::cout << PrivatePerson{"Private", 1990} << std::endl;
}
```
</details>

<details>
<summary>Ternary conditional operator</summary>

```cpp
condition ? true_expression : false_expression
```
</details>

## String

<details>
<summary>String builder</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/fYsc3b4nn)

```cpp
#include <iostream>
#include <sstream>

void build_string_1()
{
    std::ostringstream ss;

    ss << "Hello";
    ss << " from";
    ss << " string builder 1";

    std::string res1 = ss.str();
    std::string res2 = std::move(ss).str();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
}

void build_string_2()
{
    std::string res;

    res.reserve(100);  // optional

    res += "Hello";
    res += " from";
    res += " string builder 2";

    std::cout << res << std::endl;
}

int main()
{
    build_string_1();
    build_string_2();
}
```
</details>

## Type

<details>
<summary>Rvalue/universal references (test)</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/bh93hs3z4)

```cpp
#include <iostream>

using namespace std;

#define IS_RVALUE(x) (std::is_rvalue_reference<decltype(x)>::value ? " (rvalue)" : "")

// ----------------------------------------------------------------------------------------------

template<typename T>
void bar_t(const T& v) { cout << "const T&" << endl; }

template<typename T>
void bar_t(T& v) { cout << "T&" << endl; }

template<typename T>
void bar_t(T&& v) { cout << "T&&" << IS_RVALUE(v) << endl; }

template<typename T>
void foo_t(T&& p)
{
    cout << "> foo_t" << IS_RVALUE(p) << endl;

    bar_t(p);
    bar_t(std::move(p));
    bar_t(std::forward<T>(p));

    cout << endl;
}

// ----------------------------------------------------------------------------------------------

void bar(const int& v) { cout << "const int&" << endl; }

void bar(int& v) { cout << "int&" << endl; }

void bar(int&& v) { cout << "int&&" << IS_RVALUE(v) << endl; }

template<typename T>
void foo(T&& p)
{
    cout << "> foo" << IS_RVALUE(p) << endl;

    bar(p);
    bar(std::move(p));
    bar(std::forward<T>(p));

    cout << endl;
}

// ----------------------------------------------------------------------------------------------

int main()
{
    int i = 0;

    foo_t(i);
    foo_t(0);

    foo(i);
    foo(0);
}
```
</details>

<details>
<summary>Scope guard</summary>

:arrow_forward:[**Run**](https://godbolt.org/z/37ac48jbG)

```cpp
#include <utility>

template<typename F>
class ScopeGuard
{
public:
    [[nodiscard]] explicit ScopeGuard(const F& f) noexcept : f_{f} {}
    [[nodiscard]] explicit ScopeGuard(F&& f) noexcept : f_{std::forward<F>(f)} {}

    ~ScopeGuard() noexcept { if (invoke_) f_(); }

    ScopeGuard(ScopeGuard&& other) noexcept
        : f_(std::move(other.f_)), invoke_(std::exchange(other.invoke_, false))
    {}

    ScopeGuard(const ScopeGuard&) = delete;
    void operator=(const ScopeGuard&) = delete;
    void operator=(ScopeGuard&&) = delete;

    void dismiss() noexcept { invoke_ = false; }

private:
    F f_;
    bool invoke_ = true;
};

template<typename F>
[[nodiscard]] ScopeGuard<F> make_scope_guard(F&& f) noexcept
{
    return ScopeGuard<std::decay_t<F>>{std::forward<F>(f)};
}
```

Demo:
```cpp
#include <iostream>

int main()
{
    std::string resource = "resource";
    auto _ = ScopeGuard([&]() { std::cout << "guard1: " << resource << std::endl; });

    auto guard2 = make_scope_guard([]() { std::cout << "guard2" << std::endl; });

    auto guard3 = make_scope_guard([]() { std::cout << "guard3" << std::endl; });
    guard3.dismiss();

    std::cout << "--- scope out ---" << std::endl;
}
```
</details>

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
<summary>Type deduction (output)</summary>

[(StackOverflow) Using 'auto' type deduction - how to find out what type the compiler deduced?](https://stackoverflow.com/questions/38820579/using-auto-type-deduction-how-to-find-out-what-type-the-compiler-deduced)

```cpp
struct {} _ = ...
```
</details>
