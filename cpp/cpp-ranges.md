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
<summary>Range from iterators</summary>

```cpp
#include <vector>
#include <range/v3/all.hpp>

std::vector<int> v{1, 2, 3};

auto rng = ranges::subrange(v.begin() + 1, v.end());
```
</details>

<details>
<summary>Filter</summary>

```cpp
#include <vector>
#include <range/v3/all.hpp>

std::vector<int> v{1, 2, 3, 4, 5, 6};

auto is_even = [](int i) { return i % 2 == 0; };

auto even_numbers = v | ranges::views::filter(is_even);
auto odd_numbers = v | ranges::views::remove_if(is_even);
```
</details>

<details>
<summary>To string</summary>

```cpp
#include <vector>
#include <range/v3/all.hpp>

std::vector<int> v{1, 2, 3};

auto rng = v | ranges::views::transform([](int i) { return std::to_string(i); });
```
</details>

<details>
<summary>Contains</summary>

```cpp
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

std::vector<int> v{1, 2, 3};

std::cout << std::boolalpha;

std::cout << ranges::contains(v, 2) << std::endl;
std::cout << ranges::contains(v, 999) << std::endl;
```
</details>


<details>
<summary>Enumerate</summary>

```cpp
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

std::vector<std::string> v{"A", "B", "C"};

for (const auto [index, value] : ranges::views::enumerate(v))
    std::cout << index << ": " << value << std::endl;
```
</details>

<details>
<summary>Vector append</summary>

```cpp
#include <vector>
#include <range/v3/all.hpp>

std::vector<int> v1{1, 2, 3};
std::vector<int> v2{4, -5, 6};

v1 |= ranges::action::push_back(v2);
v1 |= ranges::action::push_back(v2 | ranges::views::remove_if([](int i){ return i < 0; }));
```
</details>

<details>
<summary>Copy to ostream</summary>

```cpp
#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

std::vector<int> v{1, 2, 3};

// 1
std::cout << ranges::views::all(v);

// 2
ranges::copy(v, ranges::ostream_iterator<int>(std::cout, "\n"));

// 3
using T = ranges::range_value_t<decltype(v)>;
ranges::copy(v, ranges::ostream_iterator<T>(std::cout, "\n"));
```
</details>

<details>
<summary>Range argument</summary>

```cpp
#include <range/v3/all.hpp>

void func(const auto& r);
void func(auto&& r);

void func_with_concept(const ranges::range auto& r);
void func_with_concept(ranges::range auto&& r);
```
</details>
