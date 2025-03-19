# C++ / Snippets

## Aliases

[Type alias](https://en.cppreference.com/w/cpp/language/type_alias):
```cpp
using UserId = int;
using UserAccounts = std::map<UserId, std::vector<Account>>;

// identical to: typedef void (*func)(int, int);
using func = void (*) (int, int);

template<typename T>
using UserAccounts = std::map<UserId, std::vector<T>>;
```

[Namespace alias](https://en.cppreference.com/w/cpp/language/namespace_alias):
```cpp
namespace fbz = foo::bar::baz;
```

## If statement with initializer (C++17)

```cpp
```

## Namespace using

```cpp
```

## Structured Bindings (C++17)

Unpack tuple:
```cpp
#include <tuple>

std::tuple tuple{1, 'a', 2.3};

auto [i, c, d] = tuple;
auto& [i, c, d] = tuple;
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
auto& [i, c, d] = f;
```

Unpack map:
```cpp
#include <map>

for (auto&& [k, v] : std::map<std::string, int>{{"hello", 1}, {"world", 2}}) ...
```
