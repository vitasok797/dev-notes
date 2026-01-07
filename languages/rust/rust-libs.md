# Rust / Libs

⚠️ [crates.io list](https://crates.io/crates?sort=downloads) \
⚠️ [Awesome Rust](https://github.com/rust-unofficial/awesome-rust) \
⚠️ [lib.rs](https://lib.rs/)

## Communication
* [tokio](https://crates.io/crates/tokio)
* [tower](https://crates.io/crates/tower)

### DDS
* [rustdds](https://crates.io/crates/rustdds)
* [dust_dds](https://crates.io/crates/dust_dds)
* [cyclors](https://crates.io/crates/cyclors) (CycloneDDS bindings)

### gRPC
* [tonic](https://crates.io/crates/tonic)
* [grpc](https://crates.io/crates/grpc)

### ZeroMQ
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
* [itertools](https://crates.io/crates/itertools)
* [smallvec](https://crates.io/crates/smallvec)
* [hashbrown](https://crates.io/crates/hashbrown) (port of Google's high-performance SwissTable hash map)

## Data processing
* [polars](https://crates.io/crates/polars)

## DB
* [diesel](https://crates.io/crates/diesel) (ORM and query builder for PostgreSQL, SQLite, and MySQL)
* [sea-orm](https://crates.io/crates/sea-orm)
* [sqlx](https://crates.io/crates/sqlx)
* [rusqlite](https://crates.io/crates/rusqlite)

## Error handling
* [thiserror](https://crates.io/crates/thiserror)
* [anyhow](https://crates.io/crates/anyhow)

## File system
* Walk:
  * [glob](https://crates.io/crates/glob)
  * [walkdir](https://crates.io/crates/walkdir)
  * [ignore](https://crates.io/crates/ignore)
* [tempfile](https://crates.io/crates/tempfile)
* [dirs](https://crates.io/crates/dirs) (platform-specific standard locations)
* [which](https://crates.io/crates/which)

## Formats
* [serde](https://crates.io/crates/serde) (JSON, YAML, TOML, CSV, MessagePack, FlexBuffers)
* XML ([search](https://crates.io/search?q=XML))
* [base64](https://crates.io/crates/base64)
* [flatbuffers](https://crates.io/crates/flatbuffers) ([search](https://crates.io/search?q=FlatBuffers))
* Protobuf:
  * [prost](https://crates.io/crates/prost)
  * [protobuf](https://crates.io/crates/protobuf) (v.4+) ([protobuf-team crates](https://crates.io/teams/github:protocolbuffers:protobuf-team))

## GUI
* [iced](https://crates.io/crates/iced)
* [egui](https://crates.io/crates/egui)
* [gpui](https://crates.io/crates/gpui), [gpui-component](https://crates.io/crates/gpui-component)

### Plot
* [plotly](https://crates.io/crates/plotly)
* [plotters](https://crates.io/crates/plotters)
* [egui_plot](https://crates.io/crates/egui_plot)

## Hashing
* [digest](https://crates.io/crates/digest) ([supported-algorithms](https://github.com/RustCrypto/hashes?tab=readme-ov-file#supported-algorithms))
* xxhash ([article](https://jolynch.github.io/posts/use_fast_data_algorithms/)):
  * [xxhash-rust](https://crates.io/crates/xxhash-rust)
  * [twox-hash](https://crates.io/crates/twox-hash)

## Log
* [log](https://crates.io/crates/log)
* [slog](https://crates.io/crates/slog)
* [env_logger](https://crates.io/crates/env_logger)
* [loggerv](https://crates.io/crates/loggerv)

## Multithreading
* Channels:
  * [std::sync::mpsc](https://doc.rust-lang.org/std/sync/mpsc/)
  * [crossbeam-channel](https://crates.io/crates/crossbeam-channel)
* [crossbeam](https://crates.io/crates/crossbeam)
* [rsevents](https://crates.io/crates/rsevents)

## Process
* Subprocess:
  * [std::process](https://doc.rust-lang.org/std/process/)
  * [subprocess](https://crates.io/crates/subprocess)
  * [duct](https://crates.io/crates/duct)
* Signal handling:
  * [ctrlc](https://crates.io/crates/ctrlc) ([issue](https://github.com/Detegr/rust-ctrlc/issues/122))
  * [ctrlc2](https://crates.io/crates/ctrlc2)
  * [signal-hook](https://crates.io/crates/signal-hook)
  * [tokio::signal](https://docs.rs/tokio/latest/tokio/signal/index.html) ([issue](https://github.com/tokio-rs/tokio/issues/7039))

## Shared libs
* [libloading](https://crates.io/crates/libloading)

## Scripting
* ❓

## System
* [sysinfo](https://crates.io/crates/sysinfo)
* [whoami](https://crates.io/crates/whoami)

### Windows
* Registry:
  * [winreg](https://crates.io/crates/winreg)
* WinAPI:
  * [winapi](https://crates.io/crates/winapi)
  * [windows-sys](https://crates.io/crates/windows-sys)
  * [windows](https://crates.io/crates/windows)

## Terminal
* [crossterm](https://crates.io/crates/crossterm)
* [console](https://crates.io/crates/console)
* [dialoguer](https://crates.io/crates/dialoguer)
* Progress:
  * [indicatif](https://crates.io/crates/indicatif)
* TUI:
  * [ratatui](https://crates.io/crates/ratatui)
  * [cursive](https://crates.io/crates/cursive)

## Text
* [regex](https://crates.io/crates/regex)
* [textwrap](https://crates.io/crates/textwrap)
* Tabulate:
  * [tabled](https://crates.io/crates/tabled)
  * [comfy-table](https://crates.io/crates/comfy-table)
* Line endings:
  * [newline-converter](https://crates.io/crates/newline-converter)
  * [newline_normalizer](https://crates.io/crates/newline_normalizer)
  * [line-ending](https://crates.io/crates/line-ending)
  * [eolify](https://crates.io/crates/eolify)
  * [normalized-line-endings](https://crates.io/crates/normalized-line-endings)

## Time
* [time](https://crates.io/crates/time)
* [chrono](https://crates.io/crates/chrono)
* [humantime](https://crates.io/crates/humantime)

## Types
* Newtype:
  * [derive_more](https://crates.io/crates/derive_more)
  * [strong-type](https://crates.io/crates/strong-type)
  * [shrinkwraprs](https://crates.io/crates/shrinkwraprs)
* Enum:
  * [derive_more](https://crates.io/crates/derive_more) 
  * [strum](https://crates.io/crates/strum)
* ⭐ [derive_more](https://crates.io/crates/derive_more)
* [derive-new](https://crates.io/crates/derive-new)
* [scopeguard](https://crates.io/crates/scopeguard)
* [bitflags](https://crates.io/crates/bitflags)
* units ❓

## UUID
* [uuid](https://crates.io/crates/uuid)

## Web frameworks
* [actix-web](https://crates.io/crates/actix-web)
* [axum](https://crates.io/crates/axum)
* [rocket](https://crates.io/crates/rocket)
* [warp](https://crates.io/crates/warp)
* [tide](https://crates.io/crates/tide)
* [poem](https://crates.io/crates/poem)

## Var 📌
* [lru](https://crates.io/crates/lru) (LRU cache)
