# C++ / Ranges

## Docs
* std::ranges: [ranges](https://en.cppreference.com/w/cpp/ranges) [algorithms](https://en.cppreference.com/w/cpp/algorithm/ranges)
* [Range-v3 reference](https://ericniebler.github.io/range-v3/)
* [Microsoft std::ranges tutorial](https://learn.microsoft.com/en-us/cpp/standard-library/ranges)

## Articles
* [(Habr) Примеры C++ кода до и после Ranges](https://habr.com/ru/companies/otus/articles/456452/)
* [(Habr) Алгоритмы диапазонов C++20 — 7 немодифицирующих операций](https://habr.com/ru/companies/skillfactory/articles/706458/)
* [(Habr) Алгоритмы диапазонов C++20 — 11 модифицирующих операций](https://habr.com/ru/companies/skillfactory/articles/707948/)
* [(Habr) Алгоритмы диапазонов C++20 — сортировка, множества, обновления C++23 и прочее](https://habr.com/ru/companies/skillfactory/articles/707946/)

## Iterators
* [C++20’s Iterator Sentinels](https://www.foonathan.net/2020/03/iterator-sentinel/)
* [C++20 Iterators In-depth](https://hitchcock.codes/blog/cpp-iterators-in-depth)
* [Defining Ranges using Sentinels](https://www.studyplan.dev/pro-cpp/ranges-sentinels)

## Split
* [(StackOverflow) Split string by range](https://stackoverflow.com/questions/48402558/how-to-split-a-stdstring-into-a-range-v3-of-stdstring-views)
* [Superior String Splitting](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2210r2.html)
* [Implementing a better views::split](https://brevzin.github.io/c++/2020/07/06/split-view/)

## Var
* [Making Your Own Container Compatible With C++20 Ranges](https://www.reedbeta.com/blog/ranges-compatible-containers/)

## Snippets
<details>
<summary>Enumerate</summary>

```cpp
#include <iostream>
#include <vector>
 
#include <range/v3/view/enumerate.hpp>

int main()
{
    std::vector<std::string> items{"A", "B", "C"};

    for (const auto [index, value] : ranges::views::enumerate(items))
    {
        std::cout << index << ": " << value << std::endl;
    }
}
```
</details>
