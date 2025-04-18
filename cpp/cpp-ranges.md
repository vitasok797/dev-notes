# C++ / Ranges

## Docs
* std::ranges:
  * [Ranges](https://en.cppreference.com/w/cpp/ranges)
  * [Algorithms](https://en.cppreference.com/w/cpp/algorithm/ranges)
* Range-v3:
  * [Reference](https://ericniebler.github.io/range-v3/)
    ([views](https://ericniebler.github.io/range-v3/index.html#autotoc_md23),
    [actions](https://ericniebler.github.io/range-v3/index.html#autotoc_md25),
    [algorithms](https://ericniebler.github.io/range-v3/group__group-algorithms.html))
  * [Examples](https://ericniebler.github.io/range-v3/md_examples.html)
  * [Sources](https://github.com/ericniebler/range-v3/tree/master/include/range/v3)
* [Microsoft std::ranges tutorial](https://learn.microsoft.com/en-us/cpp/standard-library/ranges)

## Articles
* [(Habr) Примеры C++ кода до и после Ranges](https://habr.com/ru/companies/otus/articles/456452/)
* [(Habr) Алгоритмы диапазонов C++20 — 7 немодифицирующих операций](https://habr.com/ru/companies/skillfactory/articles/706458/)
* [(Habr) Алгоритмы диапазонов C++20 — 11 модифицирующих операций](https://habr.com/ru/companies/skillfactory/articles/707948/)
* [(Habr) Алгоритмы диапазонов C++20 — сортировка, множества, обновления C++23 и прочее](https://habr.com/ru/companies/skillfactory/articles/707946/)
* [A beginner's guide to C++ Ranges and Views](https://hannes.hauswedell.net/post/2019/11/30/range_intro/)
* [A Gentle Introduction to Ranges v3](https://www.daixtrose.de/talks/gentle-intro-to-ranges/talk/A%20Gentle%20Introduction%20to%20Ranges%20v3.pdf)

## Iterators
* [C++20’s Iterator Sentinels](https://www.foonathan.net/2020/03/iterator-sentinel/)
* [C++20 Iterators In-depth](https://hitchcock.codes/blog/cpp-iterators-in-depth)
* [Defining Ranges using Sentinels](https://www.studyplan.dev/pro-cpp/ranges-sentinels)

## Split string
* [(StackOverflow) Split string by range](https://stackoverflow.com/questions/48402558/how-to-split-a-stdstring-into-a-range-v3-of-stdstring-views)
* [Superior String Splitting](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2210r2.html)
* [Implementing a better views::split](https://brevzin.github.io/c++/2020/07/06/split-view/)

## Var
* [Making Your Own Container Compatible With C++20 Ranges](https://www.reedbeta.com/blog/ranges-compatible-containers/)

## Snippets

<details>
<summary>Range as argument</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/hExn53qWf)

```cpp
void func([const] auto[&][&&] rng) {}
```

```cpp
void func_with_concept([const] ranges::range auto[&][&&] rng) {}
void func_with_concept([const] ranges::output_range auto[&][&&] rng) {}

template<typename R>
requires ranges::range<R>
void func_with_concept([const] R[&][&&] rng) {}

template<ranges::range R>
void func_with_concept([const] R[&][&&] rng) {}
```
</details>

<details>
<summary>Range from iterators</summary>

```cpp
auto v = std::vector<int>{1, 2, 3, 4, 5};

auto rng = ranges::subrange(v.begin() + 2, v.end());
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

:arrow_forward: [**Run**](https://godbolt.org/z/j4a31Toqo)

```cpp
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

struct Person
{
    std::string firstname;
    std::string surname;
    int year;
};

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << person.surname << ", " << person.firstname << " was born in " << person.year;
    return os;
}

int main()
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
<summary>String: to_string</summary>

```cpp
auto v = std::vector<int>{1, 2, 3};

auto rng = v | ranges::views::transform([](int i) { return std::to_string(i); });
```
</details>

<details>
<summary>String: trim and uppercase</summary>

```cpp
#include <iomanip>
#include <iostream>
#include <range/v3/all.hpp>

int main()
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
<summary>Contains</summary>

```cpp
auto v = std::vector<int>{1, 2, 3};

std::cout << std::boolalpha;

std::cout << ranges::contains(v, 2) << std::endl;
std::cout << ranges::contains(v, 999) << std::endl;
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
<summary>Vector append</summary>

```cpp
auto v1 = std::vector<int>{1, 2, 3};
auto v2 = std::vector<int>{4, -5, 6};

v1 |= ranges::actions::push_back(v2);
v1 |= ranges::actions::push_back(v2 | ranges::views::remove_if([](int i) { return i < 0; }));
```
</details>

<details>
<summary>Copy to ostream</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/Whbbv4Tnz)

```cpp
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

int main()
{
    auto v = std::vector<int>{1, 2, 3};

    // 1
    std::cout << ranges::views::all(v) << std::endl;

    // 2
    ranges::copy(v, ranges::ostream_iterator<int>(std::cout, "\n"));

    // 3
    using T = ranges::range_value_t<decltype(v)>;
    ranges::copy(v, ranges::ostream_iterator<T>(std::cout, "\n"));
}
```
</details>

<details>
<summary>Projections</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/341nroGr6)

```cpp
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

struct S
{
    std::string name;
    double a = 0.0;
    double b = 0.0;

    double area() const { return a * b; }
};

void demo1()
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

void demo2()
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

int main()
{
    demo1();
    demo2();
}
```
</details>

<details>
<summary>Custom views</summary>

:arrow_forward: [**Run**](https://godbolt.org/z/7TrxrYsvh)

```cpp
#include <format>
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

struct Person
{
    std::string firstname;
    std::string surname;
    int year;

    std::string to_str() const
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

int main()
{
    std::vector<Person> people
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
