# Cargo offline

## Step 1: On the online machine (fathering the cache)
When you build Rust projects online, Cargo automatically caches all downloaded packages as .crate files (which are just compressed source archives) in a central system directory.
To harvest your offline asset cache:

   1. Navigate to: `C:\Users\Your_Name\.cargo\registry\cache\`
   2. Inside, you will see a folder named something like github.com-XXXXXX or index.crates.io-XXXXXX.
   3. Copy everything inside that directory to your USB drive or external storage. This is your definitive asset_cache.

## Step 2: On the offline machine (one-time setup)
We will configure the offline environment globally so that individual projects are completely unaware they are running in an isolated environment.

   1. Move the files from your USB drive to a permanent local directory, for example: C:\rust_asset_cache\
   2. Create one single global configuration file for your Windows user profile at:
   C:\Users\Your_Name\.cargo\config.toml
   3. Paste the following configuration into it:

### 1. Permanently block Cargo from attempting network access

```toml
[net]
offline = true
```

### 2. Redirect all standard crates.io requests to our local mirror

```toml
[source.crates-io]
replace-with = "my-shared-asset-cache"
```

### 3. Specify the path to your centralized archive directory

```toml
[source.my-shared-asset-cache]
local-registry = "C:/rust_asset_cache"
```

## The final result

* Inside Your Projects: Complete cleanliness. No vendor clutter, no tracked local .cargo configurations. Git histories stay pure.
* Developer Experience: You simply open a project repo and run standard commands like cargo build --release.
* Under the Hood: Cargo intercepts the build request, reads the global configuration, pulls the required .crate archive from C:\rust_asset_cache\, extracts it into the target build directory, and compiles without a single network packet.
