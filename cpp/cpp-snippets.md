# C++ / Snippets

## Class

<details>
<summary>Class: guide</summary>

#### Structure
```cpp
class MyClass [final]
{
public:
    // Types and type aliases
    // Static constants

    // Factory functions
    // Constructors and assignment operators
    // Destructor

    MyClass() = default;

    // Rule of five/zero
    MyClass(const MyClass&) = default;
    MyClass(MyClass&&) noexcept = default;
    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) noexcept = default;
    [virtual] ~MyClass() = default;

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

#### Options

| Inheritance | Polymorphic<br>usage | Type | Class options |
|:---:|:---:|:---:|---|
| No ||| • `final` class<br>• rule of five/zero |
| :white_check_mark: | No | Abstract | • destructor: `virtual ~MyClass() = 0;`<br>• destructor body: `inline MyClass::~MyClass() {}` |
| :white_check_mark: | No | Concrete | • (optional) `final` class<br>• rule of five/zero |
| :white_check_mark: | :white_check_mark: | Interface | • destructor: `virtual ~MyClass() = default;` |
| :white_check_mark: | :white_check_mark: | Abstract | • destructor:<br>&nbsp;&nbsp;&nbsp;&nbsp;- base: `virtual ~MyClass() = 0;`<br>&nbsp;&nbsp;&nbsp;&nbsp;- derived: `~MyClass() override = 0;`<br>• destructor body: `inline MyClass::~MyClass() {}` |
| :white_check_mark: | :white_check_mark: | Concrete<br>(base) | • destructor: `virtual`, user-defined/`default`<br>• rule of five (user-defined/`default`)<br>• risk of slicing ([C.67](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c67-a-polymorphic-class-should-suppress-public-copymove)) |
| :white_check_mark: | :white_check_mark: | Concrete<br>(derived) | • (optional) `final` class<br>• rule of five/zero (mark destructor as `override`/`final`) |

#### Tips

:warning: Make explicit move operations `noexcept` ([C.66](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c66-make-move-operations-noexcept)):
```cpp
MyClass(MyClass&& other) noexcept {...}
MyClass& operator=(MyClass&& other) noexcept {...}
```

#### Specifiers: virtual/override/final
```cpp
struct A
{
    virtual ~A() = default;
    virtual auto foo() [const] [&/&&] [noexcept] -> void = 0;
};

struct B : A
{
    ~B() override;
    auto foo() [const] [&/&&] [noexcept] -> void override;
};

struct C final : B
{
    ~C() final;
    auto foo() [const] [&/&&] [noexcept] -> void final;
};
```

</details>

<details>
<summary>Class: abstract</summary>

```cpp
class AbstractBase
{
public:
    virtual ~AbstractBase() = 0;

    auto process() const -> void
    {
        step1();
        step2();
    };

    virtual auto step1() const -> void {...}
    virtual auto step2() const -> void {...}
};

inline AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase
{
public:
    auto step2() const -> void override {...}
};
```

:arrow_forward: [**Demo**](https://godbolt.org/z/7evMYToW4)

</details>

<details>
<summary>Class: interface</summary>

```cpp
class ITest
{
public:
    virtual auto test1() const -> void = 0;
    virtual auto test2() const -> void = 0;
    virtual ~ITest() = default;
};

class Test : public ITest
{
public:
    auto test1() const -> void override {...}
    auto test2() const -> void override {...}
};
```

:arrow_forward: [**Demo**](https://godbolt.org/z/hsE9v5dEa)

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

:arrow_forward: [**Demo**](https://godbolt.org/z/zKv78hE71)

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

    // non-static const
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

    // non-static const
    const std::string const_str{"non-static const str"};
};
```

:arrow_forward: [**Demo**](https://godbolt.org/z/7bKoo59Mv)

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
<summary>Constructors: inheritance (hierarchy)</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/Kdo6acEh7)

```cpp
#include <iostream>

auto print(auto text) -> void
{
    std::cout << text << " ";
}

struct A
{
    A()
    {
        print("A");
    }

    A(int x)
    {
        print("Ai");
    }
};

struct B : A
{
    B()
    {
        print("B");
    }

    B(int x)
        : A(x)
    {
        print("Bi");
    }
};

struct C : B
{
    C()
    {
        print("C");
    }

    C(int x)
        : B(x)
    {
        print("Ci");
    }

    C(double x)
    {
        print("Cd");
    }
};

auto main() -> int
{
    C();  // A B C

    std::cout << std::endl;

    C(1);  // Ai Bi Ci

    std::cout << std::endl;

    C(1.0);  // A B Cd
}
```

</details>

<details>
<summary>Constructors: inheritance (import)</summary>

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
<summary>Template class constructors/methods with T&& args</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/9ajoYG3Yh) [[object_watcher.h](src/object_watcher.h)]

```cpp
#include <iostream>
#include <utility>

#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/cpp/src/object_watcher.h>

using std::cout, std::endl;

using Watcher = vs::debug::CtorWatcher;

template<typename T>
struct Test1
{
    Test1(const T& x) : x_{x}
    {
        cout << "Test1 [const T&]" << endl;
    }

    // Catches only rvalues
    // T&& is rvalue ref of type T (not forwarding/universal ref)
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
<summary>Object Watcher</summary>

:arrow_forward: [**Demo** (CtorWatcher)](https://godbolt.org/z/f6r8obT7W) [[object_watcher.h](src/object_watcher.h)] \
:arrow_forward: [**Demo** (ObjWatcher)](https://godbolt.org/z/zWoMMTdqz) [[object_watcher.h](src/object_watcher.h)]

</details>

<details>
<summary>Show deducted type</summary>

[(StackOverflow) Using 'auto' type deduction - how to find out what type the compiler deduced?](https://stackoverflow.com/questions/38820579/using-auto-type-deduction-how-to-find-out-what-type-the-compiler-deduced)

```cpp
struct {} _ = ...
```

</details>

<details>
<summary>Type info (overload resolution test)</summary>

:arrow_forward: [**Demo** (overload resolution test)](https://godbolt.org/z/jGWMzWvE9) [[type_info.h](src/type_info.h)]

</details>

## Functional

<details>
<summary>Dispatch table</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/dY9qeP87v)

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
    auto operator()(double a, double b) -> double
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
<summary>Function as argument</summary>

```cpp
#include <functional>

auto func_arg(std::function<int(int, int)> f) -> void
{
    int res = f(1, 2);
}
```

```cpp
auto func_arg(auto f) -> void
{
    int res = f(1, 2);
}
```

:arrow_forward: [**Demo**](https://godbolt.org/z/bE63qnnhM)

</details>

<details>
<summary>Function object</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/bssqEqqMj)

```cpp
#include <iostream>

struct Compare
{
    constexpr auto operator()(const auto& a, const auto& b) const -> bool
    {
        return a == b;
    }
};

inline constexpr Compare compare{};

auto main() -> int
{
    std::cout << compare(1, 2) << std::endl;
    std::cout << compare(2, 2) << std::endl;
    std::cout << compare(3, 2) << std::endl;
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
<summary>Parameter passing</summary>

#### Guidelines
* [Prefer simple and conventional ways of passing information](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f15-prefer-simple-and-conventional-ways-of-passing-information)
* [For general use, take T* or T& arguments rather than smart pointers](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f7-for-general-use-take-t-or-t-arguments-rather-than-smart-pointers)
* [Prefer T* over T& when “no argument” is a valid option](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f60-prefer-t-over-t-when-no-argument-is-a-valid-option)

#### Pass by value
[Language / Types / Passing parameters by value (by-value-then-move idiom)](cpp-language.md#types--passing-parameters-by-value-by-value-then-move-idiom)

* **Cheap-to-copy types (≤ 2×sizeof(void\*))**
* **Non-copyable types**
* Iterators
* Callable objects (functors, lambdas, std::function)
* View types (std::string_view, std::span)
* std::shared_ptr (sharing ownership)
* std::unique_ptr (taking ownership)

</details>

<details>
<summary>Projection</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/YT7ToaYvd)

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

//=============================================================================
// Run projection
//-----------------------------------------------------------------------------
// const P&  proj: NO (doesn't accept mutable lambdas/functors)
//       P&  proj: NO (doesn't accept rvalues)
//       P&& proj: NO (confusing if there is no forwarding)
//       P   proj: YES
//=============================================================================
// Store projection for lazy evaluation
//-----------------------------------------------------------------------------
// const P&  proj: NO
//       P&  proj: NO
//       P&& proj: YES (pass by forwarding ref, then store by std::forward)
//       P   proj: YES (pass by value, then store by std::move)
//=============================================================================
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
<summary>Return structured data</summary>

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

:arrow_forward: [**Demo**](https://godbolt.org/z/j8dGva4bT)

</details>

<details>
<summary>std::apply</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/3Gs98nrhG)

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

:arrow_forward: [**Run**](https://godbolt.org/z/5PcK5hev7)

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

## Initialization

<details>
<summary>auto (AAA)</summary>

:point_right: `auto` means "take exactly the type on the right-hand side, but strip off top-level const/volatile and &/&&"

Syntax:
```cpp
[static/inline] [const/constexpr] auto[&/&&/*] x = expr;
[static/inline] [const/constexpr] auto[&/&&/*] x = TYPE{expr};
```

```cpp
         auto  x = expr;  // removes cv/ref
decltype(auto) x = expr;  // preserves cv/ref
```

Examples:
```cpp
auto i = int64_t{123};
auto v = std::vector<int>{};
auto get_size = [](const auto& x) { return x.size(); };
```

Dynamic memory allocation:
```cpp
auto w = new Widget{};
auto w = std::make_unique<Widget>();
```

Polymorphic smart pointers:
```cpp
auto base_shared_ptr = std::shared_ptr<Base>{ std::make_shared<Derived>() };
auto base_unique_ptr = std::unique_ptr<Base>{ std::make_unique<Derived>() };
```

Strings:
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

Loop counter:
```cpp
for (auto i = size_t{0}; i < v.size(); ++i)
for (auto i = vs::Index{0}; i < vs::signed_size(v); ++i)

for (auto i = vs::signed_size(v)-1; i >= 0; --i)
```

Signed/unsigned cast with helpers:
```cpp
auto x = vs::as_signed(integer_expr);
auto x = vs::as_unsigned(integer_expr);
```

Initialization by function return value:
```cpp
Gadget get_gadget();

Widget w = get_gadget();  // BAD: implicit conversion Gadget to Widget (creates a temporary)
auto w = get_gadget();  // GOOD: no implicit conversion
auto w = Widget{ get_gadget() };  // GOOD: implicit conversion with intent
```

`std::initializer_list` issue:
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
<summary>auto (trailing return type)</summary>

#### Trailing return type

```cpp
[static/inline] [constexpr] TYPE non_member_func() [noexcept]
[static/inline] [constexpr] auto non_member_func() [noexcept] -> TYPE
```

```cpp
[virtual] [static] [constexpr] TYPE member_func() [const] [&/&&] [noexcept]         [override/final]
[virtual] [static] [constexpr] auto member_func() [const] [&/&&] [noexcept] -> TYPE [override/final]
```

```cpp
Person::PersonType Person::get_person_type()
auto               Person::get_person_type() -> PersonType
```

#### Trailing return type (type deduction)

```cpp
... auto func() ... -> TYPE
... auto func() ... -> [const] auto[&/&&/*]
                    -> decltype(auto)
```

```cpp
auto func() -> auto
auto func()  // trailing auto can be omitted
```

</details>

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
if (auto [it_elem, success] = mymap.insert(std::pair('a', 100)); success) {...}
```

</details>

<details>
<summary>Statement with initializer: range-based for (C++20)</summary>

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
for (auto& x : foo().items()) {...}  // undefined behavior if foo() returns by value
                                     // https://pvs-studio.ru/ru/blog/posts/cpp/1149/#ID5FFD7E2F1C
for (auto thing = foo(); auto& x : thing.items()) {...}  // OK
```

</details>

<details>
<summary>:warning: Structured Binding</summary>

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

Unpacking a tuple:
```cpp
#include <tuple>

auto tuple = std::tuple{1, 'a', 2.3};

auto [a, b, c] = tuple;
```

Unpacking a struct:
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

Unpacking a map:
```cpp
#include <map>

for (const auto& [k, v] : mymap) {...}
```

</details>

## Math

<details>
<summary>Clamp</summary>

```cpp
#include <algorithm>
#include <iostream>

auto main() -> int
{
    std::cout << std::clamp(0.5, 1.0, 2.0) << std::endl;  // 1
    std::cout << std::clamp(1.5, 1.0, 2.0) << std::endl;  // 1.5
    std::cout << std::clamp(2.5, 1.0, 2.0) << std::endl;  // 2
}
```

</details>

<details>
<summary>Floating point comparisons</summary>

[(LearnCpp) Relational operators and floating point comparisons](https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/)

:arrow_forward: [**Demo**](https://godbolt.org/z/1orqxaq9d) [[math.h](src/math.h)]

</details>

<details>
<summary>Signed/unsigned</summary>

#### Loop counter
```cpp
for (auto i = size_t{0}; i < v.size(); ++i)
for (auto i = vs::Index{0}; i < vs::signed_size(v); ++i)

for (auto i = vs::signed_size(v)-1; i >= 0; --i)
```

#### Demos
:arrow_forward: [**Demo** (arithmetic)](https://godbolt.org/z/vcnarnYb6) [[util.h](src/util.h)] \
:arrow_forward: [**Demo** (compare)](https://godbolt.org/z/nG9x3oEM3) [[util.h](src/util.h)] \
:arrow_forward: [**Demo** (index)](https://godbolt.org/z/8PzeK8qKE) [[util.h](src/util.h)] \
:arrow_forward: [**Demo** (accumulate)](https://godbolt.org/z/Tq3MW9zn4) [[util.h](src/util.h)]

#### `-Wsign-compare` compiler option
* Enabling:
  * GCC: `-Wsign-compare`, `-Wall`, `-Wextra` ([doc](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html))
  * Clang: `-Wsign-compare`, `-Wextra` ([doc](https://clang.llvm.org/docs/DiagnosticsReference.html))
  * MSVC: `/W3`, `/W4` ([C4018](https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4018)) ([doc](https://learn.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level))
* Cons: false positive for code like `for (auto i = vs::Index{0}; i < sizeof(buf); i++)`
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

[(Reference) Using namespace](https://en.cppreference.com/w/cpp/language/namespace#Using-directives)

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

[(Reference) Operator overloading](https://en.cppreference.com/w/cpp/language/operators)

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

:arrow_forward: [**Demo**](https://godbolt.org/z/fxPqf4GKW)

</details>

<details>
<summary>Ternary conditional operator</summary>

```cpp
condition ? true_expression : false_expression
```

</details>

## Std::

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
auto func(const std::optional<std::string>& arg) -> void
{
    if (arg)
    {
        // use: *arg
        // use: arg.value()
    }
}

func({});
func(std::nullopt);
func("hello");
```

```cpp
auto func_nocopy(const vs::util::optional_ref<const std::string> arg) -> void
{
    if (arg)
    {
        auto& value = arg->get();
    }
}

const auto s = std::string{"world"};
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

:arrow_forward: [**Demo** (initialization)](https://godbolt.org/z/reexs7fG5) [[object_watcher.h](src/object_watcher.h)] \
:arrow_forward: [**Demo** (usage)](https://godbolt.org/z/T57E6rh76) [[util.h](src/util.h)]

</details>

<details>
<summary>std::tuple</summary>

#### Creating
```cpp
// inplace (single-arg ctor only)
auto t = std::tuple<int, Watcher>{0, 1};

// move
auto t = std::tuple<int, Watcher>{0, std::move(w)};
auto t = std::tuple<int, Watcher>{0, Watcher{1, 2}};
```

#### Returning
```cpp
// inplace (single-arg + non-explicit ctor only)
auto return_tuple() -> std::tuple<int, Watcher> { return {0, 1}; }

// inplace (single-arg ctor only)
auto return_tuple() -> std::tuple<int, Watcher> { return std::tuple<int, Watcher>{0, 1}; }

// move
auto return_tuple() -> std::tuple<int, Watcher> { return {0, std::move(w)}; }
auto return_tuple() -> std::tuple<int, Watcher> { return {0, Watcher{1, 2}}; }
```

:arrow_forward: [**Demo** (initialization)](https://godbolt.org/z/b9cPfqq5q) [[object_watcher.h](src/object_watcher.h)]

[(StackOverflow) Why do I not get guaranteed copy elision with std::tuple?](https://stackoverflow.com/questions/63560015/why-do-i-not-get-guaranteed-copy-elision-with-stdtuple/63560206#63560206)

</details>

## String

<details>
<summary>Join string</summary>

Libs: [fmt](https://github.com/fmtlib/fmt)

:arrow_forward: [**Run**](https://godbolt.org/z/KGq79nbTW)

```cpp
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ranges.h>

auto main() -> int
{
    auto v = std::vector<std::string>{"a", "b", "c", "d"};

    auto res = fmt::format("{}", fmt::join(v, ", "));

    fmt::print("[{}]", res);
}
```

</details>

<details>
<summary>String builder</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/GG4YrYd8G)

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

## Type

<details>
<summary>:warning: auto&& resolving</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/vznsdzoTc)

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
<summary>:warning: auto&& and forward :confused:</summary>

#### Summary
```cpp
for (auto&& el : my_range)
auto&& [el, _] = my_tuple;
auto&& [el, _] = my_struct;

if constexpr (std::is_rvalue_reference_v<decltype(my_range)>)
if constexpr (std::is_rvalue_reference_v<decltype(my_tuple)>)
if constexpr (std::is_rvalue_reference_v<decltype(my_struct)>)
{
    vec.push_back(std::move(el));
}
else
{
    vec.push_back(el);
}
```

:arrow_forward: [**Run**](https://godbolt.org/z/nK4dWzjM6)

```cpp
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using std::cout, std::endl;

enum class ArgType { VAL, RVAL };

struct Watcher
{
    Watcher() = default;
    Watcher& operator=(const Watcher&) = delete;
    Watcher& operator=(Watcher&&) = delete;
    Watcher(const Watcher&) noexcept { operations_history += "C"; }
    Watcher(Watcher&&) noexcept { operations_history += "M"; }

    static inline std::string operations_history{};

    static auto check(const std::string& desc, ArgType arg_type) -> void
    {
        auto operations_expected = std::string{};
        if (arg_type == ArgType::VAL)
        {
            operations_expected = "C";
            cout << desc << " (val)";
        }
        else
        {
            operations_expected = "M";
            cout << desc << " (RVAL)";
        }

        cout << " --> " << operations_history;
        if (operations_history != operations_expected)
        {
            cout << " ERROR (expected: " << operations_expected << ")";
        }

        cout << endl;
        operations_history.clear();
    }
};

// ----------------------------------------------------------------------------------------------

auto append_range_bad(auto& dest, auto&& range) -> void
{
    for (auto&& el : range)
    {
        dest.push_back(std::forward<decltype(el)>(el));
    }
}

auto append_range_good(auto& dest, auto&& range) -> void
{
    for (auto&& el : range)
    {
        if constexpr (std::is_rvalue_reference_v<decltype(range)>)
        {
            dest.push_back(std::move(el));
        }
        else
        {
            dest.push_back(el);
        }
    }
}

// solution using std::forward_like (C++23)
// auto append_range_good_2(auto& dest, auto&& range) -> void
// {
//     for (auto&& el : range)
//     {
//         dest.push_back(std::forward_like<decltype(range)>(el));
//     }
// }

auto test_range_for() -> void
{
    auto vec = std::vector<Watcher>(1);
    auto dest = std::vector<Watcher>{};
    dest.reserve(100);

    append_range_bad(dest, vec);
    Watcher::check("append_range_bad", ArgType::VAL);

    append_range_bad(dest, std::vector<Watcher>(1));
    Watcher::check("append_range_bad", ArgType::RVAL);

    append_range_good(dest, vec);
    Watcher::check("append_range_good", ArgType::VAL);

    append_range_good(dest, std::vector<Watcher>(1));
    Watcher::check("append_range_good", ArgType::RVAL);

    cout << endl;
}

// ----------------------------------------------------------------------------------------------

auto append_tuple_bad(auto& dest, auto&& tuple) -> void
{
    auto&& [watcher, _] = tuple;
    dest.push_back(std::forward<decltype(watcher)>(watcher));
}

auto append_tuple_good(auto& dest, auto&& tuple) -> void
{
    auto&& [watcher, _] = tuple;

    if constexpr (std::is_rvalue_reference_v<decltype(tuple)>)
    {
        dest.push_back(std::move(watcher));
    }
    else
    {
        dest.push_back(watcher);
    }
}

auto test_tuple() -> void
{
    auto tuple = std::tuple<Watcher, int>{};
    auto dest = std::vector<Watcher>{};
    dest.reserve(100);

    append_tuple_bad(dest, tuple);
    Watcher::check("append_tuple_bad", ArgType::VAL);

    append_tuple_bad(dest, std::tuple<Watcher, int>{});
    Watcher::check("append_tuple_bad", ArgType::RVAL);

    append_tuple_good(dest, tuple);
    Watcher::check("append_tuple_good", ArgType::VAL);

    append_tuple_good(dest, std::tuple<Watcher, int>{});
    Watcher::check("append_tuple_good", ArgType::RVAL);

    cout << endl;
}

// ----------------------------------------------------------------------------------------------

struct TestStruct { Watcher w; int i; };

auto append_struct_bad_1(auto& dest, auto&& test_struct) -> void
{
    auto&& [watcher, _] = test_struct;
    dest.push_back(std::forward<decltype(watcher)>(watcher));
}

auto append_struct_bad_2(auto& dest, auto&& test_struct) -> void
{
    dest.push_back(std::forward<decltype(test_struct.w)>(test_struct.w));
}

auto append_struct_good_1(auto& dest, auto&& test_struct) -> void
{
    dest.push_back(std::forward<decltype(test_struct)>(test_struct).w);
}

auto append_struct_good_2(auto& dest, auto&& test_struct) -> void
{
    auto&& [watcher, _] = test_struct;

    if constexpr (std::is_rvalue_reference_v<decltype(test_struct)>)
    {
        dest.push_back(std::move(watcher));
    }
    else
    {
        dest.push_back(watcher);
    }
}

auto test_struct() -> void
{
    auto test_struct = TestStruct{};
    auto dest = std::vector<Watcher>{};
    dest.reserve(100);

    append_struct_bad_1(dest, test_struct);
    Watcher::check("append_struct_bad_1", ArgType::VAL);

    append_struct_bad_1(dest, TestStruct{});
    Watcher::check("append_struct_bad_1", ArgType::RVAL);

    append_struct_bad_2(dest, test_struct);
    Watcher::check("append_struct_bad_2", ArgType::VAL);

    append_struct_bad_2(dest, TestStruct{});
    Watcher::check("append_struct_bad_2", ArgType::RVAL);

    append_struct_good_1(dest, test_struct);
    Watcher::check("append_struct_good_1", ArgType::VAL);

    append_struct_good_1(dest, TestStruct{});
    Watcher::check("append_struct_good_1", ArgType::RVAL);

    append_struct_good_2(dest, test_struct);
    Watcher::check("append_struct_good_2", ArgType::VAL);

    append_struct_good_2(dest, TestStruct{});
    Watcher::check("append_struct_good_2", ArgType::RVAL);

    cout << endl;
}

// ----------------------------------------------------------------------------------------------

auto main() -> int
{
    test_range_for();
    test_tuple();
    test_struct();
}
```

</details>

<details>
<summary>Enum bit flags</summary>

Libs: [magic_enum](https://github.com/Neargye/magic_enum)

:arrow_forward: [**Run**](https://godbolt.org/z/69fs8a7G6)

```cpp
#include <cstdint>

#include <magic_enum/magic_enum_containers.hpp>

enum class Option : uint64_t
{
    OPT1 = uint64_t{1} << 0,
    OPT2 = uint64_t{1} << 1,
    OPT3 = uint64_t{1} << 2,
    OPT4 = uint64_t{1} << 3,
};
using OptionFlags = magic_enum::containers::bitset<Option>;
inline constexpr OptionFlags no_options{};

enum class OtherOption : uint32_t
{
    OPT1 = 1 << 0,
    OPT2 = 1 << 1,
    OPT3 = 1 << 2,
    OPT4 = 1 << 3,
};
using OtherOptionFlags = magic_enum::containers::bitset<OtherOption>;

// ----------------------------------------------------------------------------------------------

#include <cassert>
#include <format>
#include <iostream>

using std::cout, std::endl;

auto print_options(OptionFlags opt) -> void
{
    bool opt1_set = opt.test(Option::OPT1);
    bool opt2_set = opt.test(Option::OPT2);
    bool opt3_set = opt[Option::OPT3];
    bool opt4_set = opt[Option::OPT4];

    bool all = opt.all();
    bool any = opt.any();
    bool none = opt.none();
    assert(none == !any);

    size_t total_flags_count = opt.size();
    size_t set_flags_count = opt.count();

    std::string as_str = opt.to_string();
    std::string as_str_bin = opt.to_string({}, '0', '1');
    unsigned long long as_raw = opt.to_ullong({});

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
    OptionFlags opt;

    // create: from raw
    int raw = 7;
    opt = OptionFlags{{}, static_cast<unsigned long long>(raw)};
    print_options(opt);

    // create: from enum list
    opt = OptionFlags{Option::OPT1, Option::OPT2};
    print_options(opt);

    // create: from enum
    opt = OptionFlags{Option::OPT1};
    print_options(opt);

    // create: empty
    opt = OptionFlags{};
    print_options(opt);

    // set
    opt.set(Option::OPT1);
    opt |= OptionFlags{Option::OPT2, Option::OPT3};
    print_options(opt);

    // toggle
    opt[Option::OPT4] = !opt[Option::OPT4];
    print_options(opt);
    opt[Option::OPT4] = !opt[Option::OPT4];
    print_options(opt);

    // reset
    opt.set(Option::OPT3, false);
    opt.reset(Option::OPT2);
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
    OptionFlags opt_lhs{Option::OPT1, Option::OPT2};
    OptionFlags opt_rhs_same{Option::OPT1, Option::OPT2};
    OptionFlags opt_rhs_diff{Option::OPT1, Option::OPT3};
    assert(opt_lhs == opt_rhs_same);
    assert(opt_lhs != opt_rhs_diff);

    // | operator
    OptionFlags opt13{Option::OPT1, Option::OPT3};
    OptionFlags opt2{Option::OPT2};
    OptionFlags opt123{Option::OPT1, Option::OPT2, Option::OPT3};
    assert(opt123 == (opt13 | opt2));

    // function args
    cout << endl;
    auto func = [](int a, OptionFlags opt = OptionFlags{}, int b = 0)
    {
        cout << "func: [" << opt << "]" << endl;
    };
    func(1);
    func(1, OptionFlags{Option::OPT1, Option::OPT2});
    func(1, {Option::OPT3, Option::OPT4});
    func(1, OptionFlags{}, 2);
    func(1, no_options, 2);

    //-----------------
    // errors
    //-----------------

    // OtherOptionFlags other_opt{OtherOption::OPT1, OtherOption::OPT2};
    // other_opt.set(Option::OPT3);

    // OtherOptionFlags other_opt{OtherOption::OPT1, OtherOption::OPT2};
    // print_options(other_opt);
}
```

</details>

<details>
<summary>Named arguments</summary>

Libs: [strong_type](https://github.com/rollbear/strong_type)

:arrow_forward: [**Run**](https://godbolt.org/z/YEs7TYKsj)

```cpp
#include <iostream>
#include <string>

#include <strong_type/strong_type.hpp>

using FirstName = strong::type<std::string, struct FirstName_tag>;
using LastName = strong::type<std::string, struct LastName_tag>;

auto func(const FirstName& first_name, const LastName& last_name) -> void
{
    std::cout << "FirstName: " << value_of(first_name) << std::endl;
    std::cout << "LastName: " << value_of(last_name) << std::endl;
}

auto main() -> int
{
    func(FirstName{"John"}, LastName{"Doe"});
}
```

</details>

<details>
<summary>Pointers and const</summary>

| Declaration syntax      | Description                | Reassign?              | Modify target?         |
|-------------------------|----------------------------|:----------------------:|:----------------------:|
| **`const Type*`**       | **pointer-to**-const       | :white_check_mark: Yes | No                     |
| `Type const*`           | **pointer-to**-const       | :white_check_mark: Yes | No                     |
| **`Type* const`**       | const **pointer**          | No                     | :white_check_mark: Yes |
| **`const Type* const`** | const **pointer-to**-const | No                     | No                     |
| `Type const* const`     | const **pointer-to**-const | No                     | No                     |

</details>

<details>
<summary>Type alias</summary>

[(Reference) Type alias](https://en.cppreference.com/w/cpp/language/type_alias)

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

<details>
<summary>Universal reference with type constrains</summary>

[(Reddit) A syntax for universal references of concrete types](https://www.reddit.com/r/cpp/comments/hyfz76/a_syntax_for_universal_references_of_concrete/)

```cpp
#include <concepts>

template<std::convertible_to<double> T>
auto convertible_to_double(T&& x) -> void {...}
```

```cpp
#include <concepts>

template<typename T>
requires std::same_as<std::decay_t<T>, std::string>
auto same_as_string_1(T&& x) -> void {...}
```

```cpp
#include <concepts>

template<typename T1, typename T2>
concept same_type = std::same_as<std::decay_t<T1>, std::decay_t<T2>>;

template<typename T>
requires same_type<T, std::string>
auto same_as_string_2(T&& x) -> void {...}
```

:arrow_forward: [**Demo**](https://godbolt.org/z/hhbo7f8GT) [[type_info.h](src/type_info.h)]

</details>

## Util

<details>
<summary>Scope guard</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/Eqb3Kov44) [[scope_guard.h](src/scope_guard.h)]

```cpp
#include <iostream>

#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/cpp/src/scope_guard.h>

using std::cout, std::endl;

using vs::util::ScopeGuard;
using vs::util::make_scope_guard;

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

        auto guard1 = ScopeGuard([]() { cout << "guard1" << endl; });

        auto lam2 = []() { cout << "guard2" << endl; };
        auto guard2 = make_scope_guard(lam2);

        auto guard3 = make_scope_guard([]() { cout << "guard3" << endl; });
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

        VS_SCOPE_GUARD{ cout << "additional SCOPE_GUARD" << endl; };

        auto resource = Resource{};
        VS_SCOPE_GUARD{ resource.close(); };

        // ...
        resource.use();
        // ...

        cout << "--- scope out 3 ---" << endl;
    }
}
```

</details>
