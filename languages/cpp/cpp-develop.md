# C++ / Develop

## Style
* <https://google.github.io/styleguide/cppguide.html>
* <https://github.com/motine/cppstylelineup>
* [(Habr) Руководство Google по стилю в C++](https://habr.com/ru/articles/480422/)
* [(Habr) Руководство Google по стилю в C++ 2](https://habr.com/ru/articles/841552/)
* [(Habr) 90 рекомендаций по стилю написания программ на C++](https://habr.com/ru/articles/172091/)

## VCPKG
* [(MS) vcpkg documentation](https://learn.microsoft.com/en-us/vcpkg/)
* [(Issue) How do I use libraries of vcpkg with cmake?](https://github.com/microsoft/vcpkg/issues/14258#issuecomment-717579819)
* [Using vcpkg in anger](https://codingnest.com/files/Using%20vcpkg%20In%20Anger.pdf)
* [Managing dependencies in a C++ project with vcpkg](https://decovar.dev/blog/2022/10/30/cpp-dependencies-with-vcpkg/)
* [(MS) Using Overlay Triplets: Building dynamic libraries on Linux](https://learn.microsoft.com/en-us/vcpkg/users/examples/overlay-triplets-linux-dynamic)

<details>
<summary>Configure overlay triplets in CMakePresets.json</summary>

```json
"cacheVariables": {
    "VCPKG_OVERLAY_TRIPLETS": "${sourceDir}/triplets"
}
```
</details>

## CMake
* [(Habr) Современный CMake: 10 советов по улучшению скриптов сборки](https://habr.com/ru/articles/330902/)
* [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
* [How to Use CMake Without the Agonizing Pain - Part 2](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-2.html)
* [Managing Compiler Warnings with CMake](https://www.foonathan.net/2018/10/cmake-warnings/)
* [CMake presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
* [CMake useful variables](https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/Useful-Variables)
* [(StackOverflow) Difference between CMAKE_CURRENT_SOURCE_DIR and CMAKE_CURRENT_LIST_DIR](https://stackoverflow.com/questions/15662497/difference-between-cmake-current-source-dir-and-cmake-current-list-dir)

## Testing
* [GoogleTest: Building with CMake](https://google.github.io/googletest/quickstart-cmake.html)
* [(MS) Testing tools in Visual Studio](https://learn.microsoft.com/en-us/visualstudio/test/unit-test-basics?view=vs-2019)
* [Testing With CMake and CTest](https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html)
* [Testing With CTest](https://gitlab.kitware.com/cmake/community/-/wikis/doc/ctest/Testing-With-CTest)
* [Scripting Of CTest](https://gitlab.kitware.com/cmake/community/-/wikis/doc/ctest/Scripting-Of-CTest)
* [Modern CMake: Testing](https://cliutils.gitlab.io/modern-cmake/chapters/testing.html)
* [How to automate testing with CMake, CTest, and gtest](https://cfd.university/learn/automating-cfd-solver-and-library-compilation-using-cmake/how-to-automate-testing-with-cmake-ctest-and-gtest/)
* [(Habr) Просто о сложном — пишем тесты с Google C++ Testing Framework (GTest, GMock)](https://habr.com/ru/articles/667880/)
* [(Habr) Руководство по CMake для разработчиков C++ библиотек](https://habr.com/ru/articles/683204/)

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
  * [(MS) C++ Code analysis in Visual Studio](https://learn.microsoft.com/en-us/cpp/code-quality/?view=msvc-160)
    * [(MS) Using Clang-Tidy in Visual Studio](https://learn.microsoft.com/en-us/cpp/code-quality/clang-tidy?view=msvc-160)
    * [(MS) Use the C++ Core Guidelines checkers](https://learn.microsoft.com/en-us/cpp/code-quality/using-the-cpp-core-guidelines-checkers?view=msvc-160)
  * [(MS) AddressSanitizer](https://learn.microsoft.com/en-us/cpp/sanitizers/asan)
* Sanitizers:
  * [(Habr) Выявление ошибок в работе с памятью в C и C++: Сравниваем Sanitizers и Valgrind](https://habr.com/ru/companies/otus/articles/801123/)
  * <https://github.com/google/sanitizers>
  * [Valgrind](https://valgrind.org/)
  * [Clang UndefinedBehaviorSanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
  * [Clang AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
  * [Clang hardware-assisted AddressSanitizer](https://clang.llvm.org/docs/HardwareAssistedAddressSanitizerDesign.html)
* Includes optimization:
  * [include-what-you-use](https://github.com/include-what-you-use/include-what-you-use)
  * [cppclean](https://github.com/myint/cppclean)

## Visual Studio
* [(MS) Visual Studio 2022 Release History](https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-history)
* [(MS) C++ Binary Compatibility and Pain-Free Upgrades to Visual Studio 2019](https://devblogs.microsoft.com/cppblog/cpp-binary-compatibility-and-pain-free-upgrades-to-visual-studio-2019/)
* [(MS) C++ binary compatibility between Visual Studio versions](https://learn.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=msvc-160)
* [Visual Studio version map](https://gist.github.com/RDCH106/40fe61f447df58c1b9c83a1781374bcd)
* [Portable Build Tools](https://github.com/Data-Oriented-House/PortableBuildTools)
* [(StackOverflow) Integrate Google Protocol Buffers .proto files to Visual Studio](https://stackoverflow.com/questions/11447950/integrate-google-protocol-buffers-proto-files-to-visual-c-2010)

### Visual Studio / Cmake
* [(MS) CMake projects in Visual Studio](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-160)
* [(MS) Open Folder support for C++ build systems in Visual Studio](https://learn.microsoft.com/en-us/cpp/build/open-folder-projects-cpp?view=msvc-160)
* [(MS) Clang/LLVM support in Visual Studio CMake projects](https://learn.microsoft.com/en-us/cpp/build/clang-support-cmake?view=msvc-160)
* [CMake in Visual Studio](https://logins.github.io/programming/2020/05/17/CMakeInVisualStudio.html)

### Visual Studio / Extensions
* Linters and Analyzers:
  * [Clang Power Tools](https://marketplace.visualstudio.com/items?itemName=caphyon.ClangPowerTools) ([site](https://clangpowertools.com/))
* Test adapters:
  * [GoogleTest](https://marketplace.visualstudio.com/items?itemName=ChristianSoltenborn.GoogleTestAdapter)
  * [Catch2](https://marketplace.visualstudio.com/items?itemName=JohnnyHendriks.ext01)
* Productivity Power Tools
  [2017/2019](https://marketplace.visualstudio.com/items?itemName=VisualStudioPlatformTeam.ProductivityPowerPack2017)
  [2022](https://marketplace.visualstudio.com/items?itemName=VisualStudioPlatformTeam.ProductivityPowerPack2022)
* Trailing Whitespace Visualizer
  [2019](https://marketplace.visualstudio.com/items?itemName=MadsKristensen.TrailingWhitespaceVisualizer)
  [2022](https://marketplace.visualstudio.com/items?itemName=MadsKristensen.TrailingWhitespace64)
* Qt Visual Studio Tools
  [2019](https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2019)
  [2022](https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2022)
* [CodeMaid](https://marketplace.visualstudio.com/items?itemName=SteveCadwallader.CodeMaid)

### Visual Studio / Linux
* [(MS) Linux with Visual Studio C++](https://learn.microsoft.com/en-us/cpp/linux/?view=msvc-160)
* [(MS) Tutorial: Create C++ cross-platform projects in Visual Studio](https://learn.microsoft.com/en-us/cpp/build/get-started-linux-cmake?view=msvc-160)
* [(MS) Walkthrough: Build and debug C++ with WSL 2 and Visual Studio 2022](https://learn.microsoft.com/en-us/cpp/build/walkthrough-build-debug-wsl2?view=msvc-160)
* [(MS) Tutorial: Debug a CMake project on a remote Windows machine](https://learn.microsoft.com/en-us/cpp/build/cmake-remote-debugging?view=msvc-160)

## DLL
* [(StackOverflow) How to make a .lib file when have a .dll file and a header file](https://stackoverflow.com/questions/9360280/how-to-make-a-lib-file-when-have-a-dll-file-and-a-header-file)
* [(StackOverflow) How to generate an import library (LIB-file) from a DLL?](https://stackoverflow.com/questions/9946322/how-to-generate-an-import-library-lib-file-from-a-dll)

### DLL / Export
* [Create dlls on Windows without declspec() using new CMake export all feature](https://www.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/)
* [CMake GenerateExportHeader](https://cmake.org/cmake/help/latest/module/GenerateExportHeader.html)
* [(StackOverflow) Error LNK1104: cannot open file 'Debug\MyProjectLib.lib'](https://stackoverflow.com/questions/40739061/error-lnk1104-cannot-open-file-debug-myprojectlib-lib/40743080#40743080)
* [(StackOverflow) Export all symbols when creating a DLL](https://stackoverflow.com/questions/225432/export-all-symbols-when-creating-a-dll/32284832#32284832)
* [(StackOverflow) CMake adds -Dlibname_EXPORTS compile definition](https://stackoverflow.com/questions/27429732/cmake-adds-dlibname-exports-compile-definition)

## Mixing

### Mixing / Languages
* [How to mix C and C++](https://isocpp.org/wiki/faq/mixing-c-and-cpp)

### Mixing / Runtime libraries (dll boundaries)
* Guides:
  * [DLL dos and don’ts](http://rvelthuis.de/articles/articles-dlls.html)
  * [Разработка API (контракта) для своей DLL](https://www.gunsmoker.ru/2019/06/developing-DLL-API.html)
  * [(MS) Allocating and freeing memory across module boundaries](https://devblogs.microsoft.com/oldnewthing/20060915-04/?p=29723)
  * [How to Ensure Proper Dynamic Library Boundary Crossing for Objects using Smart Pointers' Custom Deleters](https://www.codeproject.com/Articles/594671/How-to-Ensure-Proper-Dynamic-Library-Boundary-Cros)
* MSVC:
  * [(MS) C++ Binary Compatibility and Pain-Free Upgrades to Visual Studio 2019](https://devblogs.microsoft.com/cppblog/cpp-binary-compatibility-and-pain-free-upgrades-to-visual-studio-2019/)
  * [(MS) C++ binary compatibility between Visual Studio versions](https://learn.microsoft.com/en-us/cpp/porting/binary-compat-2015-2017?view=msvc-160)
  * [(MS) Microsoft C runtime library (CRT) reference: C runtime (CRT) and C++ standard library (STL) .lib files](https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-library-features)
* [Mixing Multiple Visual Studio Versions in a Program is Evil](https://siomsystems.com/mixing-visual-studio-versions/)
* [(StackOverflow) Do (statically linked) DLLs use a different heap than the main program?](https://stackoverflow.com/questions/10820114/do-statically-linked-dlls-use-a-different-heap-than-the-main-program)
* [(StackOverflow) Using C++ DLLs with different compiler versions](https://stackoverflow.com/questions/331045/using-c-dlls-with-different-compiler-versions)
* [(StackOverflow) How to make consistent dll binaries across VS versions?](https://stackoverflow.com/questions/232926/how-to-make-consistent-dll-binaries-across-vs-versions)
* [(StackOverflow) C++ test if two DLLs share the same heap](https://stackoverflow.com/questions/73973154/c-test-if-two-dlls-share-the-same-heap)

### Mixing / Mixed compilers linkage
* <https://gitlab.kitware.com/cmake/cmake/-/issues/25533>
* <https://gitlab.kitware.com/cmake/cmake/-/issues/25598>
* <https://gitlab.kitware.com/cmake/cmake/-/issues/25620>
* <https://stackoverflow.com/questions/1867745/cmake-use-a-custom-linker>

## Speed up build
* [CMake target_precompile_headers](https://cmake.org/cmake/help/latest/command/target_precompile_headers.html)
* [Ускорение сборки C и C++ проектов](https://pvs-studio.ru/ru/blog/posts/cpp/0549/)
* [(Habr) Ускорение сборки проекта на CMake+GCC: предварительная компиляция заголовочных файлов](https://habr.com/ru/articles/503302/)
* [(Youtube) Why Is My C++ Build So Slow? Compilation Profiling and Visualization](https://www.youtube.com/watch?v=Oih3K-3eZ4Y)

## Var
* [C++ developer Roadmap](https://roadmap.sh/cpp)
* [Beautiful Native Libraries](https://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/)
* [Canonical Project Structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html)
* [Ужасное состояние двоичной совместимости Linux](https://habr.com/ru/articles/893720/)
* [Compiler Options Hardening Guide for C and C++](https://best.openssf.org/Compiler-Hardening-Guides/Compiler-Options-Hardening-Guide-for-C-and-C++.html)
