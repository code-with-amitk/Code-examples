Registeries

## Registeries
- Cargo installs crates and fetches dependencies from a "registry". The default registry is crates.io

### Using Alternate Registry
- To use a registry other than crates.io, the name and index URL of the registry must be added to a .cargo/config.toml file
```c
$ ls -ltra
src
Cargo.toml
.cargo

$ .cargo/config
[registry]
default = "amit-registry"
[registries]
amit-registry = { index = "https://artifactory.janiper.net/crates-io.git" }

$ Cargo.toml
[package]
name = "my-project"
version = "0.1.0"

[dependencies]
tokio = { version = "1.0", registry = "amit-registry" }   //tokio fetched from custom registry
```
