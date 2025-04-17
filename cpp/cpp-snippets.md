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
</details>

<details>
<summary>Constructor with default arguments</summary>

```cpp
#include <string>

class Employee
{
public:
    Employee(std::string name, int id = default_id) :
        name_{std::move(name)},
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
<summary>Constructors and inheritance: hierarchy</summary>

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
<summary>Constructors and inheritance: import</summary>

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
<summary>Static/const fields</summary>

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

:arrow_forward: [**Run**](https://godbolt.org/z/MEdMY1b9e)

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
<summary>Template class constructors/methods with T&& args</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/frqz64xsh)

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

    // SURPRISE!!!
    // Catches only rvalues
    // T&& is rvalue ref of type T (not forwarding/universal ref)
    // So we need additional TestClass1(const T&) constructor
    // Note: both std::move and std::forward are acceptable
    TestClass1(T&& x) : x_{std::forward<T>(x)}
    {
        std::cout << "TestClass1 [T&&]";
        std::cout << (std::is_rvalue_reference_v<decltype(x)> ? " rvalue_ref" : "");
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
        std::cout << (std::is_rvalue_reference_v<decltype(x)> ? " rvalue_ref" : "");
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

[Source](src/object_watcher.h)

:arrow_forward: [**Demo**](https://godbolt.org/z/EjcqW9M3x)
</details>

<details>
<summary>Show deducted type</summary>

[(StackOverflow) Using 'auto' type deduction - how to find out what type the compiler deduced?](https://stackoverflow.com/questions/38820579/using-auto-type-deduction-how-to-find-out-what-type-the-compiler-deduced)

```cpp
struct {} _ = ...
```
</details>

<details>
<summary>Type info</summary>

[Source](src/type_info.h)

:arrow_forward: [**Demo**](https://godbolt.org/z/67rd4PoWa)
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
<summary>Dispatch table</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/zY6j8Gnse)

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

    std::map<const char, std::function<double(double, double)>> disp_table
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

:arrow_forward: [**Run**](https://godbolt.org/z/W71MMcabY)

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
p_nums = std::make_unique<std::vector<int>>(nums);
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

:arrow_forward: [**Run**](https://godbolt.org/z/T1nv85b7G)

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
    std::vector<Rect> v1
    {
        {"bbb", 1.0, 2.0},
        {"aaa", 11.0, 220.0},
        {"ccc", 12.0, 22.0}
    };

    print_range_with_proj(v1, &Rect::name);
    print_range_with_proj(v1, &Rect::area);
    print_range_with_proj(v1, [](const Rect& rect) { return rect.a + rect.b; });

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

## Initialization

<details>
<summary>Initialization with a temporary :confused:</summary>

[(StackOverflow) Why do I not get guaranteed copy elision with std::tuple?](https://stackoverflow.com/questions/63560015/why-do-i-not-get-guaranteed-copy-elision-with-stdtuple/63560206#63560206)

:arrow_forward: [**Run**](https://godbolt.org/z/7cGEM3ETb)

```cpp
std::tuple<int, Watcher>{42, 1};  // inplace
std::tuple<int, Watcher>{42, {1}};  // COPY
std::tuple<int, Watcher>{42, Watcher{1}};  // move
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

## String

<details>
<summary>String builder</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/fYsc3b4nn)

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
<summary>:warning: auto&& resolving</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/qYbG51vzd)

```cpp
#include <map>
#include <tuple>
#include <vector>

void test_scalar()
{
    int x = 0;
    auto&& x1 = x;
    // int& x1

    auto&& x2 = 0;
    // int&& x2
}

void test_tuple_binding_by_uref()
{
    std::tuple tuple{1, 2.0};
    auto&& [x1, y1] = tuple;
    // int& x1, double& y1

    auto&& [x2, y2] = std::tuple{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary tuple)
}

void test_tuple_binding_by_copy()
{
    std::tuple tuple{1, 2.0};
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
    std::vector v{1, 2, 3};
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
    std::map<int, double> m{{1, 10.0}, {2, 20.0}};
    for (auto&& [k, v] : m) {}
    // const int& k, double& v

    for (auto&& [k, v] : std::map<int, double>{{1, 10.0}, {2, 20.0}}) {}
    // !!!
    // const int& k, double& v
}

void test_struct_binding_by_uref()
{
    struct S { int x; double y; };

    S s{1, 2.0};
    auto&& [x1, y1] = s;
    // int& x1, double& y1

    auto&& [x2, y2] = S{1, 2.0};
    // int& x2, double& y2 (lvalue refs to original temporary struct)
}

void test_struct_binding_by_copy()
{
    struct S { int x; double y; };

    S s{1, 2.0};
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

:arrow_forward: [**Run**](https://godbolt.org/z/aefr999Go)

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

enum class OtherOption
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
<summary>Function overload resolution test</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/v3xMbM9z8)
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
<summary>Scope guard</summary>

[Source](src/scope_guard.h)

:arrow_forward: [**Demo**](https://godbolt.org/z/8sx6Th3ss)

```cpp
#include <iostream>

#include <https://raw.githubusercontent.com/vitasok797/dev-notes/refs/heads/main/cpp/src/scope_guard.h>

using namespace vs::util;
using std::cout, std::endl;

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

        Resource resource;
        ScopeGuard scope_guard = [&]() { resource.close(); };

        // ...
        resource.use();
        // ...

        cout << "--- scope out 2 ---" << endl;
    }

    cout << endl;

    {
        cout << "--- scope in 3 ---" << endl;

        VS_SCOPE_GUARD{ cout << "additional SCOPE_GUARD" << endl; };

        Resource resource;
        VS_SCOPE_GUARD{ resource.close(); };

        // ...
        resource.use();
        // ...

        cout << "--- scope out 3 ---" << endl;
    }
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
<summary>Universal reference with type constrains</summary>

[(Reddit) A syntax for universal references of concrete types](https://www.reddit.com/r/cpp/comments/hyfz76/a_syntax_for_universal_references_of_concrete/)

:arrow_forward: [**Run**](https://godbolt.org/z/MfKo5GeT1)

```cpp
#include <concepts>

template<std::convertible_to<double> T>
void func_double(T&& x) {...}
```

```cpp
#include <concepts>

template<typename T>
requires std::same_as<std::decay_t<T>, std::string>
void func_string(T&& x) {...}

int main()
{
    std::string s = "111";
    func_string(s);

    func_string("222");  // error
    func_string<std::string>("222");
    func_string(std::string{"222"});
}
```

```cpp
#include <concepts>

template<typename T1, typename T2>
concept same_type = std::same_as<std::decay_t<T1>, std::decay_t<T2>>;

template<typename T>
requires same_type<T, std::string>
void func_string(T&& x) {...}
```
</details>

## Unil

## Var

<details>
<summary>std::optional</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/oaTc8E7qx)

```cpp
#include <iostream>
#include <optional>
#include <vector>

std::optional<std::string> create(bool is_success)
{
    if (!is_success) return {};  // or std::nullopt;
    return "hello";
}

void test(bool is_success)
{
    std::cout << std::boolalpha;
    std::cout << "--- is_success: " << is_success << " ---" << std::endl;

    // ---------------------------------------------------------------------------

    auto value = create(is_success);

    std::cout << value.value_or("nullopt") << std::endl;

    if (value)
        std::cout << *value << std::endl;

    if (value.has_value())
        std::cout << value.value() << std::endl;

    // ---------------------------------------------------------------------------

    if (auto str = create(is_success); str)
        std::cout << *str << std::endl;

    // ---------------------------------------------------------------------------

    // construct in_place
    const std::optional<std::vector<int>> opt_vec(std::in_place, {1, 2, 3});

    // ---------------------------------------------------------------------------
}

int main()
{
    test(true);
    test(false);
}
```
</details>
