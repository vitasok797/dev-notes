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

## DLL
* [(StackOverflow) How to make a .lib file when have a .dll file and a header file](https://stackoverflow.com/questions/9360280/how-to-make-a-lib-file-when-have-a-dll-file-and-a-header-file)
* [(StackOverflow) How to generate an import library (LIB-file) from a DLL?](https://stackoverflow.com/questions/9946322/how-to-generate-an-import-library-lib-file-from-a-dll)

## Mixing runtime libraries (dll boundaries)
* [Mixing Multiple Visual Studio Versions in a Program is Evil](https://siomsystems.com/mixing-visual-studio-versions/)
* [Microsoft C runtime library (CRT) reference: C runtime (CRT) and C++ standard library (STL) .lib files](https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-library-features)
* [Allocating and freeing memory across module boundaries](https://devblogs.microsoft.com/oldnewthing/20060915-04/?p=29723)
* [How to Ensure Proper Dynamic Library Boundary Crossing for Objects using Smart Pointers' Custom Deleters](https://www.codeproject.com/Articles/594671/How-to-Ensure-Proper-Dynamic-Library-Boundary-Cros)
* [DLL dos and don’ts](http://rvelthuis.de/articles/articles-dlls.html)
* [Разработка API (контракта) для своей DLL](https://www.gunsmoker.ru/2019/06/developing-DLL-API.html)
* [C++ Binary Compatibility and Pain-Free Upgrades to Visual Studio 2019](https://devblogs.microsoft.com/cppblog/cpp-binary-compatibility-and-pain-free-upgrades-to-visual-studio-2019/)
* [C++ binary compatibility between Visual Studio versions](https://learn.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=msvc-160)
* [(StackOverflow) Do (statically linked) DLLs use a different heap than the main program?](https://stackoverflow.com/questions/10820114/do-statically-linked-dlls-use-a-different-heap-than-the-main-program/10820167)
* [(StackOverflow) ]()
* [(StackOverflow) ]()
* [(StackOverflow) ]()
* [(StackOverflow) ]()
* [(StackOverflow) ]()

## Linters and Analyzers
* [Cppcheck](https://cppcheck.sourceforge.io/)
* Clang:
  * [Clang Format](https://clang.llvm.org/docs/ClangFormat.html)
  * [Clang Static Analyzer](https://clang-analyzer.llvm.org/)
  * [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/) ([habr](https://habr.com/ru/companies/auriga/articles/526486/))
* [CodeChecker](https://pypi.org/project/codechecker/) ([habr](https://habr.com/ru/companies/yadro/articles/838878/))
* cpplint:
  * [cpplint](https://github.com/cpplint/cpplint)
  * [cpplint в Visual Studio (1)](https://demin.ws/blog/russian/2009/07/08/google-coding-standard-in-visual-studio/)
  * [cpplint в Visual Studio (2)](https://heaohan.github.io/blog/2017/12/01/he-aohan-apply-cpplint)
* Visual Studio:
  * [C++ Code analysis in Visual Studio](https://learn.microsoft.com/en-us/cpp/code-quality/?view=msvc-160)
    * [Using Clang-Tidy in Visual Studio](https://learn.microsoft.com/en-us/cpp/code-quality/clang-tidy?view=msvc-160)
    * [Use the C++ Core Guidelines checkers](https://learn.microsoft.com/en-us/cpp/code-quality/using-the-cpp-core-guidelines-checkers?view=msvc-160)
  * [AddressSanitizer](https://learn.microsoft.com/en-us/cpp/sanitizers/asan)
* Sanitizers:
  * [(Habr) Выявление ошибок в работе с памятью в C и C++: Сравниваем Sanitizers и Valgrind](https://habr.com/ru/companies/otus/articles/801123/)
  * <https://github.com/google/sanitizers>
  * [Valgrind](https://valgrind.org/)
  * [Clang UndefinedBehaviorSanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
  * [Clang AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
  * [Clang hardware-assisted AddressSanitizer](https://clang.llvm.org/docs/HardwareAssistedAddressSanitizerDesign.html)

## Visual Studio
* [Visual Studio 2022 Release History](https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-history)
* [C++ Binary Compatibility and Pain-Free Upgrades to Visual Studio 2019](https://devblogs.microsoft.com/cppblog/cpp-binary-compatibility-and-pain-free-upgrades-to-visual-studio-2019/)
* [C++ binary compatibility between Visual Studio versions](https://learn.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=msvc-160)
* [Visual Studio version map](https://gist.github.com/RDCH106/40fe61f447df58c1b9c83a1781374bcd)
* [Portable Build Tools](https://github.com/Data-Oriented-House/PortableBuildTools)
* [(StackOverflow) Integrate Google Protocol Buffers .proto files to Visual Studio](https://stackoverflow.com/questions/11447950/integrate-google-protocol-buffers-proto-files-to-visual-c-2010)

### Visual Studio / Extensions
* Linters and Analyzers:
  * [Clang Power Tools](https://marketplace.visualstudio.com/items?itemName=caphyon.ClangPowerTools) ([site](https://clangpowertools.com/))
* Productivity Power Tools
  [2017/2019](https://marketplace.visualstudio.com/items?itemName=VisualStudioPlatformTeam.ProductivityPowerPack2017)
  [2022](https://marketplace.visualstudio.com/items?itemName=VisualStudioPlatformTeam.ProductivityPowerPack2022)
* Trailing Whitespace Visualizer
  [2019](https://marketplace.visualstudio.com/items?itemName=MadsKristensen.TrailingWhitespaceVisualizer)
  [2022](https://marketplace.visualstudio.com/items?itemName=MadsKristensen.TrailingWhitespace64)
* [CodeMaid](https://marketplace.visualstudio.com/items?itemName=SteveCadwallader.CodeMaid)

## Var
* [C++ developer Roadmap](https://roadmap.sh/cpp)
* [Beautiful Native Libraries](https://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/)
* [Canonical Project Structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html)
* [Ужасное состояние двоичной совместимости Linux](https://habr.com/ru/articles/893720/)
* [How to mix C and C++](https://isocpp.org/wiki/faq/mixing-c-and-cpp)
* [Ускорение сборки C и C++ проектов](https://pvs-studio.ru/ru/blog/posts/cpp/0549/)
