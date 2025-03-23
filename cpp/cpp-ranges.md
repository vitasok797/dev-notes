# C++ / Ranges

## Docs
* [Range-v3 reference](https://ericniebler.github.io/range-v3/)

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
        std::cout << index << ": " << value << '\n';
    }
}
```
</details>

## Var
* [C++20’s Iterator Sentinels](https://www.foonathan.net/2020/03/iterator-sentinel/)
* [(Habr) Примеры C++ кода до и после Ranges](https://habr.com/ru/companies/otus/articles/456452/)
