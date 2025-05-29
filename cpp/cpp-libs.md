# C++ / Libs

## Library lists
* [Awesome C++](https://github.com/fffaraz/awesome-cpp)
* [Awesome HPP](https://github.com/p-ranav/awesome-hpp)
* [A list of open-source C++ libraries](https://en.cppreference.com/w/cpp/links/libs)

## Frameworks
* [Boost](https://www.boost.org/libraries/latest/categorized/)
* [POCO](https://pocoproject.org/) ([doc](https://docs.pocoproject.org/current/index.html))
* [Abseil](https://abseil.io/)
* [Folly](https://github.com/facebook/folly)
* [GSL](https://github.com/Microsoft/GSL) ([vcpkg](https://vcpkg.io/en/package/ms-gsl)), [gsl-lite](https://github.com/gsl-lite/gsl-lite/)

## Text

### Text / Strings
* ⚠️ `Boost Locale?`
* [Boost String Algorithms Library](https://www.boost.org/doc/libs/latest/doc/html/string_algo.html)
* [Boost.Tokenizer](https://www.boost.org/doc/libs/latest/libs/tokenizer/doc/index.html)
* POCO ([StringsAndFormatting](https://pocoproject.org/slides/040-StringsAndFormatting.pdf)) ([String.h](https://github.com/pocoproject/poco/blob/main/Foundation/include/Poco/String.h), [UTF8String.h](https://github.com/pocoproject/poco/blob/main/Foundation/include/Poco/UTF8String.h))
* [Abseil Strings](https://abseil.io/docs/cpp/guides/strings)

### Text / Encoding
* ⚠️ `Boost Locale?`
* ⚠️ `Найти примеры настроек сборки в одной из библиотек`
* ⚠️ [ICU](https://icu.unicode.org/)
* ⚠️ [ztd-text](https://github.com/soasis/text) ([doc](https://ztdtext.readthedocs.io/en/stable/index.html), [article](https://thephd.dev/any-encoding-ever-ztd-text-unicode-cpp))
* ⚠️ [utfcpp](https://github.com/nemtrif/utfcpp)
* ⚠️ [Boost.Nowide](https://www.boost.org/doc/libs/latest/libs/nowide/doc/html/index.html) ([standalone](https://github.com/boostorg/nowide))
* ⚠️ [tiny-utf8](https://github.com/DuffsDevice/tiny-utf8) ([vcpkg](https://vcpkg.io/en/package/tinyutf8))
* ⚠️ [simdutf](https://github.com/simdutf/simdutf)
* ⚠️ [uni-algo](https://github.com/uni-algo/uni-algo)
* ⚠️ [utf8.h](https://github.com/sheredom/utf8.h) ([vcpkg](https://vcpkg.io/en/package/utf8h))

### Text / Formating
* <https://github.com/fmtlib/fmt> ([site](https://fmt.dev/), [cheatsheet](https://hackingcpp.com/cpp/libs/fmt.png))
* <https://github.com/p-ranav/pprint>
* <https://github.com/p-ranav/tabulate>

### Text / Regex
* ⚠️ `Boost`
* ⚠️ `POCO (PCRE)`
* ⚠️ `ICU?`
* ⚠️ `Другие`
* <https://github.com/ZimProjects/SRELL>
* <https://github.com/hanickadot/compile-time-regular-expressions> ([vcpkg](https://vcpkg.io/en/package/ctre), [doc](https://compile-time-regular-expressions.readthedocs.io/))
* <https://github.com/zemasoft/wildcards>
* Articles:
  * [(Habr) regexp — большие гонки](https://habr.com/ru/articles/812953/)

### Text / I18n
* [Boost.Locale](https://www.boost.org/doc/libs/latest/libs/locale/doc/html/index.html)

## Configuration

### Configuration / Multisource
* [Boost.Program\_options](https://www.boost.org/doc/libs/latest/doc/html/program_options.html)
* [Boost.PropertyTree (JSON, XML)](https://www.boost.org/doc/libs/latest/doc/html/property_tree.html)
* POCO ([Configuration](https://pocoproject.org/slides/180-Configuration.pdf))

### Configuration / Argument parser
* [Boost.Program\_options](https://www.boost.org/doc/libs/latest/doc/html/program_options.html)
* POCO ([Applications](https://pocoproject.org/slides/190-Applications.pdf))
* [Abseil Flags](https://abseil.io/docs/cpp/guides/flags)
* <https://github.com/jarro2783/cxxopts>
* <https://github.com/p-ranav/argparse>
* <https://github.com/mmahnic/argumentum>
* <https://github.com/p-ranav/structopt> (no vcpkg, header-only)
* <https://github.com/muellan/clipp>
* <https://github.com/adishavit/argh>
* <https://github.com/CLIUtils/CLI11>

### Configuration / Environment
* [Boost.Program\_options](https://www.boost.org/doc/libs/latest/doc/html/program_options.html)
* POCO ([PlatformAndEnvironment](https://pocoproject.org/slides/050-PlatformAndEnvironment.pdf))
* <https://github.com/ph3at/libenvpp>
* <https://github.com/p-ranav/envy> (no vcpkg, header-only)

## Formats

### Formats / XML
* [Boost.PropertyTree](https://www.boost.org/doc/libs/latest/doc/html/property_tree.html)
* POCO ([XML](https://pocoproject.org/slides/170-XML.pdf))
* <https://github.com/zeux/pugixml>
* <https://github.com/leethomason/tinyxml2>
* Articles:
  * [(StackOverflow) Choose XML library](https://stackoverflow.com/questions/9387610/what-xml-parser-should-i-use-in-c/9387612#9387612)

### Formats / JSON
* [Boost.PropertyTree](https://www.boost.org/doc/libs/latest/doc/html/property_tree.html)
* [Boost.JSON](https://www.boost.org/doc/libs/latest/libs/json/doc/html/index.html)
* POCO ([JSON/Object.h](https://github.com/pocoproject/poco/blob/main/JSON/include/Poco/JSON/Object.h))
* <https://github.com/nlohmann/json> ([vcpkg](https://vcpkg.io/en/package/nlohmann-json))
* <https://github.com/Tencent/rapidjson> ([site](https://rapidjson.org/))
* <https://github.com/stephenberry/glaze>
* <https://github.com/danielaparker/jsoncons>
* <https://github.com/open-source-parsers/jsoncpp>

### Formats / TOML
* <https://github.com/marzer/tomlplusplus> ([site](https://marzer.github.io/tomlplusplus/))
* <https://github.com/ToruNiina/toml11>
* <https://github.com/skystrife/cpptoml>
* <https://github.com/mayah/tinytoml>

### Formats / CSV
* <https://github.com/ben-strasser/fast-cpp-csv-parser>
* <https://github.com/d99kris/rapidcsv>
* <https://github.com/vincentlaucsb/csv-parser> ([vcpkg](https://vcpkg.io/en/package/vincentlaucsb-csv-parser))
* <https://github.com/p-ranav/csv2> ([vcpkg](https://vcpkg.io/en/package/p-ranav-csv2))
* <https://github.com/stephenberry/glaze> ([CSV](https://github.com/stephenberry/glaze/blob/main/docs/csv.md))
* <https://github.com/danielaparker/jsoncons> ([CSV](https://github.com/danielaparker/jsoncons/blob/master/doc/ref/csv/csv.md))

### Formats / Binary serialization
* <https://protobuf.dev/>
* <https://github.com/PragmaTwice/protopuf>
* <https://flatbuffers.dev/>
* <https://github.com/capnproto/capnproto>
* <https://github.com/eyalz800/zpp_bits> ([vcpkg](https://vcpkg.io/en/package/zpp-bits))
* <https://github.com/fraillt/bitsery>
* <https://github.com/p-ranav/alpaca>
* <https://github.com/felixguendling/cista>
* [Kaitai Struct (custom binary format)](https://kaitai.io/) ([vcpkg](https://vcpkg.io/en/package/kaitai-struct-cpp-stl-runtime))
* Articles:
  * [CPP serializers benchmark (bitsery)](https://github.com/fraillt/cpp_serializers_benchmark)
  * [Benchmark comparing various data serialization libraries (thrift, protobuf etc.) for C++](https://github.com/thekvs/cpp-serializers)
  * [Comparison of C++ Serialization Libraries for Graph Data (cista)](https://github.com/felixguendling/cpp-serialization-benchmark)

### Formats / Multiformat serialization
* [reflect-cpp: Serialization and validation (JSON, Cap'n Proto, flexbuffers, msgpack, TOML, XML, YAML)](https://github.com/getml/reflect-cpp) ([vcpkg](https://vcpkg.io/en/package/reflectcpp), [site](https://rfl.getml.com/))
* <https://github.com/injae/serdepp>
* <https://github.com/USCiLab/cereal> (binary, JSON, XML)

### Formats / Base64
* POCO ([Streams](https://pocoproject.org/slides/100-Streams.pdf))
* <https://github.com/tplgy/cppcodec>
* <https://github.com/ReneNyffenegger/cpp-base64>

### Formats / Hashing
* POCO ([RandomCrypto](https://pocoproject.org/slides/060-RandomCrypto.pdf))
* <https://github.com/okdshin/PicoSHA2>
* <https://github.com/weidai11/cryptopp>
* <https://github.com/stbrumme/hash-library>
* Articles:
  * [Use Fast Algorithms](https://jolynch.github.io/posts/use_fast_data_algorithms/)

## Types

### Types / Container
* [Boost.Container](https://www.boost.org/doc/libs/latest/doc/html/container.html)
* [Boost.Circular\_Buffer](https://www.boost.org/doc/libs/latest/doc/html/circular_buffer.html)
* [Boost.MultiArray](https://www.boost.org/doc/libs/latest/libs/multi_array/doc/index.html)
* <https://github.com/kokkos/mdspan>

### Types / Enum
* <https://github.com/Neargye/magic_enum> ([vcpkg](https://vcpkg.io/en/package/magic-enum))
* <https://github.com/fix8mt/conjure_enum> ([vcpkg](https://vcpkg.io/en/package/conjure-enum))

### Types / Reflection
* <https://github.com/Neargye/nameof>
* [Boost.Describe](https://www.boost.org/doc/libs/latest/libs/describe/doc/html/describe.html)
* Boost.Core: [type\_name](https://www.boost.org/doc/libs/latest/libs/core/doc/html/core/type_name.html)
* <https://github.com/felixguendling/cista> ([site](https://cista.rocks/#reflection))

### Types / Scope guard
* [Boost.Scope](https://www.boost.org/doc/libs/latest/libs/scope/doc/html/index.html)
* [GSL final_action](https://github.com/microsoft/GSL/blob/main/include/gsl/util)
* <https://github.com/ricab/scope_guard> ([vcpkg](https://vcpkg.io/en/package/scope-guard))
* <https://github.com/Neargye/scope_guard> (no vcpkg, header-only)

### Types / Strong type
* <https://github.com/rollbear/strong_type> ([vcpkg](https://vcpkg.io/en/package/strong-type))
* <https://github.com/foonathan/type_safe> ([vcpkg](https://vcpkg.io/en/package/type-safe), [article1](https://www.foonathan.net/2016/10/type-safe/), [article2](https://www.foonathan.net/2016/10/strong-typedefs/))
* <https://github.com/joboccara/NamedType> (dead?, no vcpkg, header-only, [articles](https://www.fluentcpp.com/2016/12/08/strong-types-for-strong-interfaces/))

### Types / Type Erasure
* <https://github.com/kelbon/AnyAny> (no vcpkg, header-only)

### Types / Units
* [Boost.Units](https://www.boost.org/doc/libs/latest/doc/html/boost_units.html)
* POCO ([Util/Units.h](https://github.com/pocoproject/poco/blob/main/Util/include/Poco/Util/Units.h))
* <https://github.com/LLNL/units> ([vcpkg](https://vcpkg.io/en/package/llnl-units))
* <https://github.com/mpusz/mp-units> ([vcpkg](https://vcpkg.io/en/package/mp-units))
* <https://github.com/nholthaus/units> ([vcpkg](https://vcpkg.io/en/package/units))
* <https://github.com/bernedom/SI> ([vcpkg](https://vcpkg.io/en/package/si))

## System

### System / Process
* [Boost.Process](https://www.boost.org/doc/libs/latest/doc/html/process.html)
* [Boost.Interprocess](https://www.boost.org/doc/libs/latest/doc/html/interprocess.html)
* POCO ([Processes](https://pocoproject.org/slides/150-Processes.pdf))
* <https://github.com/DaanDeMeyer/reproc>

### System / File System
* [\<filesystem\>](https://en.cppreference.com/w/cpp/filesystem)
* [Boost.Filesystem](https://www.boost.org/doc/libs/latest/libs/filesystem/doc/index.htm)
* POCO ([Files](https://pocoproject.org/slides/080-Files.pdf))
* <https://github.com/p-ranav/glob> ([vcpkg](https://vcpkg.io/en/package/p-ranav-glob))

## Multithreading
* [\<thread\>](https://en.cppreference.com/w/cpp/thread)
* [Boost.Thread](https://www.boost.org/doc/libs/latest/doc/html/thread.html)
* POCO ([Threads](https://pocoproject.org/slides/130-Threads.pdf), [NotificationsEvents](https://pocoproject.org/slides/090-NotificationsEvents.pdf))

### Multithreading / Concurrent queues
* POCO ([NotificationsEvents](https://pocoproject.org/slides/090-NotificationsEvents.pdf))
* <https://github.com/cameron314/concurrentqueue>
* <https://github.com/cameron314/readerwriterqueue>
* <https://github.com/rigtorp/MPMCQueue>
* <https://github.com/rigtorp/SPSCQueue>
* <https://github.com/max0x7ba/atomic_queue> ([vcpkg](https://vcpkg.io/en/package/atomic-queue))

### Multithreading / Coroutines
* <https://github.com/David-Haim/concurrencpp>
* <https://github.com/lewissbaker/cppcoro>
* <https://github.com/qcoro/qcoro>
* <https://github.com/alibaba/async_simple>

### Multithreading / Tasks (async)
* [oneTBB](https://github.com/uxlfoundation/oneTBB) ([doc](https://uxlfoundation.github.io/oneTBB/))
* <https://github.com/David-Haim/concurrencpp>
* <https://github.com/Amanieu/asyncplusplus>

### Multithreading / Var
* <https://github.com/Stiffstream/sobjectizer> (Actor and CSP models)

## Logging
* [Boost.Log v2](https://www.boost.org/doc/libs/latest/libs/log/doc/html/index.html)
* POCO ([Logging](https://pocoproject.org/slides/110-Logging.pdf))
* [Abseil Logging](https://abseil.io/docs/cpp/guides/logging)
* <https://github.com/google/glog>
* <https://github.com/gabime/spdlog>
* <https://github.com/odygrd/quill>
* <https://github.com/SergiusTheBest/plog>
* <https://github.com/abumq/easyloggingpp>
* <https://github.com/log4cplus/log4cplus>
* <https://logging.apache.org/log4cxx/>
* Articles:
  * [(Habr) Сравнение библиотек логирования](https://habr.com/ru/articles/313686/)

## GUI
* <https://www.qt.io/product/framework>
* <https://www.wxwidgets.org/>
* <https://github.com/ocornut/imgui>
* <https://github.com/aui-framework/aui> (no vcpkg)

### GUI / Plot
* <https://github.com/wxIshiko/wxCharts>
* <https://github.com/epezent/implot>

## UUID
* [Boost.Uuid](https://www.boost.org/doc/libs/latest/libs/uuid/doc/html/uuid.html)
* POCO ([URIandUUID](https://pocoproject.org/slides/160-URIandUUID.pdf))
* <https://github.com/mariusbancila/stduuid>

## CLI
* <https://github.com/p-ranav/indicators>
* <https://github.com/ArthurSonzogni/FTXUI>
* <https://github.com/magiblot/tvision>

## Signals, Events
* [Boost.Signals2](https://www.boost.org/doc/libs/latest/doc/html/signals2.html)
* POCO ([NotificationsEvents](https://pocoproject.org/slides/090-NotificationsEvents.pdf))
* <https://github.com/libsigcplusplus/libsigcplusplus> ([vcpkg](https://vcpkg.io/en/package/libsigcpp))
* <https://github.com/palacaze/sigslot> ([vcpkg](https://vcpkg.io/en/package/palsigslot))
* <https://github.com/NoAvailableAlias/nano-signal-slot>
* <https://github.com/wqking/eventpp>
* <https://github.com/libevent/libevent>

## Communication
* gRPC:
  * <https://github.com/grpc/grpc>
  * <https://github.com/Tradias/asio-grpc>
* ZeroMQ:
  * <https://github.com/zeromq/libzmq> ([vcpkg](https://vcpkg.io/en/package/zeromq))
  * <https://github.com/zeromq/cppzmq>
  * <https://github.com/zeromq/azmq>
* NNG:
  * <https://github.com/nanomsg/nng>
  * <https://github.com/cwzx/nngpp>
* DDS:
  * <https://github.com/eProsima/Fast-DDS> ([vcpkg](https://vcpkg.io/en/package/fastdds))

## HTTP servers
* POCO ([Network](https://pocoproject.org/slides/200-Network.pdf))
* <https://github.com/civetweb/civetweb>
* <https://github.com/yhirose/cpp-httplib>
* <https://github.com/CrowCpp/crow>
* <https://github.com/drogonframework/drogon>
* <https://github.com/Stiffstream/restinio>

## Math
* [Numerics library](https://en.cppreference.com/w/cpp/numeric)
* [Boost.Math](https://www.boost.org/doc/libs/latest/libs/math/doc/html/index.html)
* [Boost.Icl (Interval Container Library)](https://www.boost.org/doc/libs/latest/libs/icl/doc/html/index.html)
* [Boost.Interval](https://www.boost.org/doc/libs/latest/libs/numeric/interval/doc/interval.htm)
* [Intel MKL](https://vcpkg.io/en/package/intel-mkl)

## DB
* POCO [Data (SQLite, MySQL/MariaDB, PostgreSQL)](https://docs.pocoproject.org/current/00200-DataUserManual.html)
* <https://github.com/aminroosta/sqlite_modern_cpp> ([vcpkg](https://vcpkg.io/en/package/sqlite-modern-cpp))
* <https://github.com/SRombauts/SQLiteCpp>
* <https://github.com/bw-hro/sqlitemap> ([vcpkg](https://vcpkg.io/en/package/bw-sqlitemap))

## Shared Libraries
* [Boost.DLL](https://www.boost.org/doc/libs/latest/doc/html/boost_dll.html)
* POCO ([SharedLibraries](https://pocoproject.org/slides/120-SharedLibraries.pdf))

## Bindings
* [SWIG](https://www.swig.org/)
* Python:
  * [Boost.Python](https://www.boost.org/doc/libs/latest/libs/python/doc/html/)
  * <https://github.com/pybind/pybind11>
  * <https://github.com/wjakob/nanobind>

## Scripting
* Lua:
  * <https://www.lua.org> ([vcpkg](https://vcpkg.io/en/package/lua))
  * <https://github.com/LuaJIT/LuaJIT>
  * <https://github.com/vinniefalco/LuaBridge>
  * <https://github.com/kunitoki/LuaBridge3>
  * <https://github.com/luau-lang/luau>

## Error handling
* [Boost.Optional](https://www.boost.org/doc/libs/latest/libs/optional/doc/html/index.html)
* [Boost.Outcome](https://www.boost.org/doc/libs/latest/libs/outcome/doc/html/index.html) ([standalone](https://github.com/ned14/outcome))
* [Boost.LEAF](https://www.boost.org/doc/libs/latest/libs/leaf/doc/html/index.html)
* [Boost.System](https://www.boost.org/doc/libs/latest/libs/system/doc/html/system.html)
* <https://github.com/TartanLlama/expected> ([vcpkg](https://vcpkg.io/en/package/tl-expected))
* <https://github.com/martinmoene/expected-lite>

## Debug
* <https://github.com/foonathan/debug_assert> ([vcpkg](https://vcpkg.io/en/package/debug-assert), [article](https://www.foonathan.net/2016/09/assertions/))
* <https://github.com/renatoGarcia/icecream-cpp>
* <https://github.com/keithpotz/CrashCatch> (no vcpkg, header-only)

## Test
* <https://github.com/google/googletest> ([vcpkg](https://vcpkg.io/en/package/gtest))
* <https://github.com/catchorg/Catch2>
* <https://github.com/doctest/doctest>

## Benchmark
* <https://github.com/google/benchmark>
* <https://github.com/martinus/nanobench>
* <https://github.com/ivafanas/sltbench>
* <https://github.com/DigitalInBlue/Celero>

## Var
* <https://github.com/ericniebler/range-v3>
* <https://github.com/Dobiasd/FunctionalPlus>
* <https://github.com/ryanhaining/cppitertools>
* <https://github.com/CoolProp/CoolProp>
* [cpp-validator](https://github.com/evgeniums/cpp-validator) (no vcpkg, header-only, [article](https://habr.com/ru/articles/525204/))
* [match(it): Pattern-matching library](https://github.com/BowenFu/matchit.cpp) ([vcpkg](https://vcpkg.io/en/package/matchit))
