# C++ / Develop

## VCPKG
* <https://learn.microsoft.com/en-us/vcpkg/>
* [(Issue) How do I use libraries of vcpkg with cmake?](https://github.com/microsoft/vcpkg/issues/14258#issuecomment-717579819)
* [Using vcpkg in anger](https://codingnest.com/files/Using%20vcpkg%20In%20Anger.pdf)
* [Managing dependencies in a C++ project with vcpkg](https://decovar.dev/blog/2022/10/30/cpp-dependencies-with-vcpkg/)
* [Using Overlay Triplets: Building dynamic libraries on Linux](https://learn.microsoft.com/en-us/vcpkg/users/examples/overlay-triplets-linux-dynamic)

<details>
<summary>Configure overlay triplets in CMakePresets.json</summary>

```json
"cacheVariables": {
    "VCPKG_OVERLAY_TRIPLETS": "${sourceDir}/triplets"
}
```
</details>

## CMake
* <https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-160>
* <https://learn.microsoft.com/en-us/cpp/build/open-folder-projects-cpp?view=msvc-160>
* <https://learn.microsoft.com/en-us/cpp/linux/?view=msvc-160>
* [(Habr) Современный CMake: 10 советов по улучшению скриптов сборки](https://habr.com/ru/articles/330902/)
* [CMake in Visual Studio](https://logins.github.io/programming/2020/05/17/CMakeInVisualStudio.html)
* [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
* [How to Use CMake Without the Agonizing Pain - Part 2](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-2.html)
* [Managing Compiler Warnings with CMake](https://www.foonathan.net/2018/10/cmake-warnings/)
* [CMake presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
* [CMake useful variables](https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/Useful-Variables)
* [(StackOverflow) Difference between CMAKE_CURRENT_SOURCE_DIR and CMAKE_CURRENT_LIST_DIR](https://stackoverflow.com/questions/15662497/difference-between-cmake-current-source-dir-and-cmake-current-list-dir)

## Style
* <https://google.github.io/styleguide/cppguide.html>
* <https://github.com/motine/cppstylelineup>
* [(Habr) Руководство Google по стилю в C++](https://habr.com/ru/articles/480422/)
* [(Habr) Руководство Google по стилю в C++ 2](https://habr.com/ru/articles/841552/)
* [(Habr) 90 рекомендаций по стилю написания программ на C++](https://habr.com/ru/articles/172091/)

## Testing
* <https://github.com/google/googletest> ([vcpkg](https://vcpkg.io/en/package/gtest))
* <https://github.com/catchorg/Catch2>
* <https://github.com/doctest/doctest>

## Benchmarking
* <https://github.com/google/benchmark>
* <https://github.com/martinus/nanobench>
* <https://github.com/ivafanas/sltbench>
* <https://github.com/DigitalInBlue/Celero>

## DLL
* [How to make a .lib file when have a .dll file and a header file](https://stackoverflow.com/questions/9360280/how-to-make-a-lib-file-when-have-a-dll-file-and-a-header-file)

## Linters and Analyzers
* cpplint:
  * [cpplint](https://github.com/cpplint/cpplint)
  * [cpplint в Visual Studio (1)](https://demin.ws/blog/russian/2009/07/08/google-coding-standard-in-visual-studio/)
  * [cpplint в Visual Studio (2)](https://heaohan.github.io/blog/2017/12/01/he-aohan-apply-cpplint)
* Clang:
  * [Clang Format](https://clang.llvm.org/docs/ClangFormat.html)
  * [Clang Static Analyzer](https://clang-analyzer.llvm.org/)
  * [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/)
  * [(Habr) Clang-Tidy для автоматического рефакторинга кода](https://habr.com/ru/companies/auriga/articles/526486/)
* [Cppcheck](https://cppcheck.sourceforge.io/)
* Visual Studio:
  * [C++ Code analysis in Visual Studio](https://learn.microsoft.com/en-us/cpp/code-quality/?view=msvc-160)
  * [C++ Code analysis in Visual Studio: Using Clang-Tidy in Visual Studio](https://learn.microsoft.com/en-us/cpp/code-quality/clang-tidy?view=msvc-160)

## Visual Studio
* [Visual Studio 2022 Release History](https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-history)
* [C++ Binary Compatibility and Pain-Free Upgrades to Visual Studio 2019](https://devblogs.microsoft.com/cppblog/cpp-binary-compatibility-and-pain-free-upgrades-to-visual-studio-2019/)
* [C++ binary compatibility between Visual Studio versions](https://learn.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=msvc-160)
* [Visual Studio version map](https://gist.github.com/RDCH106/40fe61f447df58c1b9c83a1781374bcd)
* [Portable Build Tools](https://github.com/Data-Oriented-House/PortableBuildTools)

### Visual Studio / Extensions
* Linters and Analyzers:
  * [Clang Power Tools](https://marketplace.visualstudio.com/items?itemName=caphyon.ClangPowerTools) ([site](https://clangpowertools.com/))
  * [cpplint](https://marketplace.visualstudio.com/items?itemName=mine.cpplint)
* Productivity Power Tools
  [2017/2019](https://marketplace.visualstudio.com/items?itemName=VisualStudioPlatformTeam.ProductivityPowerPack2017)
  [2022](https://marketplace.visualstudio.com/items?itemName=VisualStudioPlatformTeam.ProductivityPowerPack2022)
* Trailing Whitespace Visualizer
  [2019](https://marketplace.visualstudio.com/items?itemName=MadsKristensen.TrailingWhitespaceVisualizer)
  [2022](https://marketplace.visualstudio.com/items?itemName=MadsKristensen.TrailingWhitespace64)
* [CodeMaid](https://marketplace.visualstudio.com/items?itemName=SteveCadwallader.CodeMaid)

## Var
* [Beautiful Native Libraries](https://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/)
* [Canonical Project Structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html)
