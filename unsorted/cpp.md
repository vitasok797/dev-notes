# Unsorted: C++

## Convert
* https://www.boost.org/doc/libs/latest/libs/numeric/conversion/doc/html/index.html
* https://www.boost.org/doc/libs/latest/libs/convert/doc/html/index.html

## Interval
* [(DeepSeek) Interval](https://chat.deepseek.com/a/chat/s/3456b75e-bbb8-4c40-8106-f070f9b6dff5)
* https://stackoverflow.com/questions/9255887/stl-function-to-test-whether-a-value-is-within-some-range
* https://stackoverflow.com/questions/16339380/c-generic-way-to-check-a-value-in-a-range
* https://labex.io/tutorials/cpp-how-to-detect-out-of-range-values-421164

## Ranges
* https://www.walletfox.com/course/quickref_range_v3.php
* https://hackingcpp.com/cpp/std/range_views_intro.html
* https://hackingcpp.com/cpp/std/range_views.png
* https://stackoverflow.com/questions/67716780/is-it-possible-advisable-to-return-a-range
* https://hannes.hauswedell.net/post/2019/11/30/range_intro/
* Constness:
  * https://godbolt.org/z/3rTz5dsvP
  * https://ericniebler.github.io/range-v3/index.html#tutorial-quick-start
  * https://en.cppreference.com/w/cpp/ranges/filter_view.html
  * https://en.cppreference.com/w/cpp/ranges/reverse_view.html
  * https://www.google.ru/search?q=c%2B%2B+view+range+argument+constness
  * https://www.reddit.com/r/cpp_questions/comments/lnm5ty/taking_a_range_the_concept_as_a_function_argument/
  * https://stackoverflow.com/questions/73444061/passing-stdrangesviews-as-parameters-in-c20/73444148
  * https://github.com/microsoft/STL/issues/1942
  * https://stackoverflow.com/questions/74806106/is-const-broken-with-stdviews

## Error Handling
* https://www.boost.org/doc/libs/latest/libs/outcome/doc/html/index.html
* https://www.boost.org/doc/libs/latest/libs/outcome/doc/html/alternatives.html
* https://www.boost.org/doc/libs/latest/libs/leaf/doc/html/index.html
* https://www.boost.org/doc/libs/latest/libs/optional/doc/html/index.html
* https://github.com/pdimov/expected/blob/master/doc/expected.md
* https://www.boost.org/doc/libs/latest/libs/system/doc/html/system.html
* https://www.boost.org/doc/libs/latest/libs/variant2/doc/html/variant2.html
* https://stackoverflow.com/questions/10176471/is-it-possible-to-convert-a-boostsystemerror-code-to-a-stderror-code
* https://gist.github.com/Vaiz/057cface48d5bb9f399c23d4235d23aa
* https://github.com/ned14/Boost.Expected
* https://blog.tartanllama.xyz/optional-expected/
* http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-1.html ([google translate](https://blog-think--async-com.translate.goog/2010/04/system-error-support-in-c0x-part-1.html?_x_tr_sch=http&_x_tr_sl=en&_x_tr_tl=ru))
* http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-2.html ([google translate](https://blog-think--async-com.translate.goog/2010/04/system-error-support-in-c0x-part-2.html?_x_tr_sch=http&_x_tr_sl=en&_x_tr_tl=ru))

## GSL
* https://www.cppstories.com/2017/10/notnull/
* GSL_SUPPRESS
* Expects/Ensures
* zstring
* final_action
* gsl::narrow, gsl::narrow_cast
* gsl::at

## Structured Binding
* Snippets:
  * Errors (typical) / "Far" objects forwarding
  * Initialization / Structured Binding
  * Type / auto&& resolving
* [(DeepSeek) Structured Binding](https://chat.deepseek.com/a/chat/s/d5354b11-b48b-40b7-b17a-ed92b04c2700)
* https://jguegant.github.io/blogs/tech/structured-bindings.html
* https://blog.petrzemek.net/2017/12/08/when-auto-seemingly-deduces-a-reference-in-cpp/
* https://godbolt.org/z/TEnf33jrM
* https://stackoverflow.com/questions/44695684/structured-bindings-when-something-looks-like-a-reference-and-behaves-similarly/44696826#44696826
* https://stackoverflow.com/questions/44671697/what-are-the-types-of-identifiers-introduced-by-structured-bindings-in-c17/44672220#44672220

## Compare
* https://stackoverflow.com/questions/47466358/what-is-the-spaceship-three-way-comparison-operator-in-c
* https://habr.com/ru/companies/microsoft/articles/458242/
* https://brevzin.github.io/c++/2019/07/28/comparisons-cpp20/#new-operator-abilities
* https://en.cppreference.com/w/cpp/utility.html#Three-way_comparison
* https://en.cppreference.com/w/cpp/language/operator_comparison.html
* https://en.cppreference.com/w/cpp/language/operator_comparison.html#Three-way_comparison
* https://en.cppreference.com/w/cpp/language/default_comparisons.html
* https://godbolt.org/z/bWcc9PoPx
* Вопросы:
  * Для чего еще может использоваться <=>
  * Как сравниваются структуры

## MACROS
* https://blog.tartanllama.xyz/passing-overload-sets/
* https://vittorioromeo.info/index/blog/capturing_perfectly_forwarded_objects_in_lambdas.html
* https://www.reddit.com/r/cpp/comments/mgwfm8/comment/gswydka/
* https://www.reddit.com/r/cpp/comments/mgwfm8/comment/gsz49uj/
* https://stackoverflow.com/questions/27501400/the-implementation-of-stdforward
* https://github.com/rollbear/lift

## CMake
* https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
* https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
* https://habr.com/ru/articles/683204/
* https://www.youtube.com/watch?v=sBP17HQAQjk
* https://www.youtube.com/watch?v=_5weX5mx8hc
* https://habr.com/ru/articles/916620/
* Compiler options:
  * See: [C++ / Guidelines](cpp-guidelines.md) / Signed/unsigned
  * [Compiler Options Hardening Guide for C and C++](https://best.openssf.org/Compiler-Hardening-Guides/Compiler-Options-Hardening-Guide-for-C-and-C++.html)
  * `-Wtype-limits`
  * `-ftrivial-auto-var-init=pattern`, `/RTC1`
  * `-fsanitize=signed-integer-overflow`, `-fsanitize=unsigned-integer-overflow`

## Var
* https://hackingcpp.com/
* [How to properly integrate third party libraries using design patterns in C++ and Java](https://medium.com/techanic/how-to-properly-integrate-third-party-libraries-using-design-patterns-in-c-and-java-a6980f7184f8)
* [Путеводитель C++ программиста по неопределённому поведению](https://pvs-studio.ru/ru/blog/posts/cpp/1129/)
* [Размещение объектов. Часть 1: Основы](https://scrutator.me/post/2014/01/29/objects_memory_layout_p1.aspx)
* [Поиск Кёнига (ADL)](https://dyzzet.ru/a/argument-dependent-lookup/ (советы, https://k0d.cc/storage/books/C/standarty_programmirovaniya_na_c.pdf))
* [Understanding C++ Macros](https://madhawapolkotuwa.medium.com/understanding-c-macros-850ee3f316ca)
* [(Habr) Статья 1: Введение в MV шаблоны](https://habr.com/ru/articles/922980/)

## ⚠️ LearnCpp
* [LearnCpp](https://www.learncpp.com/)
  * 14 - Introduction to Classes
  * 15 - More on Classes
  * 16 - Dynamic arrays: std::vector
  * 17 - Fixed-size arrays: std::array and C-style arrays
  * 18 - Iterators and Algorithms
  * 19 - Dynamic Allocation
  * 20 - Functions
  * 21 - Operator Overloading
  * 22 - Move Semantics and Smart Pointers
  * 23 - Object Relationships
  * 24 - Inheritance
  * 25 - Virtual Functions
  * 26 - Templates and Classes
  * 28 - Input and Output (I/O)

## ⚠️ Dangling references
* https://www.learncpp.com/cpp-tutorial/ref-qualifiers/
* https://raw.githubusercontent.com/rollbear/strong_type/refs/heads/main/include/strong_type/type.hpp
* https://en.cppreference.com/w/cpp/utility/optional/value.html
* https://godbolt.org/z/8xbs9oYY6
* https://godbolt.org/z/sKW846o7e
* https://godbolt.org/z/dfjb6Kq9q https://cppinsights.io/

## ⚠️ vsl
* Add narrow_cast and narrow (https://github.com/microsoft/GSL/blob/main/include/gsl/util, https://github.com/microsoft/GSL/blob/main/include/gsl/narrow)
* Error handling:
  * Options:
    * assert
    * gsl::Expects
    * EXPECTS from vsl/assert.h
    * throw "soft" exception
    * throw "terminate" exception
  * Headers:
    * assert.h
    * error.h (throw nullptr_error)
    * math.h/ftrim (throw logic_error) [demo](https://godbolt.org/z/bsqGP99eK)
    * math.h/ceil_div (assert)
    * ...
* noexcept
