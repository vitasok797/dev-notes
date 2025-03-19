# C++ / Snippets

## Aliases

Type:
```cpp
```

Namespace:
```cpp
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
