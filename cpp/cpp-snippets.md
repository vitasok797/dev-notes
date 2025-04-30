# C++ / Snippets

## Class

<details>
<summary>Class: structure</summary>

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

    MyClass(const MyClass&) = default;
    MyClass(MyClass&&) = default;
    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) = default;

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

:warning: Make explicit move operations `noexcept` ([C.66](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c66-make-move-operations-noexcept)):
```cpp
MyClass(MyClass&& other) noexcept {...}
MyClass& operator=(MyClass&& other) noexcept {...}
```

:warning: Inheritance:
| Inheritance | Class                           |
|:-----------:|---------------------------------|
| Yes         | `virtual` and public destructor |
| No          | `final` class                   |

</details>

<details>
<summary>Class: virtual functions</summary>

```cpp
struct A
{
    virtual ~A() = default;
    virtual void foo() [const] = 0;
};

struct B : A
{
    ~B() override;
    void foo() [const] override;
};

struct C final : B
{
    ~C() final;
    void foo() [const] final;
};
```
</details>

<details>
<summary>Class: interface/abstract</summary>

### Interface
```cpp
class ITest
{
public:
    virtual void test1() const = 0;
    virtual void test2() const = 0;
    virtual ~ITest() = default;
};

class Test : public ITest
{
public:
    void test1() const override {...}
    void test2() const override {...}
};
```

:arrow_forward: [**Demo**](https://godbolt.org/z/E97aTccbc)

### Abstract base
```cpp
class AbstractBase
{
public:
    virtual ~AbstractBase() = 0;

    void process() const
    {
        step1();
        step2();
    };

    virtual void step1() const {...}
    virtual void step2() const {...}
};

inline AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase
{
public:
    void step2() const override {...}
};
```

:arrow_forward: [**Demo**](https://godbolt.org/z/n9b5osa9x)

</details>

<details>
<summary>Class: polymorphism</summary>

```cpp
class Base
{
public:
    virtual void run() const = 0;
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    void run() const override {...}
};

void polymorphic_call(const Base& base) {...}
void polymorphic_call(const Base* base) {...}
void polymorphic_call(std::shared_ptr<Base> base) {...}

void ref_and_ptr()
{
    auto derived = Derived{};
    Base& base_ref = derived;
    Base* base_ptr = &derived;
}

void shared_ptr()
{
    // create
    std::shared_ptr<Base> base_shared_ptr = std::make_shared<Derived>();

    // return
    auto return_base_shared_ptr = []() -> std::shared_ptr<Base> { return std::make_shared<Derived>(); };

    // call
    func(*base_shared_ptr);       // (const Base&)
    func(base_shared_ptr.get());  // (const Base*)
    func(base_shared_ptr);        // (std::shared_ptr<Base>)
}

void unique_ptr()
{
    // create
    std::unique_ptr<Base> base_unique_ptr = std::make_unique<Derived>();

    // return
    auto return_base_unique_ptr = []() -> std::unique_ptr<Base> { return std::make_unique<Derived>(); };

    // call
    func(*base_unique_ptr);       // (const Base&)
    func(base_unique_ptr.get());  // (const Base*)
}

void vector_of_unique_ptr()
{
    auto v = std::vector<std::unique_ptr<Base>>{};
    v.push_back(std::make_unique<Derived>());
}
```

:arrow_forward: [**Demo**](https://godbolt.org/z/YWevKsvo4)

</details>

<details>
<summary>Class: static/const fields</summary>

### Summary
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

### Full
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

:arrow_forward: [**Demo**](https://godbolt.org/z/a4jcrPrMo)

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

:arrow_forward: [**Run**](https://godbolt.org/z/xddov143j)

```cpp
#include <iostream>

void print(auto text)
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

int main()
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

:arrow_forward: [**Run**](https://godbolt.org/z/Tb781E4s3)

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

void lf() { cout << endl; }

void test1()
{
    auto w = Watcher{};
    Test1{w};
    lf();

    Test1{Watcher{}};
    lf();
}

void test2()
{
    auto w = Watcher{};
    Test2{w};
    lf();

    Test2{Watcher{}};
    lf();
}

void test3()
{
    auto w = Watcher{};
    Test3<Watcher>{w};
    lf();

    Test3<Watcher>{Watcher{}};
    lf();
}

int main()
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

[Source](src/object_watcher.h)

:arrow_forward: [**Demo** (CtorWatcher)](https://godbolt.org/z/5Yd5TxWhT) \
:arrow_forward: [**Demo** (ObjWatcher)](https://godbolt.org/z/45q6TK5Kx)
</details>

<details>
<summary>Show deducted type</summary>

[(StackOverflow) Using 'auto' type deduction - how to find out what type the compiler deduced?](https://stackoverflow.com/questions/38820579/using-auto-type-deduction-how-to-find-out-what-type-the-compiler-deduced)

```cpp
struct {} _ = ...
```
</details>

<details>
<summary>Type info (+overload resolution test)</summary>

[Source](src/type_info.h)

:arrow_forward: [**Demo**](https://godbolt.org/z/Wcfd717c9)
</details>

## Functional

<details>
<summary>Dispatch table</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/fnhbG7vz7)

```cpp
#include <functional>
#include <iostream>
#include <map>

double add(double a, double b)
{
    return a + b;
}

struct Sub
{
    double operator()(double a, double b)
    {
        return a - b;
    }
};

double mult_three(double a, double b, double c)
{
    return a * b * c;
}

int main()
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

void func_arg(std::function<int(int, int)> f)
{
    int res = f(1, 2);
}
```

```cpp
void func_arg(auto f)
{
    int res = f(1, 2);
}
```

:arrow_forward: [**Demo**](https://godbolt.org/z/W71MMcabY)

</details>

<details>
<summary>Function object</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/7xMds9jjq)

```cpp
#include <iostream>

struct Compare
{
    constexpr bool operator()(const auto& a, const auto& b) const
    {
        return a == b;
    }
};

inline constexpr Compare compare{};

int main()
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
<summary>Projection</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/xb4bxo4EY)

```cpp
#include <functional>
#include <iostream>
#include <vector>

struct Rect
{
    std::string name;
    double a = 0.0;
    double b = 0.0;

    double area() const { return a * b; }
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
void print_range_with_proj(const R& range, P proj = {})
{
    std::cout << "---------------" << std::endl;
    for (const auto& x : range)
    {
        std::cout << std::invoke(proj, x) << std::endl;
    }
};

int main()
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

:arrow_forward: [**Run**](https://godbolt.org/z/exdTYbvsx)

```cpp
#include <iostream>
#include <tuple>

// --------------------------------------------------------

struct ReturnData1 { int i; double d; };

ReturnData1 get_data_1()
{
    return {42, 0.1};
}

// --------------------------------------------------------

auto get_data_2()
{
    struct ReturnData2 { int i; double d; };
    return ReturnData2{42, 0.2};
}

// --------------------------------------------------------

std::tuple<int, double> get_data_3()
{
    return {42, 0.3};
}

// --------------------------------------------------------

int main()
{
    auto res1 = get_data_1();
    std::cout << res1.d << std::endl;

    auto res2 = get_data_2();
    std::cout << res2.d << std::endl;

    auto [_, d] = get_data_3();
    std::cout << d << std::endl;
}
```
</details>

<details>
<summary>std::apply</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/fE8c846Pj)

```cpp
#include <iostream>
#include <tuple>

int sum(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    auto numbers = std::tuple{1, 2, 3};
    std::cout << "apply res: " << std::apply(sum, numbers) << std::endl;
}
```
</details>

<details>
<summary>std::make_from_tuple</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/4andfo1hb)

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

int main()
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
[const] auto[&] x = expr;
[const] auto[&] x = type{expr};
```

Examples:
```cpp
auto i = uint64_t{123};
auto v = std::vector<int>{};
auto get_size = [](const auto& x) { return x.size(); };
```

Heap allocation:
```cpp
auto w = new Widget{};
auto w = std::make_unique<Widget>();
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
for(int i = 0; i < v.size(); ++i)  // BAD
for(size_t i = 0; i < v.size(); ++i)  // BETTER
for(auto i = size_t{}; i < v.size(); ++i)  // GOOD
```

Singned/unsignned cast with helpers:
```cpp
auto x = as_signed(integer_expr);
auto x = as_unsigned(integer_expr);
```

Init by function return value:
```cpp
Gadget get_gadget();

Widget w = get_gadget();  // BAD: implicit conversion Gadget to Widget (creates a temporary)
auto w = get_gadget();  // GOOD: no implicit conversion
auto w = Widget{ get_gadget() };  // GOOD: implicit conversion with intent
```

std::initializer_list issue:
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

Unpack tuple:
```cpp
#include <tuple>

auto tuple = std::tuple{1, 'a', 2.3};

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

auto f = Foo{1, 'a', 2.3};

auto [i, c, d] = f;
```

Unpack map:
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

int main()
{
    std::cout << std::clamp(0.5, 1.0, 2.0) << std::endl;  // 1
    std::cout << std::clamp(1.5, 1.0, 2.0) << std::endl;  // 1.5
    std::cout << std::clamp(2.5, 1.0, 2.0) << std::endl;  // 2
}
```
</details>

<details>
<summary>:warning: Signed/unsigned operations :confused:</summary>

:arrow_forward: [**Demo**](https://godbolt.org/z/5aPxGTEdz)

</details>

## Namespace

<details>
<summary>Inline namespace</summary>

```cpp
#include <iostream>

inline namespace V1
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

namespace V2
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
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
<summary>ostream <<</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/effze1zTY)

```cpp
#include <iostream>

// ----------------------------------------------------------------------------------------------

struct Person
{
    std::string firstname;
    std::string surname;
    int year;
};

inline std::ostream& operator<<(std::ostream& os, const Person& person)
{
    return os << person.surname << " " << person.firstname << " was born in " << person.year;
}

// ----------------------------------------------------------------------------------------------

class PrivatePerson
{
public:
    PrivatePerson(const std::string& alias, int year) : alias_{alias}, year_{year} {};

    friend std::ostream& operator<<(std::ostream& os, const PrivatePerson& person);

private:
    std::string alias_;
    int year_;
};

inline std::ostream& operator<<(std::ostream& os, const PrivatePerson& person)
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

## Std::

<details>
<summary>std::optional</summary>

### Create
```cpp
// inplace
auto opt = std::make_optional<Type>(1, 2);

// move
auto opt = std::optional<Type>{std::move(type_inst)};
auto opt = std::optional<Type>{Type{1, 2}};

// copy
auto opt = std::optional<Type>{type_inst};
```

### Return
```cpp
std::optional<Type> return_opt()
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

### Argument
```cpp
void func(const std::optional<std::string>& arg)
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
void func_nocopy(const vs::util::optional_ref<const std::string> arg)
{
    if (arg)
    {
        auto& value = arg->get();
    }
}

const auto s = std::string{"world"};
func_nocopy(s);
```

### Get value
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

### Usage
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

:arrow_forward: [**Demo** (initialization)](https://godbolt.org/z/3PcKTG431) \
:arrow_forward: [**Demo** (usage)](https://godbolt.org/z/96KqW36xe)

</details>

<details>
<summary>std::tuple</summary>

### Create
```cpp
// inplace (single-arg ctor only)
auto t = std::tuple<int, Watcher>{0, 1};

// move
auto t = std::tuple<int, Watcher>{0, std::move(w)};
auto t = std::tuple<int, Watcher>{0, Watcher{1, 2}};
```

### Return
```cpp
// inplace (single-arg + non-explicit ctor only)
std::tuple<int, Watcher> return_tuple() { return {0, 1}; }

// inplace (single-arg ctor only)
std::tuple<int, Watcher> return_tuple() { return std::tuple<int, Watcher>{0, 1}; }

// move
std::tuple<int, Watcher> return_tuple() { return {0, std::move(w)}; }
std::tuple<int, Watcher> return_tuple() { return {0, Watcher{1, 2}}; }
```

:arrow_forward: [**Demo** (initialization)](https://godbolt.org/z/MET71zdG1)

[(StackOverflow) Why do I not get guaranteed copy elision with std::tuple?](https://stackoverflow.com/questions/63560015/why-do-i-not-get-guaranteed-copy-elision-with-stdtuple/63560206#63560206)

</details>

## String

<details>
<summary>String builder</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/n4nKdqjjW)

```cpp
#include <iostream>
#include <sstream>

void build_string_1()
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

void build_string_2()
{
    auto res = std::string{};

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
<summary>:warning: auto&& resolving</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/qhcsK1GW3)

```cpp
#include <map>
#include <tuple>
#include <vector>

void test_scalar()
{
    auto x = 0;
    auto&& x1 = x;
    // int& x1

    auto&& x2 = 0;
    // int&& x2
}

void test_tuple_binding_by_uref()
{
    auto tuple = std::tuple{1, 2.0};
    auto&& [x1, y1] = tuple;
    // int& x1, double& y1

    auto&& [x2, y2] = std::tuple{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary tuple)
}

void test_tuple_binding_by_copy()
{
    auto tuple = std::tuple{1, 2.0};
    auto [x1, y1] = tuple;
    // int& x1, double& y1 (lvalue refs to tuple copy)

    auto [x2, y2] = std::tuple{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary tuple)
}

void test_vector_el()
{
    auto&& v = std::vector{1, 2, 3};
    // std::vector<int>&& v

    auto&& x = v[0];
    // !!!
    // int& x
}

void test_vector_proxy_el()
{
    auto&& v = std::vector<bool>{true, false, true};
    // std::vector<bool>&& v

    auto&& x = v[0];
    // bool&& x (rvalue ref to temporary proxy object)
}

void test_iteration_vector()
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

void test_iteration_binding_map()
{
    auto m = std::map<int, double>{{1, 10.0}, {2, 20.0}};
    for (auto&& [k, v] : m) {}
    // const int& k, double& v

    for (auto&& [k, v] : std::map<int, double>{{1, 10.0}, {2, 20.0}}) {}
    // !!!
    // const int& k, double& v
}

void test_struct_binding_by_uref()
{
    struct S { int x; double y; };

    auto s = S{1, 2.0};
    auto&& [x1, y1] = s;
    // int& x1, double& y1

    auto&& [x2, y2] = S{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary struct)
}

void test_struct_binding_by_copy()
{
    struct S { int x; double y; };

    auto s = S{1, 2.0};
    auto [x1, y1] = s;
    // int& x1, double& y1 (lvalue refs to struct copy)

    auto [x2, y2] = S{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary struct)
}

int main()
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

### Summary
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

:arrow_forward: [**Run**](https://godbolt.org/z/MTaYK9coG)

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

    static void check(const std::string& desc, ArgType arg_type)
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

void append_range_bad(auto& dest, auto&& range)
{
    for (auto&& el : range)
    {
        dest.push_back(std::forward<decltype(el)>(el));
    }
}

void append_range_good(auto& dest, auto&& range)
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
// void append_range_good_2(auto& dest, auto&& range)
// {
//     for (auto&& el : range)
//     {
//         dest.push_back(std::forward_like<decltype(range)>(el));
//     }
// }

void test_range_for()
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

void append_tuple_bad(auto& dest, auto&& tuple)
{
    auto&& [watcher, _] = tuple;
    dest.push_back(std::forward<decltype(watcher)>(watcher));
}

void append_tuple_good(auto& dest, auto&& tuple)
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

void test_tuple()
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

void append_struct_bad_1(auto& dest, auto&& test_struct)
{
    auto&& [watcher, _] = test_struct;
    dest.push_back(std::forward<decltype(watcher)>(watcher));
}

void append_struct_bad_2(auto& dest, auto&& test_struct)
{
    dest.push_back(std::forward<decltype(test_struct.w)>(test_struct.w));
}

void append_struct_good_1(auto& dest, auto&& test_struct)
{
    dest.push_back(std::forward<decltype(test_struct)>(test_struct).w);
}

void append_struct_good_2(auto& dest, auto&& test_struct)
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

void test_struct()
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

int main()
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

:arrow_forward: [**Run**](https://godbolt.org/z/bMnr4q14c)

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

void print_options(OptionFlags opt)
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

int main()
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
<summary>Named arguments (using strong type)</summary>

Libs: [strong_type](https://github.com/rollbear/strong_type)

:arrow_forward: [**Run**](https://godbolt.org/z/Y9ocj6c8c)

```cpp
#include <iostream>
#include <string>

#include <strong_type/strong_type.hpp>

using FirstName = strong::type<std::string, struct FirstName_tag>;
using LastName = strong::type<std::string, struct LastName_tag>;

void func(const FirstName& first_name, const LastName& last_name)
{
    std::cout << "FirstName: " << first_name.value_of() << std::endl;
    std::cout << "LastName: " << last_name.value_of() << std::endl;
}

int main()
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
<summary>Universal reference with type constrains</summary>

[(Reddit) A syntax for universal references of concrete types](https://www.reddit.com/r/cpp/comments/hyfz76/a_syntax_for_universal_references_of_concrete/)

```cpp
#include <concepts>

template<std::convertible_to<double> T>
void convertible_to_double(T&& x) {...}
```

```cpp
#include <concepts>

template<typename T>
requires std::same_as<std::decay_t<T>, std::string>
void same_as_string_1(T&& x) {...}
```

```cpp
#include <concepts>

template<typename T1, typename T2>
concept same_type = std::same_as<std::decay_t<T1>, std::decay_t<T2>>;

template<typename T>
requires same_type<T, std::string>
void same_as_string_2(T&& x) {...}
```

:arrow_forward: [**Demo**](https://godbolt.org/z/65W1E9Y5x)

</details>

## Util

<details>
<summary>Scope guard</summary>

[Source](src/scope_guard.h)

:arrow_forward: [**Demo**](https://godbolt.org/z/rq66eaTWK)

```cpp
#include <iostream>

#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/cpp/src/scope_guard.h>

using std::cout, std::endl;

using vs::util::ScopeGuard;
using vs::util::make_scope_guard;

struct Resource
{
    Resource() { cout << "resource created" << endl; }
    void use() { cout << "resource using" << endl; }
    void close() { cout << "resource closed" << endl; }
} ;

int main()
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
