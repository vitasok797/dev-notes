# Rust / Libs

## Lists 📌
* [crates.io list](https://crates.io/crates?sort=downloads)
* [lib.rs](https://lib.rs/)
* [Awesome Rust](https://github.com/rust-unofficial/awesome-rust)
* [Blessed.rs](https://blessed.rs/crates)
* [Rust cookbook](https://rust-lang-nursery.github.io/rust-cookbook/)

## Benchmarking
* [criterion](https://crates.io/crates/criterion)
* [divan](https://crates.io/crates/divan)
* Profiling tools:
  * [flamegraph](https://crates.io/crates/flamegraph)
  * [samply](https://crates.io/crates/samply)
* Guides: [Benchmarking](https://nnethercote.github.io/perf-book/benchmarking.html), [Profiling](https://nnethercote.github.io/perf-book/profiling.html)

## Communication
* [tokio](https://crates.io/crates/tokio)
* [tower](https://crates.io/crates/tower)
* ☀️ [interprocess](https://crates.io/crates/interprocess)
* DDS:
  * ☀️ [rustdds](https://crates.io/crates/rustdds)
  * ☀️ [dust_dds](https://crates.io/crates/dust_dds)
  * [cyclors](https://crates.io/crates/cyclors) (CycloneDDS bindings)
  * [hdds](https://crates.io/crates/hdds)
* gRPC:
  * ☀️ [tonic](https://crates.io/crates/tonic)
  * [grpc](https://crates.io/crates/grpc)
* ZeroMQ:
  * [zeromq](https://crates.io/crates/zeromq)
  * [rzmq](https://crates.io/crates/rzmq)

## Configuration
* Command line arguments:
  * [clap](https://crates.io/crates/clap)
  * [structopt](https://crates.io/crates/structopt)
  * [confy](https://crates.io/crates/confy)
* Complex:
  * [config](https://crates.io/crates/config)
  * [figment](https://crates.io/crates/figment)
  * [config-manager](https://crates.io/crates/config-manager)

## Containers
* Maps:
  * Flat:
    * [linear-map](https://crates.io/crates/linear-map)
    * [flat_map](https://crates.io/crates/flat_map)
  * Multi-index:
    * [multi_index_map](https://crates.io/crates/multi_index_map)
    * [bimap](https://crates.io/crates/bimap)
  * Slab:
    * [slab](https://crates.io/crates/slab)
    * [slotmap](https://crates.io/crates/slotmap)
  * Var:
    * [indexmap](https://crates.io/crates/indexmap) (hash table which preserves insertion order)
* [smallvec](https://crates.io/crates/smallvec)

## Data processing
* [polars](https://crates.io/crates/polars)

## DB
* ORM:
  * [diesel](https://crates.io/crates/diesel)
  * [sea-orm](https://crates.io/crates/sea-orm)
* Multi-DB:
  * [sqlx](https://crates.io/crates/sqlx)
* Postgres:
  * [postgres](https://crates.io/crates/postgres)
* Embedded:
  * [rusqlite](https://crates.io/crates/rusqlite) (SQLite)
  * [sled](https://crates.io/crates/sled) (KV)
  * [vsdb](https://crates.io/crates/vsdb)

## Error handling
* ⭐ [thiserror](https://crates.io/crates/thiserror)
* ⭐ [anyhow](https://crates.io/crates/anyhow)

## Expressions
* ☀️ [evalexpr](https://crates.io/crates/evalexpr)
* ☀️ [meval](https://crates.io/crates/meval)
* ☀️ [exprtk_rs](https://crates.io/crates/exprtk_rs)

## File system
* Walk:
  * [glob](https://crates.io/crates/glob)
  * [walkdir](https://crates.io/crates/walkdir)
  * [ignore](https://crates.io/crates/ignore)
* [tempfile](https://crates.io/crates/tempfile)
* [dirs](https://crates.io/crates/dirs) (platform-specific standard locations)
* [which](https://crates.io/crates/which)
* [camino](https://crates.io/crates/camino) (UTF-8 paths)

## Formats
* ☀️ [serde](https://crates.io/crates/serde) (JSON, YAML, TOML, CSV, FlexBuffers):
  * ☀️ [serde_json](https://crates.io/crates/serde_json)
  * YAML:
    * [serde_yaml_ng](https://crates.io/crates/serde_yaml_ng)
    * [yaml_serde](https://crates.io/crates/yaml_serde)
  * [toml](https://crates.io/crates/toml)
  * ☀️ [csv](https://crates.io/crates/csv)
  * [flexbuffers](https://crates.io/crates/flexbuffers)
* FlatBuffers:
  * [flatbuffers](https://crates.io/crates/flatbuffers) ([search](https://crates.io/search?q=FlatBuffers))
* Cap'n Proto:
  * [capnp](https://crates.io/crates/capnp)
* Protobuf:
  * ☀️ [prost](https://crates.io/crates/prost)
  * [protobuf](https://crates.io/crates/protobuf) (v.4+) ([protobuf-team crates](https://crates.io/teams/github:protocolbuffers:protobuf-team))
* XML ([search](https://crates.io/search?q=XML))
* [base64](https://crates.io/crates/base64)

## Git
* [git-version](https://crates.io/crates/git-version)
* [crate-git-revision](https://crates.io/crates/crate-git-revision)

## GUI
* Iced:
  * [iced](https://crates.io/crates/iced)
  * [iced_aw](https://crates.io/crates/iced_aw) (additional widgets)
  * [awesome-iced](https://github.com/iced-rs/awesome-iced)
* [slint](https://crates.io/crates/slint)
* [gtk4-rs](https://crates.io/crates/gtk4)
* [egui](https://crates.io/crates/egui)
* [gpui](https://crates.io/crates/gpui), [gpui-component](https://crates.io/crates/gpui-component)
* Qt:
  * [Qt Bridges](https://www.qt.io/development/qt-bridges)
  * [cxx-qt](https://crates.io/crates/cxx-qt) ([doc](https://kdab.github.io/cxx-qt/book/))
  * [qt_core](https://crates.io/crates/qt_core)
  * [rust_qt_binding_generator](https://crates.io/crates/rust_qt_binding_generator)
  * [qmetaobject](https://crates.io/crates/qmetaobject)
* WebView:
  * [tauri](https://crates.io/crates/tauri)
* Plot:
  * [plotly](https://crates.io/crates/plotly)
  * [plotters](https://crates.io/crates/plotters)
  * [egui_plot](https://crates.io/crates/egui_plot)
  * [plotters-iced](https://crates.io/crates/plotters-iced)

## Hashing
* [digest](https://crates.io/crates/digest) ([supported-algorithms](https://github.com/RustCrypto/hashes?tab=readme-ov-file#supported-algorithms))
* xxhash ([article](https://jolynch.github.io/posts/use_fast_data_algorithms/)):
  * [xxhash-rust](https://crates.io/crates/xxhash-rust)
  * [twox-hash](https://crates.io/crates/twox-hash)
* Hashers for HashSet/HashMap:
  * HashDoS-resistant:
    * std (SipHash 1-3, safest default)
    * [ahash](https://crates.io/crates/ahash) (faster alternative to SipHash)
  * Performance-oriented:
    * [foldhash](https://crates.io/crates/foldhash) (general-purpose default)
    * [rustc-hash](https://crates.io/crates/rustc-hash) (especially for primitive/integer keys)
    * [nohash-hasher](https://crates.io/crates/nohash-hasher) ([nohash](https://crates.io/crates/nohash))

## Log
* [log](https://crates.io/crates/log) facade:
  * [env_logger](https://crates.io/crates/env_logger)
  * [loggerv](https://crates.io/crates/loggerv)
  * [log4rs](https://crates.io/crates/log4rs)
* [slog](https://crates.io/crates/slog)
* [tracing](https://crates.io/crates/tracing)
* Debug:
  * [trace](https://crates.io/crates/trace)

## Multithreading
* Async:
  * [tokio](https://crates.io/crates/tokio)
  * [smol](https://crates.io/crates/smol)
* Channels:
  * [std::sync::mpsc](https://doc.rust-lang.org/std/sync/mpsc/)
  * [crossbeam-channel](https://crates.io/crates/crossbeam-channel)
  * [flume](https://crates.io/crates/flume)
* Parallel computation:
  * [rayon](https://crates.io/crates/rayon)
* Events:
  * ☀️ [rsevents](https://crates.io/crates/rsevents)
  * ☀️ [event-listener](https://crates.io/crates/event-listener)
* [crossbeam](https://crates.io/crates/crossbeam)
* [threadpool](https://crates.io/crates/threadpool)

## Process
* Subprocess:
  * [std::process](https://doc.rust-lang.org/std/process/)
  * [subprocess](https://crates.io/crates/subprocess)
  * [duct](https://crates.io/crates/duct)
* ☀️ Signal handling ([article](https://rust-cli.github.io/book/in-depth/signals.html)):
  * [ctrlc](https://crates.io/crates/ctrlc) ([issue](https://github.com/Detegr/rust-ctrlc/issues/122))
  * [ctrlc2](https://crates.io/crates/ctrlc2)
  * [signal-hook](https://crates.io/crates/signal-hook)
  * [tokio::signal](https://docs.rs/tokio/latest/tokio/signal/) ([issue](https://github.com/tokio-rs/tokio/issues/7039))

## Shared libs
* [libloading](https://crates.io/crates/libloading)

## Scripting
* [mlua](https://crates.io/crates/mlua)
* [rhai](https://crates.io/crates/rhai)
* [rune](https://crates.io/crates/rune)
* [wasmtime](https://crates.io/crates/wasmtime)
* [rustpython](https://crates.io/crates/rustpython)

## System
* [sysinfo](https://crates.io/crates/sysinfo)
* [whoami](https://crates.io/crates/whoami)
* Windows:
  * [winreg](https://crates.io/crates/winreg)
  * [winapi](https://crates.io/crates/winapi)
  * [windows-rs](https://github.com/microsoft/windows-rs) ([tutorial](https://kennykerr.ca/rust-getting-started/)):
    * [windows](https://crates.io/crates/windows)
    * [windows-sys](https://crates.io/crates/windows-sys)
    * [windows-strings](https://crates.io/crates/windows-strings)

## Terminal
* [crossterm](https://crates.io/crates/crossterm)
* [console](https://crates.io/crates/console)
* [dialoguer](https://crates.io/crates/dialoguer)
* Progress:
  * [indicatif](https://crates.io/crates/indicatif)
* TUI:
  * [ratatui](https://crates.io/crates/ratatui)
  * [cursive](https://crates.io/crates/cursive)
* Prompts:
  * [inquire](https://crates.io/crates/inquire)

## Testing
* [rstest](https://crates.io/crates/rstest)

## Text
* Regex:
  * ☀️ [regex](https://crates.io/crates/regex)
  * [fancy-regex](https://crates.io/crates/fancy-regex)
* Unicode:
  * [unicode-normalization](https://crates.io/crates/unicode-normalization)
* Convert:
  * ☀️ [encoding_rs](https://crates.io/crates/encoding_rs)
  * ☀️ [translit](https://crates.io/crates/translit)
* Tabulate:
  * ☀️ [tabled](https://crates.io/crates/tabled)
  * [comfy-table](https://crates.io/crates/comfy-table)
* Line endings:
  * [newline-converter](https://crates.io/crates/newline-converter)
  * [newline_normalizer](https://crates.io/crates/newline_normalizer)
  * [line-ending](https://crates.io/crates/line-ending)
  * [eolify](https://crates.io/crates/eolify)
  * [normalized-line-endings](https://crates.io/crates/normalized-line-endings)
* [textwrap](https://crates.io/crates/textwrap)
* [heck](https://crates.io/crates/heck) (case conversion)

## Time
* [time](https://crates.io/crates/time)
* [chrono](https://crates.io/crates/chrono)
* [humantime](https://crates.io/crates/humantime)

## Types
* Newtype:
  * [derive_more](https://crates.io/crates/derive_more)
  * [strong-type](https://crates.io/crates/strong-type)
  * [shrinkwraprs](https://crates.io/crates/shrinkwraprs)
  * [nutype](https://crates.io/crates/nutype)
* Enum:
  * ☀️ [derive_more](https://crates.io/crates/derive_more) 
  * ☀️ [strum](https://crates.io/crates/strum)
  * [num_enum](https://crates.io/crates/num_enum)
* Numeric:
  * [num](https://crates.io/crates/num)
  * [az](https://crates.io/crates/az)
  * [byteorder](https://crates.io/crates/byteorder)
  * [ord_subset](https://crates.io/crates/ord_subset)
* Casting:
  * [zerocopy](https://crates.io/crates/zerocopy)
  * [bytemuck](https://crates.io/crates/bytemuck)
* Units:
  * [uom](https://crates.io/crates/uom)
* ☀️ [derive_more](https://crates.io/crates/derive_more)
* ☀️ [ambassador](https://crates.io/crates/ambassador)
* ☀️ [bon](https://crates.io/crates/bon) (generating builders, optional and named parameters) ([site](https://bon-rs.com/))
* [derive-new](https://crates.io/crates/derive-new)
* [getset](https://crates.io/crates/getset)
* [bitflags](https://crates.io/crates/bitflags)
* [smart-default](https://crates.io/crates/smart-default)

## Web frameworks
* [actix-web](https://crates.io/crates/actix-web)
* [axum](https://crates.io/crates/axum)
* [rocket](https://crates.io/crates/rocket)
* [loco-rs](https://crates.io/crates/loco-rs)
* [warp](https://crates.io/crates/warp)
* [poem](https://crates.io/crates/poem)

## Var 📌
* ☀️ [itertools](https://crates.io/crates/itertools)
* ☀️ [rand](https://crates.io/crates/rand)
* ☀️ [scopeguard](https://crates.io/crates/scopeguard)
* [uuid](https://crates.io/crates/uuid)
* [semver](https://crates.io/crates/semver)
* [contracts](https://crates.io/crates/contracts)
* [lru](https://crates.io/crates/lru) (LRU cache)
