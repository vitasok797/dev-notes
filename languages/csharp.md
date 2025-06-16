# C#

## Style
* <https://docs.microsoft.com/en-us/dotnet/standard/design-guidelines/>
* <https://google.github.io/styleguide/csharp-style.html>

## GUI libs
* [Avalonia](https://avaloniaui.net/)
* [Uno Platform](https://platform.uno/)
* [Qt Bridges](https://www.qt.io/qt-bridges)

## Functional
* [(Habr) Язык C# почти функционален](https://habr.com/ru/companies/piter/articles/321546/)
* [(Habr) Ваш C# уже «функциональный», просто позвольте ему это](https://habr.com/ru/articles/493484/)
* [(Habr) Functional C#: Immutability](https://habr.com/ru/articles/266873/)

## Immutable
* [Immutable Collections](https://learn.microsoft.com/en-us/archive/msdn-magazine/2017/march/net-framework-immutable-collections)
* [How to use immutability in C#](https://www.infoworld.com/article/2258775/how-to-use-immutability-in-csharp.html)
* [C# Immutable Types: Understanding the Attraction](https://blog.ndepend.com/c-sharp-immutable-types-understanding-attraction/)

## ⚠️ Embedding
* MS:
  * [Write a custom .NET host to control the .NET runtime from your native code](https://learn.microsoft.com/en-us/dotnet/core/tutorials/netcore-hosting)
  * [Native hosting](https://github.com/dotnet/runtime/blob/main/docs/design/features/native-hosting.md)
  * [.NET Hosting Sample](https://github.com/dotnet/samples/tree/main/core/hosting)
  * [nethost vcpkg package](https://vcpkg.io/en/package/nethost)
  * [Interoperating with unmanaged code](https://learn.microsoft.com/en-us/dotnet/framework/interop/)
  * [DNNE](https://github.com/AaronRobinsonMSFT/DNNE)
  * Native AOT:
    [Using](https://github.com/dotnet/runtimelab/blob/feature/NativeAOT/docs/using-nativeaot/README.md),
    [Deployment](https://github.com/dotnet/docs/blob/main/docs/core/deploying/native-aot/index.md),
    [Sample](https://github.com/dotnet/samples/tree/main/core/nativeaot)
* MS tickets:
  * [Question / Suggestion: Allow managed exports (UnmanagedCallersOnly) in non AOT scenarios](https://github.com/dotnet/runtime/issues/90126)
  * [Make DllExport attribute to be built-in into .net](https://github.com/dotnet/runtime/issues/37556)
  * [Support PInvoke exports via regular LoadLibrary/etc. without setting up runtime first](https://github.com/dotnet/runtime/issues/3750)
  * [Allow C# to export functions and constants to native code](https://github.com/dotnet/csharplang/discussions/308)
  * [Support single-file distribution](https://github.com/dotnet/runtime/issues/11201)
* StackOverflow:
  * [Search Results: DNNE](https://stackoverflow.com/search?q=dnne)
  * [UnmanagedCallersOnly and struct as return value](https://stackoverflow.com/questions/79381121/unmanagedcallersonly-and-struct-as-return-value)
  * [How to call .NET DLL from Inno Setup using DNNE?](https://stackoverflow.com/questions/72415005/how-to-call-net-dll-from-inno-setup-using-dnne)
  * [C# Delphi Interop handling of strings](https://stackoverflow.com/questions/79393500/c-sharp-delphi-interop-handling-of-strings)
  * [C# DLL (using 3F DLLExport for exporting functions) not debuggable in Delphi application](https://stackoverflow.com/questions/78155240/c-sharp-dll-using-3f-dllexport-for-exporting-functions-not-debuggable-in-delph)
* Reddit:
  * [Embedding .Net core in C++](https://www.reddit.com/r/dotnet/comments/16kqaf9/embedding_net_core_in_c/)
  * [Question: Native Exports .NET 5/6 with DNNE ](https://www.reddit.com/r/dotnet/comments/urkdxr/question_native_exports_net_56_with_dnne/)
  * [Question: .NET 5 Native Export / Export C# Function to C/C++](https://www.reddit.com/r/dotnet/comments/k7t6nb/question_net_5_native_export_export_c_function_to/)
* Habr:
  * [Кроссплатформенное использование классов .Net из неуправляемого кода. Или аналог IDispatch на Linux](https://habr.com/ru/articles/304482/)
  * [Кроссплатформенное использование классов .Net в 1С через Native ВК. Или замена COM на Linux](https://habr.com/ru/articles/304542/)
  * [Кроссплатформенное использование классов .Net в 1С через Native ВК. Или замена COM на Linux II](https://habr.com/ru/articles/307188/)
  * [1С,.Net Core. Динамическая компиляция класса обертки для получения событий .Net объекта в 1С](https://habr.com/ru/articles/309850/)
* Languages:
  * [Import C# Dll in delphi 10.4](https://en.delphipraxis.net/topic/11493-import-c-dll-in-delphi-104/)
  * [Using a .NET Assembly via COM in Delphi](https://blogs.embarcadero.com/using-a-net-assembly-via-com-in-delphi/)
  * [Julia & C# interoperation via Julia embedding](https://github.com/ShuhuaGao/JuliaCSharp/tree/main/Embedding)
* Libs:
  * [Conari](https://github.com/3F/Conari)
  * [bflat](https://github.com/bflattened/bflat)
* [Qt/.NET — Hosting .NET code in a Qt application (1/3)](https://www.qt.io/blog/qt/.net-hosting-.net-code-in-a-qt-application) ([qtdotnet](https://github.com/qt-labs/qtdotnet))
* [Hosting .NET Core Components in Unmanaged C/C++ Process in Windows and Linux](https://www.codeproject.com/Articles/1276328/Hosting-NET-Core-Components-in-Unmanaged-C-Cpluspl)
* [Hosting .NET Web Service in Unmanaged C/C++ Process in Windows and Linux](https://www.codeproject.com/Articles/5344732/Hosting-NET-Web-Service-in-Unmanaged-C-Cplusplus-P)
* [Control .NET runtime from native code](https://dev.to/tvinko/control-net-runtime-from-native-code-473f)
* [Using .NET 7 Native AOT to call .NET functionality in C++](https://joeysenna.com/posts/nativeaot-in-c-plus-plus)
* [Calling C# natively from Rust](https://medium.com/@chyyran/calling-c-natively-from-rust-1f92c506289d)

## Var
* [The 10 Most Common Mistakes in C# Programming](https://www.toptal.com/c-sharp/top-10-mistakes-that-c-sharp-programmers-make)
