# C++ / Libs

## Library lists
* [Awesome C++](https://github.com/fffaraz/awesome-cpp)
* [Awesome HPP](https://github.com/p-ranav/awesome-hpp)
* [A list of open-source C++ libraries](https://en.cppreference.com/w/cpp/links/libs.html)

## Frameworks
* ⭐ [POCO](https://pocoproject.org/) ([doc](https://docs.pocoproject.org/current/index.html))
* ⭐ [GSL](https://github.com/Microsoft/GSL) ([vcpkg](https://vcpkg.io/en/package/ms-gsl))
* [Boost](https://www.boost.org/libraries/latest/categorized/)
* [Qt](https://www.qt.io/product/framework)
* [Abseil](https://abseil.io/)
* [Folly](https://github.com/facebook/folly)

## Text

### Text / String processing
* ⭐ POCO ([StringsAndFormatting](https://pocoproject.org/slides/040-StringsAndFormatting.pdf))
* ⚠️ `Boost Locale?`
* [Boost String Algorithms Library](https://www.boost.org/doc/libs/latest/doc/html/string_algo.html)
* [Boost.Tokenizer](https://www.boost.org/doc/libs/latest/libs/tokenizer/doc/index.html)
* [Abseil Strings](https://abseil.io/docs/cpp/guides/strings)

### Text / Encoding
* ⭐ POCO ([StringsAndFormatting](https://pocoproject.org/slides/040-StringsAndFormatting.pdf))
* ☀️ [Boost.Nowide](https://www.boost.org/doc/libs/latest/libs/nowide/doc/html/index.html) ([standalone](https://github.com/boostorg/nowide))
* ☀️ [ztd-text](https://github.com/soasis/text) ([doc](https://ztdtext.readthedocs.io/en/stable/index.html), [article](https://thephd.dev/any-encoding-ever-ztd-text-unicode-cpp))
* ⚠️ `Boost Locale?`
* [ICU](https://icu.unicode.org/)
* [utfcpp](https://github.com/nemtrif/utfcpp)
* [tiny-utf8](https://github.com/DuffsDevice/tiny-utf8) ([vcpkg](https://vcpkg.io/en/package/tinyutf8))
* [simdutf](https://github.com/simdutf/simdutf)
* [uni-algo](https://github.com/uni-algo/uni-algo)
* [utf8.h](https://github.com/sheredom/utf8.h) ([vcpkg](https://vcpkg.io/en/package/utf8h))
* [utf8proc](https://github.com/JuliaStrings/utf8proc)

### Text / Formatting
* ⭐ <https://github.com/fmtlib/fmt> ([site](https://fmt.dev/), [hackingcpp](https://hackingcpp.com/cpp/libs/fmt.html), [cheatsheet](https://hackingcpp.com/cpp/libs/fmt.png))
* ⭐ <https://github.com/p-ranav/tabulate>
* <https://github.com/p-ranav/pprint>

### Text / Regex
* ⭐ POCO (PCRE2, [StringsAndFormatting](https://pocoproject.org/slides/040-StringsAndFormatting.pdf))
* ☀️ [RE2](https://github.com/google/re2)
* ☀️ [jpcre2](https://github.com/jpcre2/jpcre2)
* [PCRE2](https://github.com/PCRE2Project/pcre2)
* [Boost.Regex](https://www.boost.org/doc/libs/latest/libs/regex/doc/html/index.html)
* [CTRE](https://github.com/hanickadot/compile-time-regular-expressions) ([doc](https://compile-time-regular-expressions.readthedocs.io/))
* [hyperscan](https://www.hyperscan.io/)
* [SRELL](https://github.com/ZimProjects/SRELL)
* Articles:
  * [(Habr) regexp — большие гонки](https://habr.com/ru/articles/812953/)
  * [Performance comparison of regular expression engines](https://zherczeg.github.io/sljit/regex_perf.html)
  * <https://github.com/rust-leipzig/regex-performance>
  * <https://github.com/HFTrader/regex-performance>

### Text / Wildcards
* <https://github.com/zemasoft/wildcards>

### Text / To numeric
* <https://github.com/fastfloat/fast_float>

### Text / I18n
* [Boost.Locale](https://www.boost.org/doc/libs/latest/libs/locale/doc/html/index.html)

## Configuration

### Configuration / Multisource
* POCO ([Configuration](https://pocoproject.org/slides/180-Configuration.pdf))
* [Boost.Program_options](https://www.boost.org/doc/libs/latest/doc/html/program_options.html)
* [Boost.PropertyTree (JSON, XML)](https://www.boost.org/doc/libs/latest/doc/html/property_tree.html)

### Configuration / Argument parsers
* POCO ([Applications](https://pocoproject.org/slides/190-Applications.pdf))
* [Boost.Program_options](https://www.boost.org/doc/libs/latest/doc/html/program_options.html)
* [Abseil Flags](https://abseil.io/docs/cpp/guides/flags)
* <https://github.com/jarro2783/cxxopts>
* <https://github.com/p-ranav/argparse>
* <https://github.com/mmahnic/argumentum>
* <https://github.com/p-ranav/structopt> (~~vcpkg~~ :page_facing_up:)
* <https://github.com/muellan/clipp>
* <https://github.com/adishavit/argh>
* <https://github.com/CLIUtils/CLI11>
* <https://github.com/mshenoda/argy> (~~vcpkg~~ :page_facing_up:)

### Configuration / Environment
* POCO ([PlatformAndEnvironment](https://pocoproject.org/slides/050-PlatformAndEnvironment.pdf))
* [Boost.Program_options](https://www.boost.org/doc/libs/latest/doc/html/program_options.html)
* <https://github.com/ph3at/libenvpp>
* <https://github.com/p-ranav/envy> (~~vcpkg~~ :page_facing_up:)

## Formats

### Formats / XML
* POCO ([XML](https://pocoproject.org/slides/170-XML.pdf))
* [Boost.PropertyTree](https://www.boost.org/doc/libs/latest/doc/html/property_tree.html)
* <https://github.com/zeux/pugixml>
* <https://github.com/leethomason/tinyxml2>
* Articles:
  * [(StackOverflow) Choose XML library](https://stackoverflow.com/questions/9387610/what-xml-parser-should-i-use-in-c/9387612#9387612)

### Formats / JSON
* ⭐ <https://github.com/nlohmann/json> ([vcpkg](https://vcpkg.io/en/package/nlohmann-json))
* POCO ([JSON](https://github.com/pocoproject/poco/tree/main/JSON))
* [Boost.PropertyTree](https://www.boost.org/doc/libs/latest/doc/html/property_tree.html)
* [Boost.JSON](https://www.boost.org/doc/libs/latest/libs/json/doc/html/index.html)
* <https://github.com/Tencent/rapidjson> ([site](https://rapidjson.org/))
* <https://github.com/danielaparker/jsoncons>
* <https://github.com/open-source-parsers/jsoncpp>
* JSON schema validators:
  * <https://github.com/pboettch/json-schema-validator>
  * <https://github.com/tristanpenman/valijson>

### Formats / TOML
* <https://github.com/marzer/tomlplusplus> ([site](https://marzer.github.io/tomlplusplus/))
* <https://github.com/ToruNiina/toml11>
* <https://github.com/skystrife/cpptoml>
* <https://github.com/mayah/tinytoml>

### Formats / YAML
* <https://github.com/jbeder/yaml-cpp>
* <https://github.com/biojppm/rapidyaml>
* <https://github.com/fktn-k/fkYAML>

### Formats / CSV
* ⭐ <https://github.com/vincentlaucsb/csv-parser> ([vcpkg](https://vcpkg.io/en/package/vincentlaucsb-csv-parser))
* <https://github.com/d99kris/rapidcsv>
* <https://github.com/p-ranav/csv2> ([vcpkg](https://vcpkg.io/en/package/p-ranav-csv2))
* <https://github.com/ben-strasser/fast-cpp-csv-parser>
* <https://github.com/danielaparker/jsoncons> ([CSV](https://github.com/danielaparker/jsoncons/blob/master/doc/ref/csv/csv.md))
* <https://github.com/liquidaty/zsv> (~~vcpkg~~)

### Formats / Multiformat serialization
* ☀️ [reflect-cpp: Serialization and validation (JSON, Cap'n Proto, CSV, flexbuffers, msgpack, TOML, XML, YAML)](https://github.com/getml/reflect-cpp) ([vcpkg](https://vcpkg.io/en/package/reflectcpp), [site](https://rfl.getml.com/))
* [Glaze (JSON, CSV, MessagePack, TOML, YAML)](https://github.com/stephenberry/glaze) (C++23)
* <https://github.com/injae/serdepp>
* <https://github.com/USCiLab/cereal> (binary, JSON, XML)

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

### Formats / Base64
* POCO ([Streams](https://pocoproject.org/slides/100-Streams.pdf))
* <https://github.com/tplgy/cppcodec>
* <https://github.com/ReneNyffenegger/cpp-base64>

### Formats / Hashing
* POCO ([RandomCrypto](https://pocoproject.org/slides/060-RandomCrypto.pdf))
* <https://github.com/okdshin/PicoSHA2>
* <https://github.com/weidai11/cryptopp>
* <https://github.com/stbrumme/hash-library>
* <https://github.com/Cyan4973/xxHash> ([site](https://xxhash.com/))
* Articles:
  * [Use Fast Algorithms](https://jolynch.github.io/posts/use_fast_data_algorithms/)

## Types

### Types / Container
* [Boost.Container](https://www.boost.org/doc/libs/latest/doc/html/container.html)
* [Boost.Circular_Buffer](https://www.boost.org/doc/libs/latest/doc/html/circular_buffer.html)
* [Boost.MultiArray](https://www.boost.org/doc/libs/latest/libs/multi_array/doc/index.html)
* [Boost.MultiIndex](https://www.boost.org/doc/libs/latest/libs/multi_index/doc/reference/index.html)
* [Boost.Unordered](https://www.boost.org/doc/libs/latest/libs/unordered/doc/html/unordered/intro.html) ([standalone](https://github.com/MikePopoloski/boost_unordered))
* <https://github.com/serge-sans-paille/frozen>
* <https://github.com/kokkos/mdspan>
* FIFO-ordered associative containers:
  * <https://github.com/Tessil/ordered-map> ([vcpkg](https://vcpkg.io/en/package/tsl-ordered-map))
  * <https://github.com/nlohmann/fifo_map> (~~vcpkg~~ :page_facing_up:)

### Types / Enum
* ⭐ <https://github.com/Neargye/magic_enum> ([vcpkg](https://vcpkg.io/en/package/magic-enum))
* <https://github.com/fix8mt/conjure_enum> ([vcpkg](https://vcpkg.io/en/package/conjure-enum))

### Types / Operators
* [Boost.Operators (Utility)](https://www.boost.org/doc/libs/latest/libs/utility/doc/html/utility/utilities/operators.html) ([vcpkg](https://vcpkg.io/en/package/boost-utility))

### Types / Reflection
* ⭐ <https://github.com/Neargye/nameof>
* [Boost.TypeIndex](https://www.boost.org/doc/libs/latest/doc/html/boost_typeindex.html)
* [Boost.Describe](https://www.boost.org/doc/libs/latest/libs/describe/doc/html/describe.html)
* <https://github.com/felixguendling/cista> ([site](https://cista.rocks/#reflection))

### Types / Scope guard
* [GSL final_action](https://github.com/microsoft/GSL/blob/main/include/gsl/util)
* [Boost.Scope](https://www.boost.org/doc/libs/latest/libs/scope/doc/html/index.html)
* <https://github.com/ricab/scope_guard> ([vcpkg](https://vcpkg.io/en/package/scope-guard))
* <https://github.com/Neargye/scope_guard> (~~vcpkg~~ :page_facing_up:)

### Types / Strong type
* ⭐ <https://github.com/rollbear/strong_type> ([vcpkg](https://vcpkg.io/en/package/strong-type))
* <https://github.com/foonathan/type_safe> ([vcpkg](https://vcpkg.io/en/package/type-safe), [article1](https://www.foonathan.net/2016/10/type-safe/), [article2](https://www.foonathan.net/2016/10/strong-typedefs/))
* <https://github.com/joboccara/NamedType> (dead?, ~~vcpkg~~ :page_facing_up:, [articles](https://www.fluentcpp.com/2016/12/08/strong-types-for-strong-interfaces/))

### Types / Units
* POCO ([Util/Units.h](https://github.com/pocoproject/poco/blob/main/Util/include/Poco/Util/Units.h))
* [Boost.Units](https://www.boost.org/doc/libs/latest/doc/html/boost_units.html)
* <https://github.com/LLNL/units> ([vcpkg](https://vcpkg.io/en/package/llnl-units))
* <https://github.com/mpusz/mp-units> ([vcpkg](https://vcpkg.io/en/package/mp-units))
* <https://github.com/nholthaus/units> ([vcpkg](https://vcpkg.io/en/package/units))
* <https://github.com/bernedom/SI> ([vcpkg](https://vcpkg.io/en/package/si))

## System

### System / Process
* POCO ([Processes](https://pocoproject.org/slides/150-Processes.pdf))
* [Boost.Process](https://www.boost.org/doc/libs/latest/doc/html/process.html)
* [Boost.Interprocess](https://www.boost.org/doc/libs/latest/doc/html/interprocess.html)
* Folly ([Subprocess.h](https://github.com/facebook/folly/blob/main/folly/Subprocess.h))
* <https://github.com/DaanDeMeyer/reproc>

### System / File System
* [\<filesystem\>](https://en.cppreference.com/w/cpp/filesystem.html)
* POCO ([Files](https://pocoproject.org/slides/080-Files.pdf))
* [Boost.Filesystem](https://www.boost.org/doc/libs/latest/libs/filesystem/doc/index.htm)
* Folly ([File.h](https://github.com/facebook/folly/blob/main/folly/File.h))
* <https://github.com/p-ranav/glob> ([vcpkg](https://vcpkg.io/en/package/p-ranav-glob))

## Multithreading
* [\<thread\>](https://en.cppreference.com/w/cpp/thread.html)
* POCO ([Threads](https://pocoproject.org/slides/130-Threads.pdf), [NotificationsEvents](https://pocoproject.org/slides/090-NotificationsEvents.pdf))
* [Boost.Thread](https://www.boost.org/doc/libs/latest/doc/html/thread.html)

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

## GUI
* <https://www.qt.io/product/framework>
* <https://www.wxwidgets.org/>
* <https://github.com/ocornut/imgui>
* <https://github.com/aui-framework/aui> (~~vcpkg~~)

### GUI / Plot
* [Qt Graphs](https://doc.qt.io/qt-6/qtgraphs-index.html) (GPL)
* [QCustomPlot](https://www.qcustomplot.com/) (GPL)
* QWT:
  * <https://qwt.sourceforge.io/>
  * <https://github.com/ig-or/qwtw>
* <https://github.com/wxIshiko/wxCharts>
* <https://github.com/epezent/implot>
* <https://github.com/jimmyorourke/plotlypp> (~~vcpkg~~)

### GUI / Var
* <https://github.com/simulton/QSchematic> (~~vcpkg~~)

## Math
* [Numerics library](https://en.cppreference.com/w/cpp/numeric.html)
* [Boost.Math](https://www.boost.org/doc/libs/latest/libs/math/doc/html/index.html)
* [Boost.Icl (Interval Container Library)](https://www.boost.org/doc/libs/latest/libs/icl/doc/html/index.html)
* [Boost.Interval](https://www.boost.org/doc/libs/latest/libs/numeric/interval/doc/interval.htm)
* [Intel MKL](https://vcpkg.io/en/package/intel-mkl)

### Math / Expressions
* ☀️ <https://github.com/ArashPartow/exprtk> ([doc](https://www.partow.net/programming/exprtk/index.html))
* <https://github.com/codeplea/tinyexpr>
* <https://github.com/Blake-Madden/tinyexpr-plusplus> (~~vcpkg~~)
* <https://github.com/beltoforion/muparser>
* Articles:
  * <https://github.com/ArashPartow/math-parser-benchmark-project>

## Ranges
* ⭐ [range-v3](https://github.com/ericniebler/range-v3)
* ⭐ [TartanLlama's ranges](https://github.com/TartanLlama/ranges) ([vcpkg](https://vcpkg.io/en/package/tl-ranges))
* <https://github.com/tcbrindle/flux>

## UUID
* POCO ([URIandUUID](https://pocoproject.org/slides/160-URIandUUID.pdf))
* [Boost.Uuid](https://www.boost.org/doc/libs/latest/libs/uuid/doc/html/uuid.html)
* <https://github.com/mariusbancila/stduuid>

## Terminal
* UI:
  * <https://github.com/ArthurSonzogni/FTXUI>
  * <https://github.com/magiblot/tvision>
  * <https://github.com/ggerganov/imtui> (~~vcpkg~~)
  * <https://github.com/a-n-t-h-o-n-y/TermOx> (~~vcpkg~~)
* Progress:
  * <https://github.com/p-ranav/indicators>
  * <https://github.com/oir/barkeep>
  * <https://github.com/gipert/progressbar> (~~vcpkg~~ :page_facing_up:)
* <https://github.com/sakhmatd/rogueutil> (~~vcpkg~~ :page_facing_up:)
* <https://github.com/jupyter-xeus/cpp-terminal> (~~vcpkg~~)
* <https://github.com/Cubified/tuibox> (~~vcpkg~~ :page_facing_up:)

## Signals, Events
* POCO ([NotificationsEvents](https://pocoproject.org/slides/090-NotificationsEvents.pdf))
* [Boost.Signals2](https://www.boost.org/doc/libs/latest/doc/html/signals2.html)
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
  * ☀️ <https://github.com/eProsima/Fast-DDS> ([vcpkg](https://vcpkg.io/en/package/fastdds))
  * <https://github.com/eclipse-cyclonedds/cyclonedds> (vcpkg: [cyclonedds](https://vcpkg.io/en/package/cyclonedds), [cyclonedds-cxx](https://vcpkg.io/en/package/cyclonedds-cxx))
  * <https://github.com/OpenDDS/OpenDDS> (~~vcpkg~~)
* Var:
  * [Boost.Asio (standalone)](https://think-async.com/Asio/) ([vcpkg](https://vcpkg.io/en/package/asio))
  * <https://github.com/zeromq/zyre>
  * <https://github.com/zeroc-ice/ice> ([vcpkg](https://vcpkg.io/en/package/zeroc-ice), GPL)
  * <https://github.com/aregtech/areg-sdk> (vcpkg?)

## Web frameworks
* ☀️ <https://github.com/CrowCpp/crow>
* POCO ([Network](https://pocoproject.org/slides/200-Network.pdf))
* <https://github.com/civetweb/civetweb>
* <https://github.com/yhirose/cpp-httplib>
* <https://github.com/drogonframework/drogon>
* <https://github.com/Stiffstream/restinio>

## Time
* [\<chrono\>](https://en.cppreference.com/w/cpp/chrono.html)
* [Abseil Time](https://abseil.io/docs/cpp/guides/time)

## DB
* POCO [Data (SQLite, MySQL/MariaDB, PostgreSQL)](https://docs.pocoproject.org/current/00200-DataUserManual.html)
* <https://github.com/aminroosta/sqlite_modern_cpp> ([vcpkg](https://vcpkg.io/en/package/sqlite-modern-cpp))
* <https://github.com/SRombauts/SQLiteCpp>
* <https://github.com/bw-hro/sqlitemap> ([vcpkg](https://vcpkg.io/en/package/bw-sqlitemap))
* <https://github.com/getml/sqlgen>

## Shared Libraries
* POCO ([SharedLibraries](https://pocoproject.org/slides/120-SharedLibraries.pdf))
* [Boost.DLL](https://www.boost.org/doc/libs/latest/doc/html/boost_dll.html)

## Bindings
* [SWIG](https://www.swig.org/)
* [Shroud](https://github.com/LLNL/shroud) ([doc](https://shroud.readthedocs.io/))
* [djinni-generator](https://github.com/cross-language-cpp/djinni-generator)
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
* [Boost.LEAF](https://www.boost.org/doc/libs/latest/libs/leaf/doc/html/index.html) ([standalone](https://github.com/boostorg/leaf))
* [Boost.System](https://www.boost.org/doc/libs/latest/libs/system/doc/html/system.html)
* <https://github.com/TartanLlama/expected> ([vcpkg](https://vcpkg.io/en/package/tl-expected))
* <https://github.com/martinmoene/expected-lite>

## Logging
* ⭐ <https://github.com/gabime/spdlog> ([doc](https://github.com/gabime/spdlog/wiki))
* POCO ([Logging](https://pocoproject.org/slides/110-Logging.pdf))
* [Boost.Log v2](https://www.boost.org/doc/libs/latest/libs/log/doc/html/index.html)
* [Abseil Logging](https://abseil.io/docs/cpp/guides/logging)
* <https://github.com/google/glog> ([ng-log](https://github.com/ng-log/ng-log))
* <https://github.com/odygrd/quill>
* <https://github.com/SergiusTheBest/plog>
* <https://github.com/abumq/easyloggingpp>
* <https://github.com/log4cplus/log4cplus>
* <https://logging.apache.org/log4cxx/>
* Articles:
  * [(Habr) Сравнение библиотек логирования](https://habr.com/ru/articles/313686/)

## Debugging
* [Boost.Stacktrace](https://www.boost.org/doc/libs/latest/doc/html/stacktrace.html)
* <https://github.com/foonathan/debug_assert> ([vcpkg](https://vcpkg.io/en/package/debug-assert), [article](https://www.foonathan.net/2016/09/assertions/))
* <https://github.com/renatoGarcia/icecream-cpp>
* <https://github.com/keithpotz/CrashCatch> (~~vcpkg~~ :page_facing_up:)
* <https://github.com/bombela/backward-cpp>

## Testing
* ⭐ <https://github.com/google/googletest> ([vcpkg](https://vcpkg.io/en/package/gtest), [doc](https://google.github.io/googletest/))
* [Boost.Test](https://www.boost.org/doc/libs/latest/libs/test/doc/html/index.html)
* <https://github.com/catchorg/Catch2>
* <https://github.com/doctest/doctest>
* <https://github.com/boost-ext/ut> (~~vcpkg~~ :page_facing_up:)
* <https://github.com/cpputest/cpputest>
* <https://github.com/martinmoene/lest>
* <https://github.com/snitch-org/snitch>
* Mocking:
  * <https://github.com/rollbear/trompeloeil>
  * <https://github.com/eranpeer/FakeIt>
* Articles:
  * [Cpp Unit Testing And Mocking Comparison](https://github.com/dhelper/CppUnitTestingAndMockingComparison)

## Benchmarking
* <https://github.com/google/benchmark>
* <https://github.com/martinus/nanobench>
* <https://github.com/ivafanas/sltbench>
* <https://github.com/DigitalInBlue/Celero>

## WSP
* <https://github.com/CoolProp/CoolProp>
* <https://github.com/thermalogic/SEUIF97>

## Var
* <https://github.com/Dobiasd/FunctionalPlus>
* <https://github.com/ryanhaining/cppitertools>
* [cpp-validator](https://github.com/evgeniums/cpp-validator) (~~vcpkg~~ :page_facing_up:, [article](https://habr.com/ru/articles/525204/))
* [match(it): Pattern-matching library](https://github.com/BowenFu/matchit.cpp) ([vcpkg](https://vcpkg.io/en/package/matchit))
