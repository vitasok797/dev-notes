# C++ / Guidelines

## Class

<details>
<summary>Class: guide</summary>

#### Prototype

```cpp
class MyClass [final]
{
public:
    // Types and type aliases
    // Static constants

    // Factory functions

    // Constructors
    // Special member functions:
    //   - copy constructor
    //   - copy assignment operator
    //   - move constructor
    //   - move assignment operator
    //   - destructor

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

#### Constructors

```cpp
    [explicit] MyClass() = default;
```

```cpp
    [explicit] MyClass() { }
```

#### Special member functions (rule of five/zero)

```cpp
    MyClass(const MyClass&) = default;
    MyClass& operator=(const MyClass&) = default;
    MyClass(MyClass&&) noexcept = default;
    MyClass& operator=(MyClass&&) noexcept = default;
    [virtual] ~MyClass() = default;
```

```cpp
    MyClass(const MyClass& other) { }
    MyClass& operator=(const MyClass& other) { return *this; }
    MyClass(MyClass&& other) noexcept { }
    MyClass& operator=(MyClass&& other) noexcept { return *this; }
    [virtual] ~MyClass() noexcept { }
```

```cpp
    MyClass(const MyClass&);
    MyClass& operator=(const MyClass&);
    MyClass(MyClass&&) noexcept;
    MyClass& operator=(MyClass&&) noexcept;
    [virtual] ~MyClass() noexcept;

[inline] MyClass::MyClass(const MyClass& other) { }
[inline] MyClass& MyClass::operator=(const MyClass& other) { return *this; }
[inline] MyClass::MyClass(MyClass&& other) noexcept { }
[inline] MyClass& MyClass::operator=(MyClass&& other) noexcept { return *this; }
[inline] MyClass::~MyClass() noexcept { }
```

👉 Make user-defined/default move operations `noexcept` ([C.66](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c66-make-move-operations-noexcept)) \
👉 Make user-defined destructors `noexcept` ([C.37](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c37-make-destructors-noexcept))

#### Member functions syntax

```cpp
[virtual] [static/inline] [constexpr] auto member_func() [const] [&/&&] [noexcept] [-> TYPE] [override/final]
```

#### Specifiers: virtual/override/final

```cpp
struct A
{
    virtual ~A() = default;
    virtual auto foo() -> void = 0;
};

struct B : A
{
    ~B() noexcept override;
    auto foo() -> void override;
};

struct C final : B
{
    ~C() noexcept final;
    auto foo() -> void final;
};
```

#### Class types

| Inheritance | Polymorphic<br>usage | Type | Class options |
|:---:|:---:|:---:|---|
|||| • `final` class<br>• rule of five/zero |
| ✔️ || Abstract | • destructor: `virtual ~MyClass() = 0;`<br>• destructor body: `inline MyClass::~MyClass() {}` |
| ✔️ || Concrete | • (optional) `final` class<br>• rule of five/zero |
| ✔️ | ✔️ | Interface | • destructor: `virtual ~MyClass() = default;` |
| ✔️ | ✔️ | Abstract | • destructor:<br>&nbsp;&nbsp;&nbsp;&nbsp;- base: `virtual ~MyClass() = 0;`<br>&nbsp;&nbsp;&nbsp;&nbsp;- derived (intermediate): `~MyClass() override = 0;`<br>• destructor body: `inline MyClass::~MyClass() {}` |
| ✔️ | ✔️ | Concrete<br>(base) | • destructor: `virtual`, user-defined/`default`<br>• rule of five (user-defined/`default`)<br>• risk of slicing ([C.67](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c67-a-polymorphic-class-should-suppress-public-copymove)) |
| ✔️ | ✔️ | Concrete<br>(derived) | • (optional) `final` class<br>• rule of five/zero (mark destructor as `override`/`final`) |

</details>

<details>
<summary>Class: abstract</summary>

#### Prototype

```cpp
class AbstractBase
{
public:
    virtual ~AbstractBase() = 0;

    virtual auto func() [const] [&/&&] [noexcept] -> TYPE = 0;  // pure virtual
    virtual auto func() [const] [&/&&] [noexcept] -> TYPE { }   // virtual
    auto func() [const] [&/&&] [noexcept] [-> TYPE] { }         // non virtual
};

inline AbstractBase::~AbstractBase() {}
```

```cpp
class Derived [final] : public AbstractBase
{
public:
    auto func() [const] [&/&&] [noexcept] -> TYPE override/final { }  // overriden virtual
    auto func() [const] [&/&&] [noexcept] [-> TYPE] { }               // non virtual
};
```

▶️[**Demo**](https://godbolt.org/z/jM6ddTdnf)

</details>

<details>
<summary>Class: interface</summary>

#### Prototype

```cpp
class ITest
{
public:
    virtual auto func() [const] [&/&&] [noexcept] -> TYPE = 0;
    virtual ~ITest() = default;
};
```

```cpp
class Test [final] : public ITest
{
public:
    auto func() [const] [&/&&] [noexcept] -> TYPE override/final { }  // overriden virtual
    auto func() [const] [&/&&] [noexcept] [-> TYPE] { }               // non virtual
};
```

▶️[**Demo**](https://godbolt.org/z/hEhsjsjn3)

</details>

<details>
<summary>Class: polymorphism</summary>

```cpp
class Base
{
public:
    virtual auto run() const -> void = 0;
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    auto run() const -> void override {...}
};

auto polymorphic_call(const Base& base) -> void {...}
auto polymorphic_call(const Base* base) -> void {...}
auto polymorphic_call(std::shared_ptr<Base> base) -> void {...}

auto ref_and_ptr() -> void
{
    auto derived = Derived{};
    Base& base_ref = derived;
    Base* base_ptr = &derived;
}

auto shared_ptr() -> void
{
    // create
    auto base_shared_ptr = std::shared_ptr<Base>{ std::make_shared<Derived>() };

    // cast
    auto base_shared_ptr = std::static_pointer_cast<Base>(derived_shared_ptr);

    // return
    auto return_base_shared_ptr = []() -> std::shared_ptr<Base> { return std::make_shared<Derived>(); };

    // call
    func(*base_shared_ptr);       // (const Base&)
    func(base_shared_ptr.get());  // (const Base*)
    func(base_shared_ptr);        // (std::shared_ptr<Base>)
}

auto unique_ptr() -> void
{
    // create
    auto base_unique_ptr = std::unique_ptr<Base>{ std::make_unique<Derived>() };

    // return
    auto return_base_unique_ptr = []() -> std::unique_ptr<Base> { return std::make_unique<Derived>(); };

    // call
    func(*base_unique_ptr);       // (const Base&)
    func(base_unique_ptr.get());  // (const Base*)
}

auto vector_of_unique_ptr() -> void
{
    auto v = std::vector<std::unique_ptr<Base>>{};
    v.push_back(std::make_unique<Derived>());
}
```

▶️[**Demo**](https://godbolt.org/z/zKv78hE71)

</details>

<details>
<summary>Class: static/const fields</summary>

#### Summary

```cpp
struct Summary
{
    // static mutable
    static inline ...

    // static const
    static inline const ...

    // non-static const (implicitly deletes assignment operators)
    const ...
};
```

#### Full

```cpp
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

    // non-static const (implicitly deletes assignment operators)
    const std::string const_str{"non-static const str"};
};
```

▶️[**Demo**](https://godbolt.org/z/8q7fT4YcT)

</details>

<details>
<summary>Constructors: default arguments</summary>

```cpp
#include <string>

class Employee
{
public:
    Employee(const std::string& name, int id = default_id) :
        name_{name},
        id_{id}
    {}

private:
    static constexpr int default_id = 0;

    std::string name_;
    int id_ = default_id;
};
```

</details>

<details>
<summary>Constructors: forward</summary>

▶️[**Run**](https://godbolt.org/z/PT33TvsbP)

```cpp
#include <iostream>
#include <utility>

class Base
{
public:
    Base()
    {
        std::cout << "Ctor: default" << std::endl;
    }

    Base(int)
    {
        std::cout << "Ctor: (int)" << std::endl;
    }

    Base(int, int)
    {
        std::cout << "Ctor: (int, int)" << std::endl;
    }
};

class Derived: public Base
{
public:
    template<typename... Args>
    Derived(Args&&... args) : Base(std::forward<Args>(args)...)
    {
        std::cout << "Additional initialization" << std::endl;
    }
};

auto main() -> int
{
    Derived{};

    std::cout << std::endl;

    Derived{1};

    std::cout << std::endl;

    Derived{1, 2};
}
```

</details>

<details>
<summary>Constructors: import from base classes</summary>

```cpp
struct A
{
    explicit A(int x) {}
};

class B: public A
{
    using A::A;
};
```

```cpp
#include <vector>

template<typename T>
class my_vector : public std::vector<T>
{
public:
    using std::vector<T>::std::vector;  // Takes all vector's constructors
};
```

</details>

<details>
<summary>Initialization/destruction order</summary>

▶️[**Demo** (Constructors/destructors)](https://godbolt.org/z/v7KeTh3xY) \
▶️[**Demo** (Members)](https://godbolt.org/z/3er9ehrYc)

</details>

<details>
<summary>Template class constructors/methods with T&& args</summary>

▶️[**Run**](https://godbolt.org/z/Kd6Kerd49) [[debug.h](vsl/debug.h)]

```cpp
#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/languages/cpp/vsl/debug.h>

#include <iostream>
#include <utility>

using std::cout, std::endl;

using Watcher = vsl::debug::CtorWatcher;

template<typename T>
struct Test1
{
    Test1(const T& x) : x_{x}
    {
        cout << "Test1 [const T&]" << endl;
    }

    // Catches only rvalues
    // T&& is rvalue ref of type T (not a forwarding ref)
    // So we need additional TestClass1(const T&) constructor
    // Note: both std::move and std::forward are acceptable
    Test1(T&& x) : x_{std::forward<T>(x)}
    {
        cout << "Test1 [T&&]";
        cout << (std::is_rvalue_reference_v<decltype(x)> ? " rvalue_ref" : "");
        cout << endl;
    }

    T x_;
};

template<typename T>
struct Test2
{
    Test2(T x) : x_{std::move(x)}
    {
        cout << "Test2 [T]" << endl;
    }

    T x_;
};

template<typename T>
struct Test3
{
    Test3(auto&& x) : x_{std::forward<decltype(x)>(x)}
    {
        cout << "Test3 [T&&]";
        cout << (std::is_rvalue_reference_v<decltype(x)> ? " rvalue_ref" : "");
        cout << endl;
    }

    T x_;
};

auto lf() -> void { cout << endl; }

auto test1() -> void
{
    auto w = Watcher{};
    Test1{w};
    lf();

    Test1{Watcher{}};
    lf();
}

auto test2() -> void
{
    auto w = Watcher{};
    Test2{w};
    lf();

    Test2{Watcher{}};
    lf();
}

auto test3() -> void
{
    auto w = Watcher{};
    Test3<Watcher>{w};
    lf();

    Test3<Watcher>{Watcher{}};
    lf();
}

auto main() -> int
{
    test1();
    test2();
    test3();
}
```

</details>

## Debug

<details>
<summary>DebugAllocator</summary>

▶️[**Demo**](https://godbolt.org/z/rfqfebqcM) [[debug.h](vsl/debug.h)]

</details>

<details>
<summary>Display type</summary>

[(StackOverflow) Using 'auto' type deduction - how to find out what type the compiler deduced?](https://stackoverflow.com/questions/38820579/using-auto-type-deduction-how-to-find-out-what-type-the-compiler-deduced)

```cpp
struct {} _ =
```

```cpp
template<typename...> class TD;

TD<T> _;
TD<decltype(x)> _;
```

</details>

<details>
<summary>Type info (overload resolution test)</summary>

▶️[**Demo** (overload resolution test)](https://godbolt.org/z/jc3dEabEv) [[debug.h](vsl/debug.h)]

</details>

<details>
<summary>Watchers</summary>

▶️[**Demo**](https://godbolt.org/z/WPKfsEq98) [[debug.h](vsl/debug.h)]

</details>

## Error handling

<details>
<summary>Assert</summary>

▶️[**Demo**](https://godbolt.org/z/TaarEqG5s) [[assert.h](vsl/assert.h)]

</details>

<details>
<summary>Pointers dereference</summary>

#### Check and deref

```cpp
// classic check
if (shared_ptr)
{
    // use *shared_ptr
    // pass_by_const_ref(*shared_ptr)
    // pass_by_ref(*shared_ptr)
}
```

```cpp
#include <vsl/error.h>

vsl::check_ptr(shared_ptr);

// use *shared_ptr
// pass_by_const_ref(*shared_ptr)
// pass_by_ref(*shared_ptr)
```

```cpp
#include <vsl/error.h>

auto[&] value = vsl::checked_deref_ptr(shared_ptr);

// use value
// pass_by_const_ref(value)
// pass_by_ref(value)
```

```cpp
#include <vsl/error.h>

class SomeClass
{
public:
    SomeClass(std::unique_ptr<int> uptr) :
        uptr_{std::move(uptr)}
    {}

    auto get_value() const & -> int&
    {
        return vsl::checked_deref_ptr(uptr_);
    }

    auto get_value() const && = delete;

private:
   std::unique_ptr<int> uptr_;
};
```

#### Check and get raw pointer

```cpp
#include <vsl/error.h>

auto non_optional_raw_ptr = vsl::checked_get_ptr(shared_ptr);

// pass_by_const_raw_ptr(non_optional_raw_ptr)
```

▶️[**Demo**](https://godbolt.org/z/hnWYMbqY4) [[error.h](vsl/error.h)]

</details>

## Errors (typical)

<details>
<summary>🚧 Dangling references</summary>

#### Range-based for

```cpp
for (const auto& el : get_struct().items()) {...}  // undefined behavior if:
                                                   //   - get_struct() returns by value
                                                   //   - items() returns by ref
```

How to avoid the *range-based for* [issue](https://pvs-studio.com/en/blog/posts/cpp/1149/#ID313A10ACA8):
* Never use any expression after a colon (:) in the loop header. Use only variables or its fields
* In C++20, use the range-based for syntax with the initializer: for (auto cont = expr; auto x : cont)
* Use std::ranges::for_each
* ❓ Never forget to do the rvalue overload for any const methods

```cpp
for (const auto& s = get_struct(); const auto& el : s.items()) { func(el); }  // OK
```

```cpp
ranges::for_each(get_struct().items(), func);  // OK
```

#### Structured binding

🚧

#### Complex demo

▶️[**Demo**](https://godbolt.org/z/1qbb17q6c)

</details>

<details>
<summary>"Far" objects forwarding</summary>

```cpp
#include <vsl/util.h>

template<typename T>
auto func(T&& range) -> void
{
    for (auto& el : range)
    {
        vec.push_back(vsl::forward_like<T>(el));
    }
}
```

```cpp
#include <vsl/util.h>

template<typename T>
auto func(T&& tuple) -> void
{
    auto& [el, _] = tuple;
    vec.push_back(vsl::forward_like<T>(el));
}
```

```cpp
#include <vsl/util.h>

template<typename T>
auto func(T&& cont) -> void
{
    vec.push_back(vsl::forward_like<T>(cont.at(0)));
}
```

```cpp
#include <vsl/util.h>

template<typename T>
auto func(T&& some_struct) -> void
{
    vec.push_back(FWD(some_struct).member);
}

template<typename T>
auto func(T&& some_struct) -> void
{
    auto& [member, _] = some_struct;
    vec.push_back(vsl::forward_like<T>(member));
}
```

▶️[**Demo**](https://godbolt.org/z/nrcjnxaqo) [[util.h](vsl/util.h)]

</details>

## Functions

<details>
<summary>🚧 Decorators</summary>

[C++ Python-like Decorators](https://github.com/TheMaverickProgrammer/C-Python-like-Decorators) \
[C++ Python-like Class Member Decorators](https://github.com/TheMaverickProgrammer/C-Python-Like-Class-Member-Decorators) \
[(reddit) Python function decorators in modern C++ (without magic macros)](https://www.reddit.com/r/cpp/comments/cm2g4l/python_function_decorators_in_modern_c_without/)

▶️[**Demo**](https://godbolt.org/z/4oc67ech1) [[util.h](vsl/util.h)]

</details>

<details>
<summary>Dispatch table</summary>

▶️[**Run**](https://godbolt.org/z/1eaK9Kaj1)

```cpp
#include <functional>
#include <iostream>
#include <map>

auto add(double a, double b) -> double
{
    return a + b;
}

struct Sub
{
    auto operator()(double a, double b) const -> double
    {
        return a - b;
    }
};

auto mult_three(double a, double b, double c) -> double
{
    return a * b * c;
}

auto main() -> int
{
    using namespace std::placeholders;

    auto disp_table = std::map<const char, std::function<double(double, double)>>
    {
        {'+', add},
        {'-', Sub{}},
        {'*', std::bind(mult_three, 1.0, _1, _2)},
        {'/', [](double a, double b) { return a / b; }}
    };

    std::cout << "3.5 + 4.5 = " << disp_table['+'](3.5, 4.5) << std::endl;
    std::cout << "3.5 - 4.5 = " << disp_table['-'](3.5, 4.5) << std::endl;
    std::cout << "3.5 * 4.5 = " << disp_table['*'](3.5, 4.5) << std::endl;
    std::cout << "3.5 / 4.5 = " << disp_table['/'](3.5, 4.5) << std::endl;
}
```

</details>

<details>
<summary>Function alias</summary>

▶️[**Run**](https://godbolt.org/z/GrWjhYj48)

```cpp
#include <iostream>

namespace other_lib
{
auto target_func() -> void { std::cout << "target_func" << std::endl; }
}

namespace my_lib
{
inline constexpr auto func = other_lib::target_func;
using other_lib::target_func;
}

auto main() -> int
{
    my_lib::func();
    my_lib::target_func();
}
```

</details>

<details>
<summary>Function object</summary>

▶️[**Run**](https://godbolt.org/z/Wzeesaq73)

```cpp
#include <iostream>

struct Compare
{
    constexpr auto operator()(const auto& a, const auto& b) const -> bool
    {
        return a == b;
    }
};

struct PrintValue
{
    auto operator()(int val) const -> void { std::cout << "int: " << val << std::endl; }
    auto operator()(double val) const -> void { std::cout << "double: " << val << std::endl; }
};

inline constexpr auto compare = Compare{};

auto main() -> int
{
    std::cout << compare(1, 2) << std::endl;
    std::cout << compare(2, 2) << std::endl;
    std::cout << compare(3, 2) << std::endl;

    std::cout << std::endl;

    auto printer = PrintValue{};
    printer(1);
    printer(1.0);
}
```

</details>

<details>
<summary>Lambda generalized capture</summary>

[(StackOverflow) What is a generalized lambda capture and why was it created?](https://stackoverflow.com/questions/41519450/what-is-a-generalized-lambda-capture-and-why-was-it-created/41520537#41520537)

```cpp
auto p_nums = std::make_unique<std::vector<int>>(nums);
auto lam = [p_nums=std::move(p_nums)]() { /* use p_nums */ };
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

<details>
<summary>Projection</summary>

▶️[**Run**](https://godbolt.org/z/K3Pj67Ybf)

```cpp
#include <functional>
#include <iostream>
#include <vector>

struct Rect
{
    std::string name;
    double a = 0.0;
    double b = 0.0;

    auto area() const -> double { return a * b; }
};

template<typename R, typename P = std::identity>
auto print_range_with_proj(const R& range, P proj = {}) -> void
{
    std::cout << "---------------" << std::endl;
    for (const auto& x : range)
    {
        std::cout << std::invoke(proj, x) << std::endl;
    }
};

auto main() -> int
{
    auto v1 = std::vector<Rect>
    {
        {"bbb", 1.0, 2.0},
        {"aaa", 11.0, 220.0},
        {"ccc", 12.0, 22.0}
    };

    print_range_with_proj(v1, &Rect::name);
    print_range_with_proj(v1, &Rect::area);
    print_range_with_proj(v1, [](const Rect& rect) { return rect.a + rect.b; });

    auto v2 = std::vector<std::string>
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

<details>
<summary>std::apply</summary>

▶️[**Run**](https://godbolt.org/z/3Gs98nrhG)

```cpp
#include <iostream>
#include <tuple>

auto sum(int a, int b, int c) -> int
{
    return a + b + c;
}

auto main() -> int
{
    auto numbers = std::tuple{1, 2, 3};
    std::cout << "apply res: " << std::apply(sum, numbers) << std::endl;
}
```

</details>

<details>
<summary>std::make_from_tuple</summary>

▶️[**Run**](https://godbolt.org/z/5PcK5hev7)

```cpp
#include <iostream>
#include <tuple>

struct Foo
{
    Foo(int first, float second, int third)
    {
        std::cout << "make_from_tuple ctor: ";
        std::cout << first << ", " << second << ", " << third << std::endl;
    }
};

auto main() -> int
{
    auto ctor_args = std::tuple{10, 20.2, 30};
    std::make_from_tuple<Foo>(ctor_args);
}
```

</details>

### Functions / Parameter passing

<details>
<summary>🚧 Parameter passing</summary>

* [Prefer simple and conventional ways of passing information](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f15-prefer-simple-and-conventional-ways-of-passing-information)
* [Language / Types / Passing parameters](cpp-language.md#types--passing-parameters) 🔗

#### Parameters

| Function intent | Value type | Rvalue<br>only | Parameter type | Comment |
|---|---|:---:|:---:|---|
| Read | `CheapToCopyType` || `CheapToCopyType` ||
| Read | `HeavyType` || `const HeavyType&` | See possible optimizations for retaining a rvalue "copy" ([demo](https://godbolt.org/z/r8q6ffoGr))<sup>✱</sup> |
| Read+Write<br>Write | `AnyType` || `AnyType&` | ["Write" only case\] Prefer return values over out parameters ([F.20](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f20-for-out-output-values-prefer-return-values-to-output-parameters)) |
| ***<ins>Optional:</ins>*** |||||
| Read | `CheapToCopyType` || `std::optional<CheapToCopyType>` ||
| Read | `HeavyType` || `const HeavyType*` | No ownership transfer |
| Read+Write<br>Write | `AnyType` || `AnyType*` | No ownership transfer |
| ***<ins>Move only types:</ins>*** |||||
| Steal | `MoveOnlyType` | ✔️ | `MoveOnlyType` | See tiny optimization for xvalues<sup>✱✱</sup> |
| ***<ins>Smart pointers:</ins>*** |||||
| Steal<br>(take ownership) | `std::unique_ptr` | ✔️ | `std::unique_ptr<>` ||
| Share ownership | `std::shared_ptr` || `std::shared_ptr<>` ||
| May share ownership | `std::shared_ptr` || `const std::shared_ptr<>&` | May copy `std::shared_ptr` or create `std::weak_ptr` |
| Reassign pointer | `std::unique_ptr` || `std::unique_ptr<>&` ||
| Reassign pointer | `std::shared_ptr` || `std::shared_ptr<>&` ||
| ***<ins>Optimizations:</ins>*** |||||
| <sup>✱</sup>Read <sub>retain "copy"</sub> | `HeavyType` || `const HeavyType&`<br>`HeavyType&&` | Then `std::move` `HeavyType&&` |
| <sup>✱</sup>Read <sub>retain "copy"</sub> | `HeavyType` || `T&&` | • Then `std::forward`<br>• Some type constraints can be added (see [concepts](https://en.cppreference.com/w/cpp/concepts.html#Core_language_concepts)) |
| <sup>✱</sup>Read <sub>retain "copy"</sub> | `HeavyType` || `HeavyType` | • Then `std::move`<br>• See [by-value-then-move idiom](cpp-language.md#types--passing-parameters-by-value-by-value-then-move-idiom) 🔗<br>• Assumed to be used only for constructors |
| <sup>✱✱</sup>Steal | `MoveOnlyType` | ✔️ | `MoveOnlyType&&` | • Then `std::move`<br>• Removes 1 of 2 move operations for xvalues |

Cheap-to-copy types (≤ 2×sizeof(void\*)):
* Fundamental types (integral, floating-point, bool, etc.)
* Iterators
* View/span types (std::string_view, std::span)
* Small callable objects (functors, lambdas)

From the caller's point of view, the value can be `std::move`-ed if the parameter type is:
* `HeavyType`
* `HeavyType&&`
* `T&&`

#### Returning

* `Polymorphic`, `NonMovable`, `ExpensiveToMove` types factory:
  * Return `std::unique_ptr` to transfer ownership
  * Return `std::shared_ptr` to share ownership
* Optional (if not returning the object can be a normal result):
  * For `CheapToCopyType`: return `std::optional` (`return value;`)
  * For `CheapToMoveType`: return `std::optional` (`return std::move(value);`)
  * Return `T*` to indicate an optional position ([F.42](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f42-return-a-t-to-indicate-a-position-only))
* Return `T&`:
  * When copy is undesirable
  * From assignment operators
  * Pass through reference
* Return by value
</details>

<details>
<summary>Forwarding reference with type constraints</summary>

```cpp
#include <concepts>

template<std::convertible_to<double> T>
auto func(T&& x) -> void {}

template<std::convertible_to<std::string> T>
auto func(T&& x) -> void {}
```

```cpp
#include <vsl/concepts.h>

template<typename T>
requires vsl::same_type_as<T, std::string>
auto func(T&& x) -> void {}
```

▶️[**Demo**](https://godbolt.org/z/nKG1TWb7E) [[concepts.h](vsl/concepts.h), [debug.h](vsl/debug.h)]

</details>

<details>
<summary>Function as argument</summary>

```cpp
//=============================================================================
// Run func
//-----------------------------------------------------------------------------
// template<typename F>
// const F&  f: NO (doesn't accept mutable lambdas/functors)
//       F&  f: NO (doesn't accept rvalues)
//       F&& f: NO (confusing if there is no forwarding)
//       F   f: YES
//=============================================================================
// Store func
//-----------------------------------------------------------------------------
// template<typename F>
// const F&  f: NO
//       F&  f: NO
//       F&& f: YES (pass by forwarding ref, then store by std::forward)
//       F   f: YES (pass by value, then store by std::move)
//=============================================================================
```

```cpp
#include <functional>

auto test(std::function<int(int, int)> f) -> void
{
    int res = f(1, 2);
}
```

```cpp
#include <vsl/concepts.h>

template<typename F>
requires vsl::callable_r<int, F, int, int>
auto test(F f) -> void
{
    int res = f(1, 2);
}
```

▶️[**Demo**](https://godbolt.org/z/r195Y13Tf) [[concepts.h](vsl/concepts.h)]

</details>

<details>
<summary>Named arguments</summary>

#### Using strong_type library

Libs: [strong_type](https://github.com/rollbear/strong_type)

▶️[**Run**](https://godbolt.org/z/6KPs48xGM)

```cpp
#include <strong_type/strong_type.hpp>

#include <iostream>
#include <string>

using FirstName = strong::type<std::string, struct FirstName_tag>;
using LastName = strong::type<std::string, struct LastName_tag>;

auto func(const FirstName& first_name, const LastName& last_name) -> void
{
    std::cout << "First name: " << value_of(first_name) << std::endl;
    std::cout << "Last name: " << value_of(last_name) << std::endl;
}

auto main() -> int
{
    func(FirstName{"John"}, LastName{"Doe"});
}
```

#### Using struct

▶️[**Run**](https://godbolt.org/z/acEG3EPqn)

```cpp
#include <iostream>
#include <string>

struct FirstName { std::string value; };
struct LastName { std::string value; };

auto func(const FirstName& first_name, const LastName& last_name) -> void
{
    std::cout << "First name: " << first_name.value << std::endl;
    std::cout << "Last name: " << last_name.value << std::endl;
}

auto main() -> int
{
    func(FirstName{"John"}, LastName{"Doe"});
    func({"John"}, {"Doe"});  // allows
}
```

#### Using designated initializers

▶️[**Run**](https://godbolt.org/z/ej5Y8nc85)

```cpp
#include <iostream>
#include <string>

struct Name
{
    std::string first_name;
    std::string last_name;
};

auto func(const Name& name) -> void
{
    std::cout << "First name: " << name.first_name << std::endl;
    std::cout << "Last name: " << name.last_name << std::endl;
}

auto main() -> int
{
    func({.first_name = "John", .last_name = "Doe"});
    func({"John", "Doe"});  // allows
}
```

</details>

<details>
<summary>Returning structured data</summary>

```cpp
struct Data { int i; double d; };

auto get_data() -> Data
{
    return {42, 0.1};
    return Data{42, 0.1};
}
```

```cpp
auto get_data()
{
    struct Data { int i; double d; };
    return Data{42, 0.2};
}
```

```cpp
auto get_data() -> std::tuple<int, double>
{
    return {42, 0.3};
}
```

▶️[**Demo**](https://godbolt.org/z/j8dGva4bT)

</details>

## Initialization

<details>
<summary>auto (initialization)</summary>

#### Syntax

```cpp
[static/inline] [const/constexpr] auto[&/&&/*] x = expr;
[static/inline] [const/constexpr] auto[&/&&/*] x = TYPE{expr};
```

```cpp
         auto  x = expr;  // removes cv/ref
decltype(auto) x = expr;  // preserves cv/ref

// "auto" constness removing exceptions
auto& ref =  const_int;  // const int&
auto* ptr = &const_int;  // const int*
auto  ptr = &const_int;  // const int*
```

| Value category | auto&& | decltype(auto) |
|---|---|---|
| lvalue | T& | T |
| lvalue& | T& | T& |
| xvalue | T&& | T&& |
| prvalue | T&& | T |

▶️[**Demo**](https://godbolt.org/z/bcWW1oee7)

#### Examples

```cpp
auto i = int64_t{123};
auto v = std::vector<int>{};
auto get_size = [](const auto& x) { return x.size(); };
```

#### Dynamic memory allocation

```cpp
auto w = new Widget{};
auto w = std::make_unique<Widget>();
```

#### Polymorphic smart pointers

```cpp
auto base_shared_ptr = std::shared_ptr<Base>{ std::make_shared<Derived>() };
auto base_unique_ptr = std::unique_ptr<Base>{ std::make_unique<Derived>() };
```

#### Strings

```cpp
using namespace std::literals;

// const char* x = "hello";
auto x = "hello";

// std::string x = "hello";
auto x = std::string{"hello"};
auto x = "hello"s;

// std::string_view x = "hello";
auto x = std::string_view{"hello"};
auto x = "hello"sv;
```

#### Loop counter

```cpp
#include <vsl/util.h>

for (auto i = size_t{0}; i < v.size(); ++i)
for (auto i = vsl::Index{0}; i < vsl::signed_size(v); ++i)

for (auto i = vsl::signed_size(v)-1; i >= 0; --i)
```

#### Range-based for loops element type

```cpp
for (      auto  x : cont)  // when you want to modify copies of the elements
for (      auto& x : cont)  // when you want to modify the original elements
for (const auto& x : cont)  // otherwise (when you just need to view the original elements)
```

#### Signed/unsigned cast with helpers

```cpp
#include <vsl/util.h>

auto x = vsl::as_signed(integer_expr);
auto x = vsl::as_unsigned(integer_expr);
```

#### Initialization by function return value

```cpp
Gadget get_gadget();

Widget w = get_gadget();  // BAD: implicit conversion Gadget to Widget (creates a temporary)
auto w = get_gadget();  // GOOD: no implicit conversion
auto w = Widget{ get_gadget() };  // GOOD: implicit conversion with intent
```

#### `std::initializer_list` issue

```cpp
auto i = 3;    // int
auto i(3);     // int
auto i{3};     // C++11: std::initializer_list<int>
               // C++14: int (only for single item in list)
auto i = {3};  // C++11: std::initializer_list<int>
               // C++14: std::initializer_list<int>
```

</details>

<details>
<summary>auto (return type)</summary>

#### Trailing return type

```cpp
[static/inline] [constexpr] auto non_member_func() [noexcept] [-> TYPE]
```

```cpp
[virtual] [static/inline] [constexpr] auto member_func() [const] [&/&&] [noexcept] [-> TYPE] [override/final]
```

#### Trailing return type (type deduction)

```cpp
-> [const] auto[&/&&/*]
-> decltype(auto) // preserves cv/ref
```

| Value category | auto&& | decltype(auto) |
|---|---|---|
| lvalue | T& | T |
| lvalue& | T& | T& |
| xvalue | T&& | T&& |
| prvalue | T&& | T |

```cpp
auto func() -> auto
auto func()  // trailing auto can be omitted
```

#### Examples

```cpp
// Simplification
Person::PersonType Person::get_person_type()
auto               Person::get_person_type() -> PersonType
```

</details>

<details>
<summary>Statement with initializer</summary>

#### `if`

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
if (auto [it_elem, success] = mymap.insert(std::pair('a', 100)); success) {...}
```

#### Range-based `for`

```cpp
for (init; decl : expr)
```

```cpp
for (auto i = size_t{}; const auto& x : container)
{
    std::cout << i++ << ": " << x << std::endl;
}
```

```cpp
for (const auto& s = get_struct(); const auto& el : s.items()) {...}
```

</details>

<details>
<summary>🚧 Structured binding</summary>

[(cppreference) Structured binding](https://en.cppreference.com/w/cpp/language/structured_binding.html)

#### Syntax

```cpp
auto [a, b, c] =
const auto [a, b, c] =

auto& [a, b, c] =
const auto& [a, b, c] =
```

```cpp
auto [_, b, c] =
```

#### Unpacking a tuple

```cpp
#include <tuple>

auto tuple = std::tuple{1, 'a', 2.3};

auto [a, b, c] = tuple;
```

#### Unpacking a struct

```cpp
struct Foo
{
    int i;
    char c;
    double d;
};

auto f = Foo{1, 'a', 2.3};

auto [i, c, d] = f;
```

#### Unpacking a map

```cpp
#include <map>

for (const auto& [k, v] : mymap) {...}
```

</details>

## Math

<details>
<summary>Ceil division</summary>

[(StackOverflow) Fast ceiling of an integer division](https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c)

▶️[**Demo**](https://godbolt.org/z/q6nabbb1T) [[math.h](vsl/math.h)]

</details>

<details>
<summary>Floating point comparisons</summary>

[(LearnCpp) Relational operators and floating point comparisons](https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/)

▶️[**Demo**](https://godbolt.org/z/fqxGa71fE) [[math.h](vsl/math.h)]

</details>

<details>
<summary>🚧 Signed/unsigned</summary>

#### Loop counter

```cpp
#include <vsl/util.h>

for (auto i = size_t{0}; i < v.size(); ++i)
for (auto i = vsl::Index{0}; i < vsl::signed_size(v); ++i)

for (auto i = vsl::signed_size(v)-1; i >= 0; --i)
```

#### Demos

▶️[**Demo** (arithmetic)](https://godbolt.org/z/ar9WcvhKd) [[util.h](vsl/util.h)] \
▶️[**Demo** (compare)](https://godbolt.org/z/KbqTq6qK8) [[util.h](vsl/util.h)] \
▶️[**Demo** (index)](https://godbolt.org/z/61bPdacfe) [[util.h](vsl/util.h)] \
▶️[**Demo** (accumulate)](https://godbolt.org/z/bvEd7oMvd) [[util.h](vsl/util.h)]

#### `-Wsign-compare` compiler option

* Enabling:
  * GCC: `-Wsign-compare`, `-Wall`, `-Wextra` ([doc](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html))
  * Clang: `-Wsign-compare`, `-Wextra` ([doc](https://clang.llvm.org/docs/DiagnosticsReference.html))
  * MSVC: `/W3`, `/W4` ([C4018](https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4018)) ([doc](https://learn.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level))
* Cons: false positive for code like `for (auto i = vsl::Index{0}; i < sizeof(buf); i++)`
* Solution:
  * Disable compiler option:
    * GCC/Clang: `-Wno-sign-compare`
    * MSVC: `/wd4018`
  * Enable a similar option in the static analyzer
  * Static analyzer configuration: do not flag on a mixed signed/unsigned comparison where one of the arguments is `sizeof` or a call to container `.size()` and the other is `ptrdiff_t` ([ES.100](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es100-dont-mix-signed-and-unsigned-arithmetic))

#### `-Wtype-limits` compiler option

* Enabling:
  * GCC: `-Wtype-limits`, `-Wextra` ([doc](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html))
  * Clang: `-Wtype-limits` ([doc](https://clang.llvm.org/docs/DiagnosticsReference.html))
  * MSVC: `/W4`+`/w44296` ([C4296](https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4296)) ([doc](https://learn.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level))

</details>

<details>
<summary>Trim</summary>

#### Using vsl::ftrim

▶️[**Run**](https://godbolt.org/z/Eh93397YE) [[math.h](vsl/math.h)]

```cpp
#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/languages/cpp/vsl/math.h>

#include <iostream>

using std::cout, std::endl;

using vsl::ftrim;

auto main() -> int
{
    cout << ftrim(-1.0, {0, 2.0}) << endl;  // 0
    cout << ftrim( 1.0, {0, 2.0}) << endl;  // 1.0
    cout << ftrim( 3.0, {0, 2.0}) << endl;  // 2.0

    cout << endl;

    cout << ftrim( 100.0, {0, INF}) << endl;  // 100.0
    cout << ftrim(-100.0, {0, INF}) << endl;  // 0

    cout << endl;

    cout << ftrim( 100.0, {-INF, 0}) << endl;  // 0
    cout << ftrim(-100.0, {-INF, 0}) << endl;  // -100.0

    cout << endl;

    cout << ftrim(5.0, {1.0, 1.0}) << endl;  // 1.0

    // cout << ftrim(5.0, {1.0, -1.0}) << endl;  // throws logic_error
}
```

#### Using std::clamp

▶️[**Run**](https://godbolt.org/z/sfnYaeE7d)

```cpp
#include <algorithm>
#include <iostream>

auto main() -> int
{
    std::cout << std::clamp(5, 10, 20) << std::endl;  // 10
    std::cout << std::clamp(15, 10, 20) << std::endl;  // 15
    std::cout << std::clamp(25, 10, 20) << std::endl;  // 20
}
```

</details>

## Multithreading

<details>
<summary>std::async</summary>

▶️[**Demo**](https://godbolt.org/z/ceocqE4Mj) [[async.h](vsl/async.h), [debug.h](vsl/debug.h)]

</details>

## Namespace

<details>
<summary>Inline namespace</summary>

```cpp
#include <iostream>

inline namespace V1
{
    auto doSomething() -> void
    {
        std::cout << "V1\n";
    }
}

namespace V2
{
    auto doSomething() -> void
    {
        std::cout << "V2\n";
    }
}

auto main() -> int
{
    V1::doSomething();
    V2::doSomething();

    // calls V1
    doSomething();

    return 0;
}
```

</details>

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

[(cppreference) Using namespace](https://en.cppreference.com/w/cpp/language/namespace.html#Using-directives)

```cpp
namespace A {...}

namespace B
{
    using namespace A;
}
```

</details>

<details>
<summary>Using namespace member</summary>

```cpp
using std::cout;
using std::endl;
```

```cpp
using std::cout, std::endl;
```

</details>

## Operators

<details>
<summary>Operator overloading</summary>

[(cppreference) Operator overloading](https://en.cppreference.com/w/cpp/language/operators.html)

* Use member function:
  * Unary operators
  * Operators that cannot be non-member (`=`, `()`, `[]`, `->`)
  * Binary operator that modifies its left operand (`+=`, `–=`, `/=`, `*=`, etc.)
* Use non-member function (or friend):
  * Binary operator that modifies its left operand, but you can’t add members to the class definition of the left operand (`<<`, etc.)
  * All other binary operators

</details>

<details>
<summary>ostream <<</summary>

```cpp
inline auto operator<<(std::ostream& os, const Person& person) -> std::ostream&
{
    return os << person.surname << " " << person.firstname << " was born in " << person.year;
}
```

```cpp
class PrivatePerson
{
public:
    friend auto operator<<(std::ostream& os, const PrivatePerson& person) -> std::ostream&;
};

inline auto operator<<(std::ostream& os, const PrivatePerson& person) -> std::ostream&
{
    return os << person.alias_ << " was born in " << person.year_;
}
```

```cpp
class PrivatePerson
{
public:
    friend auto operator<<(std::ostream& os, const PrivatePerson& person) -> std::ostream&
    {
        return os << person.alias_ << " was born in " << person.year_;
    }
};
```

▶️[**Demo**](https://godbolt.org/z/fxPqf4GKW)

</details>

<details>
<summary>Ternary conditional operator</summary>

```cpp
condition ? true_expression : false_expression
```

</details>

## Ranges

<details>
<summary>Contains</summary>

```cpp
auto v = std::vector<int>{1, 2, 3};

std::cout << std::boolalpha;

std::cout << ranges::contains(v, 2) << std::endl;
std::cout << ranges::contains(v, 999) << std::endl;
```

</details>

<details>
<summary>Copy to ostream</summary>

▶️[**Run**](https://godbolt.org/z/qxx3rqM1d)

```cpp
#include <range/v3/all.hpp>

#include <iostream>
#include <vector>

auto main() -> int
{
    auto v = std::vector<int>{1, 2, 3};

    // 1
    std::cout << ranges::views::all(v) << std::endl;

    // 2
    ranges::copy(v, ranges::ostream_iterator<int>{std::cout, "\n"});

    // 3
    using T = ranges::range_value_t<decltype(v)>;
    ranges::copy(v, ranges::ostream_iterator<T>{std::cout, "\n"});
}
```

</details>

<details>
<summary>Custom views</summary>

▶️[**Run**](https://godbolt.org/z/YvW3TP1zs)

```cpp
#include <range/v3/all.hpp>

#include <format>
#include <iostream>
#include <vector>

struct Person
{
    std::string firstname;
    std::string surname;
    int year;

    auto to_str() const -> std::string
    {
        return std::format("{} {} was born in {}", surname, firstname, year);
    };
};

auto people_to_str_view()
{
    auto in_quotes = [](const std::string& s) { return std::format("\"{}\"", s); };
    return ranges::views::transform(&Person::to_str) | ranges::views::transform(in_quotes);
}

auto people_to_str_with_tag_view(auto proj)
{
    auto to_str_with_tag = [proj=std::move(proj)](const Person& person) mutable
    {
        auto tag = std::invoke(proj, person);
        return std::format("[{}] {}", tag, person.to_str());
    };
    return ranges::views::transform(to_str_with_tag);
}

auto main() -> int
{
    auto people = std::vector<Person>
    {
        {"Jared", "Kushner", 1981},
        {"Donald", "Trump", 1946},
        {"Melania", "Trump", 1970},
        {"Ivana", "Trump", 1949},
    };

    for (const auto& x : people | people_to_str_view())
        std::cout << x << std::endl;

    std::cout << std::endl;

    for (const auto& x : people | people_to_str_with_tag_view(&Person::surname))
        std::cout << x << std::endl;

    std::cout << std::endl;

    for (const auto& x : people | people_to_str_with_tag_view(&Person::year))
        std::cout << x << std::endl;

    std::cout << std::endl;

    auto proj = [i=1](const Person& person) mutable { return person.year + i++ * 10000000; };
    for (const auto& x : people | people_to_str_with_tag_view(proj))
        std::cout << x << std::endl;
}
```

</details>

<details>
<summary>Enumerate</summary>

```cpp
auto v = std::vector<std::string>{"A", "B", "C"};

for (const auto& [index, value] : ranges::views::enumerate(v))
{
    std::cout << index << ": " << value << std::endl;
}
```

</details>

<details>
<summary>Filter</summary>

```cpp
auto v = std::vector<int>{1, 2, 3, 4, 5, 6};

auto is_even = [](int i) { return i % 2 == 0; };

auto even_numbers = v | ranges::views::filter(is_even);
auto odd_numbers = v | ranges::views::remove_if(is_even);
```

</details>

<details>
<summary>Group by</summary>

▶️[**Run**](https://godbolt.org/z/c5chY953M)

```cpp
#include <range/v3/all.hpp>

#include <iostream>
#include <vector>

struct Person
{
    std::string firstname;
    std::string surname;
    int year;
};

auto operator<<(std::ostream& os, const Person& person) -> std::ostream&
{
    os << person.surname << ", " << person.firstname << " was born in " << person.year;
    return os;
}

auto main() -> int
{
    auto people = std::vector<Person>
    {
        {"Melania", "Trump", 1970},
        {"Jared", "Kushner", 1981},
        {"Donald", "Trump", 1946},
        {"Ivana", "Trump", 1949},
    };

    ranges::sort(people, {}, &Person::surname);

    auto surname_is_equal = [](const auto& p1, const auto& p2) { return p1.surname == p2.surname; };
    auto groups = people | ranges::views::chunk_by(surname_is_equal);

    for (const auto& group : groups)
    {
        std::cout << "-------" << std::endl;
        ranges::copy(group, ranges::ostream_iterator<Person>(std::cout, "\n"));
    }
}
```

</details>

<details>
<summary>Projections</summary>

▶️[**Run**](https://godbolt.org/z/33n5xEcGc)

```cpp
#include <range/v3/all.hpp>

#include <iostream>
#include <vector>

struct S
{
    std::string name;
    double a = 0.0;
    double b = 0.0;

    auto area() const -> double { return a * b; }
};

auto demo1() -> void
{
    std::cout << "--- demo 1 ----------------------------------" << std::endl << std::endl;

    auto v = std::vector<S>
    {
        {"bbb", 1.0, 2.0},
        {"aaa", 11.0, 220.0},
        {"ccc", 12.0, 22.0}
    };

    auto print_s_names = [](const auto& rng)
    {
        ranges::for_each(rng, [](const auto& x) { std::cout << x.name << std::endl; });
        std::cout << std::endl;
    };

    // projection: member
    ranges::sort(v, {}, &S::name);
    print_s_names(v);

    // projection: member function
    ranges::sort(v, {}, &S::area);
    print_s_names(v);

    // projection: lambda
    ranges::sort(v, {}, [](const auto& s) { return s.a; });
    print_s_names(v);
}

auto demo2() -> void
{
    std::cout << "--- demo 2 ----------------------------------" << std::endl << std::endl;

    auto v = std::vector<std::string>
    {
        "aaa",
        "bbbbb",
        "c"
    };

    // ranges::max/min -> if the range is empty, the behavior is undefined
    auto max_len = ranges::max(v, {}, &std::string::length).length();
    auto min_len = ranges::min(v, {}, &std::string::length).length();
    auto min_len_alt = ranges::max(v, ranges::greater{}, &std::string::length).length();

    std::cout << "max len: " << max_len << std::endl;
    std::cout << "min len: " << min_len << std::endl;
    std::cout << "min len alt: " << min_len_alt << std::endl;
}

auto main() -> int
{
    demo1();
    demo2();
}
```

</details>

<details>
<summary>Range as argument</summary>

```cpp
auto func([const] auto[&/&&/*] rng) -> void {}
```

```cpp
// Using concepts

template<typename R>
requires ranges::range<R>
auto func([const] R[&/&&/*] rng) -> void {}

template<ranges::range R>
auto func([const] R[&/&&/*] rng) -> void {}

auto func([const] ranges::range        auto[&/&&/*] rng) -> void {}
auto func([const] ranges::output_range auto[&/&&/*] rng) -> void {}
```

▶️[**Demo**](https://godbolt.org/z/6z913s66d)

</details>

<details>
<summary>Range from iterators</summary>

```cpp
auto v = std::vector<int>{1, 2, 3, 4, 5};

auto from = ranges::find(v, 3);
auto rng = ranges::subrange(from, v.end());
```

</details>

<details>
<summary>String: to_string</summary>

```cpp
auto v = std::vector<int>{1, 2, 3};

auto rng = v | ranges::views::transform([](int i) { return std::to_string(i); });
```

</details>

<details>
<summary>String: trim and uppercase</summary>

```cpp
#include <range/v3/all.hpp>

#include <iomanip>
#include <iostream>

auto main() -> int
{
    const auto text = std::string{"    Hello World "};

    auto res = text | ranges::views::reverse
                    | ranges::views::drop_while(::isspace)
                    | ranges::views::reverse
                    | ranges::views::drop_while(::isspace)
                    | ranges::views::transform(::toupper)
                    | ranges::to<std::string>();

    std::cout << std::quoted(text) << std::endl;
    std::cout << std::quoted(res) << std::endl;
}
```

</details>

<details>
<summary>Vector append</summary>

```cpp
auto v1 = std::vector<int>{1, 2, 3};
auto v2 = std::vector<int>{4, -5, 6};

v1 |= ranges::actions::push_back(v2);
v1 |= ranges::actions::push_back(v2 | ranges::views::remove_if([](int i) { return i < 0; }));
```

</details>

## std

<details>
<summary>std::optional</summary>

#### Creating

```cpp
// inplace
auto opt = std::make_optional<Type>(1, 2);

// move
auto opt = std::optional<Type>{std::move(type_inst)};
auto opt = std::optional<Type>{Type{1, 2}};

// copy
auto opt = std::optional<Type>{type_inst};
```

#### Returning

```cpp
auto return_opt() -> std::optional<Type>
{
    if (!success) return std::nullopt;
    if (!success) return {};

    // inplace (single-arg + non-explicit ctor only)
    return 1;

    // inplace
    return std::make_optional<Type>(1, 2);

    // move
    return std::move(type_inst);
    return Type{1, 2};
}
```

#### Passing as argument

```cpp
auto func(std::optional<int> arg) -> void
{
    if (arg)
    {
        // use: *arg
        // use: arg.value()
    }
}

func({});
func(std::nullopt);
func(7);
```

```cpp
#include <vsl/util.h>

auto func_nocopy(vsl::optional_ref<const std::string> arg) -> void
{
    if (arg)
    {
        auto& value = arg->get();
    }
}

const auto s = std::string{"hello"};
func_nocopy({});
func_nocopy(std::nullopt);
func_nocopy(s);
```

#### Getting value

```cpp
// opt.value() or *opt
const auto& value = opt.value();             // const ref
      auto& value = opt.value();             // ref
      auto  value = opt.value();             // copy
      auto  value = std::move(opt).value();  // move

// opt.value_or()
auto value = opt.value_or(...);             // copy
auto value = std::move(opt).value_or(...);  // move
```

#### Usage

```cpp
auto opt = return_opt();

// use: opt.value_or(...)

if (opt)
if (opt.has_value())
{
    // use: *opt
    // use: opt.value()
}
```

```cpp
if (auto opt = return_opt(); opt.has_value())
{
    // use: *opt
    // use: opt.value()
}
```

```cpp
// no nesting on positive path

auto opt = return_opt();
if (!opt) return;

auto& value = *opt;

// use: value
```

▶️[**Demo** (initialization)](https://godbolt.org/z/6h3zT7zKz) [[debug.h](vsl/debug.h)] \
▶️[**Demo** (usage)](https://godbolt.org/z/eP9x3KzoK) [[util.h](vsl/util.h)]

</details>

<details>
<summary>std::tuple</summary>

#### Creating

```cpp
// inplace Type creation (single-arg ctor only)
auto t = std::tuple<int, Type>{0, 1};

// move
auto t = std::tuple<int, Type>{0, std::move(t)};
auto t = std::tuple<int, Type>{0, Type{1, 2}};
```

#### Returning

```cpp
// inplace Type creation (single-arg + non-explicit ctor only)
auto return_tuple() -> std::tuple<int, Type> { return {0, 1}; }

// inplace Type creation (single-arg ctor only)
auto return_tuple() -> std::tuple<int, Type> { return std::tuple<int, Type>{0, 1}; }

// move
auto return_tuple() -> std::tuple<int, Type> { return {0, std::move(t)}; }
auto return_tuple() -> std::tuple<int, Type> { return {0, Type{1, 2}}; }
```

▶️[**Demo** (initialization)](https://godbolt.org/z/doMjhh8j1) [[debug.h](vsl/debug.h)]

[(StackOverflow) Why do I not get guaranteed copy elision with std::tuple?](https://stackoverflow.com/questions/63560015/why-do-i-not-get-guaranteed-copy-elision-with-stdtuple/63560206#63560206)

</details>

## String

<details>
<summary>Join string</summary>

Libs: [fmt](https://github.com/fmtlib/fmt)

▶️[**Run**](https://godbolt.org/z/odeEKh8df)

```cpp
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <string>
#include <vector>

auto main() -> int
{
    auto v = std::vector{1, 2, 3, 4, 5};

    auto res = fmt::format("{}", fmt::join(v, ", "));

    fmt::print("[{}]", res);
}
```

</details>

<details>
<summary>String builder</summary>

▶️[**Run**](https://godbolt.org/z/GG4YrYd8G)

```cpp
#include <iostream>
#include <sstream>

auto build_string_1() -> void
{
    auto ss = std::ostringstream{};

    ss << "Hello";
    ss << " from";
    ss << " string builder 1";

    std::string res1 = ss.str();
    std::string res2 = std::move(ss).str();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
}

auto build_string_2() -> void
{
    auto res = std::string{};

    res.reserve(100);  // optional

    res += "Hello";
    res += " from";
    res += " string builder 2";

    std::cout << res << std::endl;
}

auto main() -> int
{
    build_string_1();
    build_string_2();
}
```

</details>

## Templates

<details>
<summary>Class configuration: policy</summary>

[(Modernes C++) Policy](https://www.modernescpp.com/index.php/policy-and-traits/)

▶️[**Run**](https://godbolt.org/z/rhsTfbbP6)

```cpp
#include <iostream>

template<typename Policy>
class ConfigurableClass
{
public:
    ConfigurableClass()
    {
        // option 1: pass *this (more flexible, requires "friend Policy")
        // option 2: pass/return options or struct
        Policy{}.configure(*this);
    }

    auto test() const -> void
    {
        std::cout << option_ << std::endl;
    }

private:
    auto callback() const -> void
    {
        std::cout << "callback" << std::endl;
    }

    friend Policy;

    int option_ = 0;
};

struct PolicyA
{
    auto configure(ConfigurableClass<PolicyA>& self) const -> void
    {
        self.callback();
        self.option_ = 42;
    }
};

struct PolicyB
{
    auto configure(ConfigurableClass<PolicyB>& self) const -> void
    {
        self.option_ = 333;
    }
};

using ClassA = ConfigurableClass<PolicyA>;
using ClassB = ConfigurableClass<PolicyB>;

auto main() -> int
{
    ClassA{}.test();

    std::cout << std::endl;

    ClassB{}.test();
}
```

</details>

<details>
<summary>Class configuration: non-type template parameters</summary>

▶️[**Run**](https://godbolt.org/z/s7x6MxEb9)

```cpp
#include <iostream>

template<bool opt_enabled = false, int opt_value = 0>
class ConfigurableClass1
{
public:
    auto test() const -> void
    {
        if constexpr (opt_enabled)
            std::cout << "ON ";
        else
            std::cout << "OFF ";
        std::cout << opt_value << std::endl;
    }
};

struct Options
{
    bool opt_enabled = false;
    int opt_value = 0;
};

template<Options options = {}>
class ConfigurableClass2
{
public:
    auto test() const -> void
    {
        if (options.opt_enabled)
            std::cout << "ON ";
        else
            std::cout << "OFF ";
        std::cout << options.opt_value << std::endl;
    }
};

using Class1A = ConfigurableClass1<true, 42>;
using Class1B = ConfigurableClass1<false>;
using Class1C = ConfigurableClass1<>;

using Class2A = ConfigurableClass2<{.opt_enabled = true, .opt_value = 42}>;
using Class2B = ConfigurableClass2<{false, -1}>;
using Class2C = ConfigurableClass2<>;

auto main() -> int
{
    Class1A{}.test();
    Class1B{}.test();
    Class1C{}.test();

    std::cout << std::endl;

    Class2A{}.test();
    Class2B{}.test();
    Class2C{}.test();
}
```

</details>

<details>
<summary>Concepts</summary>

#### Syntax

```cpp
template<typename T>
requires std::floating_point<T>
auto func([const] T[&/&&/*] x) -> void {}

template<std::floating_point T>
auto func([const] T[&/&&/*] x) -> void {}

auto func([const] std::floating_point auto[&/&&/*] x) -> void {}
```

#### Examples

```cpp
#include <concepts>

template<typename T>
auto is_equal(T a, T b)
{
    return a == b;
}

template<typename T>
requires std::floating_point<T>
auto is_equal(T a, T b)
{
    return std::abs(a - b) < static_cast<T>(0.000001);
}
```

▶️[**Demo**](https://godbolt.org/z/9P6oo5Tfo)

</details>

<details>
<summary>CRTP mixins</summary>

▶️[**Run**](https://godbolt.org/z/G46s933vE) [[util.h](vsl/util.h)]

```cpp
#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/languages/cpp/vsl/util.h>

#include <iostream>

// ----------------------------------------------------------------------------------------------

template<typename Underlying>
class PrintSize
{
public:
    auto print_size() const -> void
    {
        auto& und = vsl::this_to<Underlying>(this);
        std::cout << "Size: " << und.size() << std::endl;
    }
};

template<typename Underlying>
class DoubleSize
{
public:
    auto double_size() -> void
    {
        auto& und = vsl::this_to<Underlying>(this);
        und.set_size(und.size()*2);
        std::cout << "Size doubled" << std::endl;
    }
};

template<typename Underlying>
class SizeOperations : public PrintSize<Underlying>, public DoubleSize<Underlying> {};

// ----------------------------------------------------------------------------------------------

class Class1 :
    public PrintSize<Class1>,
    public DoubleSize<Class1>
{
public:
    auto size() const -> int { return size_; }
    auto set_size(int size) -> void { size_ *= 2; }
private:
    int size_ = 7;
};

auto test1() -> void
{
    auto x = Class1{};
    x.print_size();
    x.double_size();
    x.print_size();
    std::cout << std::endl;
}

// ----------------------------------------------------------------------------------------------

template<template<typename> typename... Skills>
class BaseClass2 : public Skills<BaseClass2<Skills...>>...
{
public:
    auto size() const -> int { return size_; }
    auto set_size(int size) -> void { size_ *= 2; }
private:
    int size_ = 42;
};

using Class2 = BaseClass2<PrintSize, DoubleSize>;
using Class3 = BaseClass2<SizeOperations>;

auto test2() -> void
{
    auto x = Class2{};
    x.print_size();
    x.double_size();
    x.print_size();
    std::cout << std::endl;
}

auto test3() -> void
{
    auto x = Class2{};
    x.print_size();
    x.double_size();
    x.print_size();
    std::cout << std::endl;
}

// ----------------------------------------------------------------------------------------------

auto main() -> int
{
    test1();
    test2();
    test3();
}
```

</details>

<details>
<summary>if constexpr</summary>

```cpp
template<typename T>
constexpr auto precision = T(0.000001);

template<typename T>
auto is_equal(T a, T b) -> bool
{
    if constexpr (std::is_floating_point_v<T>)
    {
        return std::abs(a - b) < precision<T>;
    }
    else
    {
        return a == b;
    }
}
```

```cpp
template<typename T>
auto read_and_fill(T& container, int size) -> void
{
    if constexpr (requires { container.reserve(size); })
    {
        container.reserve(size);
    }
    // fill
}
```

</details>

<details>
<summary>Initialization wrapper</summary>

▶️[**Run**](https://godbolt.org/z/hscdfc1sc)

```cpp
#include <iostream>
#include <utility>

class Base
{
public:
    virtual auto init_after_construction() -> void = 0;
    virtual ~Base() = default;
};

class Main: public Base
{
public:
    Main()
    {
        std::cout << "Ctor: default" << std::endl;
    }

    Main(int)
    {
        std::cout << "Ctor: (int)" << std::endl;
    }

    Main(int, int)
    {
        std::cout << "Ctor: (int, int)" << std::endl;
    }

    auto init_after_construction() -> void override
    {
        std::cout << "Initialized" << std::endl;
    }
};

template<typename T>
class Initializer: public T
{
public:
    template<typename... Args>
    Initializer(Args&&... args) : T(std::forward<Args>(args)...)
    {
        this->init_after_construction();
    }
};

auto main() -> int
{
    Initializer<Main>{};

    std::cout << std::endl;

    Initializer<Main>{1};

    std::cout << std::endl;

    Initializer<Main>{1, 2};
}
```

</details>

## Type

<details>
<summary>🚧 auto&& resolving</summary>

▶️[**Run**](https://godbolt.org/z/vznsdzoTc)

```cpp
#include <map>
#include <tuple>
#include <vector>

auto test_scalar() -> void
{
    auto x = 0;
    auto&& x1 = x;
    // int& x1

    auto&& x2 = 0;
    // int&& x2
}

auto test_tuple_binding_by_uref() -> void
{
    auto tuple = std::tuple{1, 2.0};
    auto&& [x1, y1] = tuple;
    // int& x1, double& y1

    auto&& [x2, y2] = std::tuple{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary tuple)
}

auto test_tuple_binding_by_copy() -> void
{
    auto tuple = std::tuple{1, 2.0};
    auto [x1, y1] = tuple;
    // int& x1, double& y1 (lvalue refs to tuple copy)

    auto [x2, y2] = std::tuple{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary tuple)
}

auto test_vector_el() -> void
{
    auto&& v = std::vector{1, 2, 3};
    // std::vector<int>&& v

    auto&& x = v[0];
    // !!!
    // int& x
}

auto test_vector_proxy_el() -> void
{
    auto&& v = std::vector<bool>{true, false, true};
    // std::vector<bool>&& v

    auto&& x = v[0];
    // bool&& x (rvalue ref to temporary proxy object)
}

auto test_iteration_vector() -> void
{
    auto v = std::vector{1, 2, 3};
    for (auto&& el : v) {}
    // int& el

    for (auto&& el : std::vector{1, 2, 3}) {}
    // !!!
    // int& el
    // ---------------------------------------------------------------------------
    // for(; !operator==(__begin1, __end1); __begin1.operator++())
    //   int & el = __begin1.operator*();

    for (auto&& el : std::vector<bool>{true, false, true}) {}
    // bool&& el (rvalue ref to temporary proxy object)
}

auto test_iteration_binding_map() -> void
{
    auto m = std::map<int, double>{{1, 10.0}, {2, 20.0}};
    for (auto&& [k, v] : m) {}
    // const int& k, double& v

    for (auto&& [k, v] : std::map<int, double>{{1, 10.0}, {2, 20.0}}) {}
    // !!!
    // const int& k, double& v
}

auto test_struct_binding_by_uref() -> void
{
    struct S { int x; double y; };

    auto s = S{1, 2.0};
    auto&& [x1, y1] = s;
    // int& x1, double& y1

    auto&& [x2, y2] = S{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary struct)
}

auto test_struct_binding_by_copy() -> void
{
    struct S { int x; double y; };

    auto s = S{1, 2.0};
    auto [x1, y1] = s;
    // int& x1, double& y1 (lvalue refs to struct copy)

    auto [x2, y2] = S{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary struct)
}

auto main() -> int
{
    test_scalar();
    test_tuple_binding_by_uref();
    test_tuple_binding_by_copy();
    test_vector_el();
    test_vector_proxy_el();
    test_iteration_vector();
    test_iteration_binding_map();
    test_struct_binding_by_uref();
    test_struct_binding_by_copy();
}
```

</details>

<details>
<summary>Enum bit flags</summary>

Libs: [magic_enum](https://github.com/Neargye/magic_enum)

▶️[**Run**](https://godbolt.org/z/Gjb5n7jzz)

```cpp
#include <magic_enum/magic_enum_containers.hpp>

#include <cstdint>

// ----------------------------------------------------------------------------------------------

enum class Option : uint64_t
{
    opt1 = uint64_t{1} << 0,
    opt2 = uint64_t{1} << 1,
    opt3 = uint64_t{1} << 2,
    opt4 = uint64_t{1} << 3,
};
using OptionFlags = magic_enum::containers::bitset<Option>;
inline constexpr auto no_options = OptionFlags{};

enum class OtherOption : uint32_t
{
    opt1 = 1 << 0,
    opt2 = 1 << 1,
    opt3 = 1 << 2,
    opt4 = 1 << 3,
};
using OtherOptionFlags = magic_enum::containers::bitset<OtherOption>;

// ----------------------------------------------------------------------------------------------

#include <cassert>
#include <format>
#include <iostream>

using std::cout, std::endl;

auto print_options(OptionFlags opt) -> void
{
    auto opt1_set = opt.test(Option::opt1);
    auto opt2_set = opt.test(Option::opt2);
    auto opt3_set = opt[Option::opt3];
    auto opt4_set = opt[Option::opt4];

    auto all = opt.all();
    auto any = opt.any();
    auto none = opt.none();
    assert(none == !any);

    auto total_flags_count = opt.size();
    auto set_flags_count = opt.count();

    auto as_str = opt.to_string();
    auto as_str_bin = opt.to_string({}, '0', '1');
    auto as_raw = opt.to_ullong({});

    cout << (opt1_set ? "+" : "o");
    cout << (opt2_set ? "+" : "o");
    cout << (opt3_set ? "+" : "o");
    cout << (opt4_set ? "+" : "o");
    cout << std::format("  {:19}", as_str);
    cout << std::format("  ({}/{})", set_flags_count, total_flags_count);
    cout << std::format(" ({})", as_str_bin);
    cout << std::format(" (raw:{:02})", as_raw);
    cout << (none ? " (NONE)" : "");
    cout << (all ? " (ALL)" : "");
    cout << endl;
}

auto main() -> int
{
    auto opt = OptionFlags{};

    // create: from raw
    auto raw = 7;
    opt = OptionFlags{{}, static_cast<unsigned long long>(raw)};
    print_options(opt);

    // create: from enum list
    opt = OptionFlags{Option::opt1, Option::opt2};
    print_options(opt);

    // create: from enum
    opt = OptionFlags{Option::opt1};
    print_options(opt);

    // create: empty
    opt = OptionFlags{};
    print_options(opt);

    // set
    opt.set(Option::opt1);
    opt |= OptionFlags{Option::opt2, Option::opt3};
    print_options(opt);

    // toggle
    opt[Option::opt4] = !opt[Option::opt4];
    print_options(opt);
    opt[Option::opt4] = !opt[Option::opt4];
    print_options(opt);

    // reset
    opt.set(Option::opt3, false);
    opt.reset(Option::opt2);
    print_options(opt);

    // inverse
    opt.flip();
    print_options(opt);

    // clear
    opt.reset();
    print_options(opt);

    // set all
    opt.set();
    print_options(opt);

    // == != operators
    auto opt_lhs = OptionFlags{Option::opt1, Option::opt2};
    auto opt_rhs_same = OptionFlags{Option::opt1, Option::opt2};
    auto opt_rhs_not_same = OptionFlags{Option::opt1, Option::opt3};
    assert(opt_lhs == opt_rhs_same);
    assert(opt_lhs != opt_rhs_not_same);

    // | operator
    auto opt13 = OptionFlags{Option::opt1, Option::opt3};
    auto opt2 = OptionFlags{Option::opt2};
    auto opt123 = OptionFlags{Option::opt1, Option::opt2, Option::opt3};
    assert(opt123 == (opt13 | opt2));

    // function args
    cout << endl;
    auto func = [](int a, OptionFlags opt = OptionFlags{}, int b = 0)
    {
        cout << "func: [" << opt << "]" << endl;
    };
    func(1);
    func(1, OptionFlags{Option::opt1, Option::opt2});
    func(1, {Option::opt3, Option::opt4});
    func(1, OptionFlags{}, 2);
    func(1, no_options, 2);

    //-----------------
    // errors
    //-----------------

    // auto other_opt = OtherOptionFlags{OtherOption::opt1, OtherOption::opt2};
    // other_opt.set(Option::opt3);

    // auto other_opt = OtherOptionFlags{OtherOption::opt1, OtherOption::opt2};
    // print_options(other_opt);
}
```

</details>

<details>
<summary>Pointers and const</summary>

| Declaration syntax      | Description                | Reassign? | Modify target? |
|-------------------------|----------------------------|:---------:|:--------------:|
| **`const Type*`**       | **pointer-to**-const       | ✔️ ||
| `Type const*`           | **pointer-to**-const       | ✔️ ||
| **`Type* const`**       | const **pointer**          || ✔️ |
| **`const Type* const`** | const **pointer-to**-const |||
| `Type const* const`     | const **pointer-to**-const |||

</details>

<details>
<summary>Type alias</summary>

[(cppreference) Type alias](https://en.cppreference.com/w/cpp/language/type_alias.html)

#### Simple

```cpp
using UserId = int;
using UserAccounts = std::map<UserId, std::vector<Account>>;
```

#### Template

```cpp
template<typename T>
using UserAccounts = std::map<UserId, std::vector<T>>;
```

#### Nested

```cpp
struct Shape
{
    using VertexList = std::vector<Point>;
    VertexList vertexes;
};

auto MakeShape() -> Shape
{
    return Shape{ Shape::VertexList{{1,0}, {0,1}, {0,0}, {1,1}} };
}
```

#### Function pointer

```cpp
// Equivalent to: typedef void (*func)(int, int);
using func = void (*) (int, int);
```

</details>

## vsl

<details>
<summary>NonCopyable</summary>

▶️[**Demo**](https://godbolt.org/z/KMbP1z85j) [[non_copyable.h](vsl/non_copyable.h)]

</details>

<details>
<summary>output</summary>

▶️[**Demo**](https://godbolt.org/z/3qKsKz34e) [[output.h](vsl/output.h)]

</details>

<details>
<summary>ScopeGuard</summary>

▶️[**Run**](https://godbolt.org/z/b9n3naE14) [[scope_guard.h](vsl/scope_guard.h)]

```cpp
#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/languages/cpp/vsl/scope_guard.h>

#include <iostream>

using std::cout, std::endl;

using vsl::ScopeGuard;

struct Resource
{
    Resource() { cout << "resource created" << endl; }
    auto use() -> void { cout << "resource using" << endl; }
    auto close() -> void { cout << "resource closed" << endl; }
};

auto main() -> int
{
    {
        cout << "--- scope in 1 ---" << endl;

        auto guard1 = ScopeGuard{[]() { cout << "guard1" << endl; }};

        auto lam2 = []() { cout << "guard2" << endl; };
        auto guard2 = ScopeGuard{lam2};

        auto guard3 = ScopeGuard{[]() { cout << "guard3" << endl; }};
        guard3.dismiss();

        cout << "--- scope out 1 ---" << endl;
    }

    cout << endl;

    {
        cout << "--- scope in 2 ---" << endl;

        auto resource = Resource{};
        auto scope_guard = ScopeGuard{[&]() { resource.close(); }};

        // ...
        resource.use();
        // ...

        cout << "--- scope out 2 ---" << endl;
    }

    cout << endl;

    {
        cout << "--- scope in 3 ---" << endl;

        VSL_SCOPE_GUARD{ cout << "additional SCOPE_GUARD" << endl; };

        auto resource = Resource{};
        VSL_SCOPE_GUARD{ resource.close(); };

        // ...
        resource.use();
        // ...

        cout << "--- scope out 3 ---" << endl;
    }
}
```

</details>

## Var

<details>
<summary>Includes</summary>

#### Order of includes

```cpp
// Corresponding header (if exists)
#include "self.h"

// Current project headers
#include <my_project/other.h>

// Third party headers
#include <fmt/format.h>
#include <range/v3/all.hpp>

// Standard headers
#include <atomic>
#include <ctype.h>
#include <vector>

// Conditional includes
#ifdef LANG_CXX11
#include <initializer_list>
#endif
```

</details>

<details>
<summary>Project organization</summary>

```
<project_name>
├── <project_name>/
│   ├── subdir/
│   │   └── ...
│   ├── detail/
│   │   ├── *.h
│   │   ├── *.cpp
│   │   └── *.test.cpp
│   ├── *.h
│   ├── *.cpp
│   └── *.test.cpp
├── build/
├── cmake/
│   └── *.cmake
├── doc/
├── example/
├── external/
├── out/
│   └── build/
├── test/
│   ├── subdir/
│   │   └── *_test.cpp
│   └── *_test.cpp
├── tools/
├── CMakeLists.txt
├── CMakePresets.json
├── CMakeUserPresets.json
├── vcpkg.json
├── *.bat
└── *.sh
```

</details>
