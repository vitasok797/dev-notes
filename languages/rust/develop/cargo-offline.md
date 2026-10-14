# Cargo offline usage

## On the online machine (gathering the cache)

1. Create a script in the directory where your Rust projects are located.
2. Paste and run the following script to download all dependencies into a clean, isolated directory:

```batch
@echo off
setlocal
set CARGO_HOME=%CD%\temp_cargo_home

:: Run 'cargo fetch' for each of your projects
cd "project1" && cargo fetch && cd ..
cd "project2" && cargo fetch && cd ..
cd "project3" && cargo fetch && cd ..

echo Cache collection complete
pause
```

3. Open the newly created `temp_cargo_home\registry\` folder and copy two specific directories to your USB drive:
	• 📁 cache (contains the actual .crate archives)
	• 📁 index (contains critical dependency metadata)

## On the offline machine (deployment)

1. Navigate to your global Cargo home directory: `%USERPROFILE%\.cargo\`
2. Create a folder named registry inside it if it doesn't exist.
3. Paste the cache and index folders from your USB drive directly into: `%USERPROFILE%\.cargo\registry\`
4. Create or edit the global configuration file at `%USERPROFILE%\.cargo\config.toml` and add only these lines:
```toml
[net]
offline = true
```
