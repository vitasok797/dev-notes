# Cargo offline usage

## On the online machine (gathering the cache)

1. Download all dependencies into a clean, isolated directory:
```batch
set CARGO_HOME=%CD%\temp_cargo_home
cargo fetch
```

2. Open the newly created `temp_cargo_home\registry\` folder and copy two specific directories to your USB drive:
* 📁 `cache` (contains the actual .crate archives)
* 📁 `index` (contains critical dependency metadata)

## On the offline machine (deployment)

1. Navigate to your global Cargo home directory: `%USERPROFILE%\.cargo\`
2. Create a folder named `registry` inside it if it doesn't exist.
3. Paste the `cache` and `index` folders from your USB drive directly into `%USERPROFILE%\.cargo\registry\`
4. Create or edit the global configuration file at `%USERPROFILE%\.cargo\config.toml` and add only these lines:
```toml
[net]
offline = true
```
