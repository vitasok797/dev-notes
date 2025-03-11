# C++ / Libs

## Library lists
* [Awesome C++](https://github.com/fffaraz/awesome-cpp)
* [Awesome HPP](https://github.com/p-ranav/awesome-hpp)
* [A list of open-source C++ libraries](https://en.cppreference.com/w/cpp/links/libs)

## Frameworks
* <https://www.boost.org/doc/libs/>
* <https://pocoproject.org/>
* <https://abseil.io/>
* <https://github.com/facebook/folly>
* <https://github.com/Microsoft/GSL> ([vcpkg](https://vcpkg.io/en/package/ms-gsl))

## Text

### String
* :warning: `Boost Locale?`
* [Boost String Algorithms Library](https://www.boost.org/doc/libs/release/doc/html/string_algo.html)
* [Boost.Tokenizer](https://www.boost.org/doc/libs/release/libs/tokenizer/doc/index.html)
* POCO [String](https://github.com/pocoproject/poco/blob/main/Foundation/include/Poco/String.h) [UTF8String](https://github.com/pocoproject/poco/blob/main/Foundation/include/Poco/UTF8String.h) ([slides](https://pocoproject.org/slides/040-StringsAndFormatting.pdf))
* [Abseil Strings](https://abseil.io/docs/cpp/guides/strings)

### Encoding
* :warning: `Boost Locale?`
* :warning: `Найти примеры настроек сборки в одной из библиотек`
* :warning: `Изучить` [ICU](https://icu.unicode.org/)
* :warning: `Изучить` [ztd-text](https://github.com/soasis/text/) ([doc](https://ztdtext.readthedocs.io/en/stable/index.html), [article](https://thephd.dev/any-encoding-ever-ztd-text-unicode-cpp))
* :warning: `Изучить` [utfcpp](https://github.com/nemtrif/utfcpp)
* :warning: `Изучить` [Boost.Nowide](https://www.boost.org/doc/libs/release/libs/nowide/doc/html/index.html) ([standalone](https://github.com/boostorg/nowide))
* :warning: `Изучить` [tiny-utf8](https://github.com/DuffsDevice/tiny-utf8/) ([vcpkg](https://vcpkg.io/en/package/tinyutf8))
* :warning: `Изучить` [simdutf](https://github.com/simdutf/simdutf)
* :warning: `Изучить` [uni-algo](https://github.com/uni-algo/uni-algo)
* :warning: `Изучить` [utf8.h](https://github.com/sheredom/utf8.h)

### Format
* <https://github.com/fmtlib/fmt> ([site](https://fmt.dev/))
* <https://github.com/p-ranav/pprint>
* <https://github.com/p-ranav/tabulate>

### Regex
* :warning: `Boost`
* :warning: `POCO (PCRE)`
* :warning: `ICU?`
* :warning: `Другие`
* <https://github.com/zemasoft/wildcards>

### I18n
* [Boost.Locale](https://www.boost.org/doc/libs/release/libs/locale/doc/html/index.html)

## Configuration

### Common
* [Boost.Program\_options](https://www.boost.org/doc/libs/release/doc/html/program_options.html)
* [Boost.PropertyTree](https://www.boost.org/doc/libs/release/doc/html/property_tree.html)
* POCO ([slides](https://pocoproject.org/slides/180-Configuration.pdf))

### Argument parser
* [Boost.Program\_options](https://www.boost.org/doc/libs/release/doc/html/program_options.html)
* POCO ([slides](https://pocoproject.org/slides/190-Applications.pdf))
* [Abseil Flags](https://abseil.io/docs/cpp/guides/flags)
* <https://github.com/jarro2783/cxxopts>
* <https://github.com/p-ranav/argparse>
* <https://github.com/p-ranav/structopt> (no vcpkg, header-only)
* <https://github.com/muellan/clipp>
* <https://github.com/adishavit/argh>
* <https://github.com/CLIUtils/CLI11>

### Environment
* [Boost.Program\_options](https://www.boost.org/doc/libs/release/doc/html/program_options.html)
* POCO ([slides](https://pocoproject.org/slides/050-PlatformAndEnvironment.pdf))
* <https://github.com/ph3at/libenvpp>
* <https://github.com/p-ranav/envy> (no vcpkg, header-only)

## Formats

### XML
* [Boost.PropertyTree](https://www.boost.org/doc/libs/release/doc/html/property_tree.html)
* POCO ([slides](https://pocoproject.org/slides/170-XML.pdf))
* [(StackOverflow) Choose XML library](https://stackoverflow.com/questions/9387610/what-xml-parser-should-i-use-in-c/9387612#9387612)

### JSON
* [Boost.PropertyTree](https://www.boost.org/doc/libs/release/doc/html/property_tree.html)
* [Boost.JSON](https://www.boost.org/doc/libs/release/libs/json/doc/html/index.html)
* <https://github.com/nlohmann/json> ([vcpkg](https://vcpkg.io/en/package/nlohmann-json))

### TOML
* <https://github.com/marzer/tomlplusplus> ([site](https://marzer.github.io/tomlplusplus/))
* <https://github.com/ToruNiina/toml11>
* <https://github.com/skystrife/cpptoml>
* <https://github.com/mayah/tinytoml>

### CSV
* <https://github.com/ben-strasser/fast-cpp-csv-parser>
* <https://github.com/p-ranav/csv2>
* <https://github.com/d99kris/rapidcsv>

## Data

### Serialization
* <https://protobuf.dev/>
* <https://flatbuffers.dev/>
* <https://github.com/capnproto/capnproto>
* <https://github.com/eyalz800/zpp_bits>
* <https://github.com/fraillt/bitsery>
* <https://github.com/fraillt/cpp_serializers_benchmark>

### Base64
* POCO ([slides](https://pocoproject.org/slides/100-Streams.pdf))
* <https://github.com/tplgy/cppcodec>
* <https://github.com/ReneNyffenegger/cpp-base64>

### Hash
* POCO ([slides](https://pocoproject.org/slides/060-RandomCrypto.pdf))
* <https://github.com/okdshin/PicoSHA2>
* <https://github.com/weidai11/cryptopp>
* <https://github.com/stbrumme/hash-library>
* [Use Fast Algorithms](https://jolynch.github.io/posts/use_fast_data_algorithms/)

## Types

### Common
* <https://github.com/Neargye/magic_enum>
* <https://github.com/foonathan/type_safe> ([vcpkg](https://vcpkg.io/en/package/type-safe))

### Container
* [Boost.Container](https://www.boost.org/doc/libs/release/doc/html/container.html)
* [Boost.Circular\_Buffer](https://www.boost.org/doc/libs/release/doc/html/circular_buffer.html)
* [Boost.MultiArray](https://www.boost.org/doc/libs/release/libs/multi_array/doc/index.html)
* <https://github.com/kokkos/mdspan>

### Units
* <https://github.com/LLNL/units> ([vcpkg](https://vcpkg.io/en/package/llnl-units))
* <https://github.com/mpusz/mp-units> ([vcpkg](https://vcpkg.io/en/package/mp-units))
* <https://github.com/nholthaus/units> ([vcpkg](https://vcpkg.io/en/package/units))
* <https://github.com/bernedom/SI> ([vcpkg](https://vcpkg.io/en/package/si))
* <https://www.boost.org/libs/units>

### Reflection
* <https://github.com/Neargye/nameof>
* [Boost.Describe](https://www.boost.org/doc/libs/release/libs/describe/doc/html/describe.html)
* Boost.Core: [type\_name](https://www.boost.org/doc/libs/release/libs/core/doc/html/core/type_name.html), [is\_same](https://www.boost.org/doc/libs/release/libs/core/doc/html/core/is_same.html)

## System

### Process
* [Boost.Process](https://www.boost.org/doc/libs/release/doc/html/process.html)
* [Boost.Interprocess](https://www.boost.org/doc/libs/release/doc/html/interprocess.html)
* POCO ([slides](https://pocoproject.org/slides/150-Processes.pdf))

### File System
* [\<filesystem\>](https://en.cppreference.com/w/cpp/filesystem)
* [Boost.Filesystem](https://www.boost.org/doc/libs/release/libs/filesystem/doc/index.htm)
* POCO ([slides](https://pocoproject.org/slides/080-Files.pdf))
* <https://github.com/p-ranav/glob> ([vcpkg](https://vcpkg.io/en/package/p-ranav-glob))

## Multithreading

### Threads
* [\<thread\>](https://en.cppreference.com/w/cpp/thread)
* [Boost.Thread](https://www.boost.org/doc/libs/release/doc/html/thread.html)
* POCO ([slides](https://pocoproject.org/slides/130-Threads.pdf))

### Concurrent
* <https://github.com/cameron314/concurrentqueue>
* <https://github.com/cameron314/readerwriterqueue>
* <https://github.com/rigtorp/MPMCQueue>
* <https://github.com/rigtorp/SPSCQueue>
* <https://github.com/max0x7ba/atomic_queue> ([vcpkg](https://vcpkg.io/en/package/atomic-queue))
* [TBB](https://github.com/uxlfoundation/oneTBB)

## Logging
* [Boost.Log v2](https://www.boost.org/doc/libs/release/libs/log/doc/html/index.html)
* POCO ([slides](https://pocoproject.org/slides/110-Logging.pdf))
* [Abseil Logging](https://abseil.io/docs/cpp/guides/logging)
* <https://github.com/google/glog>
* <https://github.com/gabime/spdlog>
* <https://github.com/odygrd/quill>
* <https://github.com/SergiusTheBest/plog>
* <https://github.com/abumq/easyloggingpp>
* <https://github.com/log4cplus/log4cplus>
* <https://logging.apache.org/log4cxx/>

## GUI
* <https://www.qt.io/product/framework>
* <https://www.wxwidgets.org/>

## UUID
* [Boost.Uuid](https://www.boost.org/doc/libs/release/libs/uuid/doc/html/uuid.html)
* POCO ([slides](https://pocoproject.org/slides/160-URIandUUID.pdf))
* <https://github.com/mariusbancila/stduuid>

## CLI
* <https://github.com/p-ranav/indicators>
* <https://github.com/ArthurSonzogni/FTXUI>
* <https://github.com/magiblot/tvision>

## Signals, Events
* [Boost.Signals2](https://www.boost.org/doc/libs/release/doc/html/signals2.html)
* POCO ([slides](https://pocoproject.org/slides/090-NotificationsEvents.pdf))
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
* <https://github.com/eProsima/Fast-DDS> ([vcpkg](https://vcpkg.io/en/package/fastdds))

## Math
* [Numerics library](https://en.cppreference.com/w/cpp/numeric)
* [Boost.Math](https://www.boost.org/doc/libs/release/libs/math/doc/html/index.html)
* [Boost.Icl (Interval Container Library)](https://www.boost.org/doc/libs/release/libs/icl/doc/html/index.html)
* [Boost.Interval](https://www.boost.org/doc/libs/release/libs/numeric/interval/doc/interval.htm)
* [Intel MKL](https://vcpkg.io/en/package/intel-mkl)

## Shared Libraries
* [Boost.DLL](https://www.boost.org/doc/libs/release/doc/html/boost_dll.html)
* POCO ([slides](https://pocoproject.org/slides/120-SharedLibraries.pdf))

## Error handling
* [Boost.Optional](https://www.boost.org/doc/libs/release/libs/optional/doc/html/index.html)
* [Boost.Outcome](https://www.boost.org/doc/libs/release/libs/outcome/doc/html/index.html) ([standalone](https://github.com/ned14/outcome))
* [Boost.LEAF](https://www.boost.org/doc/libs/release/libs/leaf/doc/html/index.html)
* [Boost.System](https://www.boost.org/doc/libs/release/libs/system/doc/html/system.html)
* <https://github.com/foonathan/debug_assert> ([vcpkg](https://vcpkg.io/en/package/debug-assert), [article](https://www.foonathan.net/2016/09/assertions/))
* <https://github.com/TartanLlama/expected> ([vcpkg](https://vcpkg.io/en/package/tl-expected))
* <https://github.com/martinmoene/expected-lite>

## Var
* <https://github.com/ericniebler/range-v3>
* <https://github.com/Dobiasd/FunctionalPlus>
* <https://github.com/CoolProp/CoolProp>
* [cpp-validator](https://github.com/evgeniums/cpp-validator) (no vcpkg, header-only, [article](https://habr.com/ru/articles/525204/))
* [Kaitai Struct](http://kaitai.io/) ([vcpkg](https://vcpkg.io/en/package/kaitai-struct-cpp-stl-runtime))
* [A lightweight header-only pattern-matching library for C++17 with macro-free APIs](https://github.com/BowenFu/matchit.cpp) ([vcpkg](https://vcpkg.io/en/package/matchit))
