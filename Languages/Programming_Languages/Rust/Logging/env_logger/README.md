**env_logger library**
- [How it works](#hw1)
- [Code](#co1)


## env_logger library
<a name=hw1></a>
### How it works
- Provide log level in enviornment variable(RUST_LOG)
- Call env_logger::init() in code, everything is written on stderr=stdout
- API will log all log levels above it.

<a name=co1></a>
### Code
5 log levels: error (highest priority), warn, info, debug, and trace (lowest priority)
```rs
# Cargo.toml
[package]
name = "Logging"
version = "0.1.0"
edition = "2021"

[dependencies]
log = {version="0.4"}
env_logger = "0.9.0"

# main.rs
fn main() {
    env_logger::init();
    log::error!("error log");
    log::warn!("warn log");
    log::info!("info log");
    log::debug!("debug log");
    log::trace!("trace log");
}

$ RUST_LOG=trace cargo run                        //Prints self+above all
[2022-05-30T12:12:37Z ERROR Logging] error log
[2022-05-30T12:12:37Z WARN  Logging] warn log
[2022-05-30T12:12:37Z INFO  Logging] info log
[2022-05-30T12:12:37Z DEBUG Logging] debug log
[2022-05-30T12:12:37Z TRACE Logging] trace log

$ RUST_LOG=debug cargo run                        
[2022-05-30T12:10:24Z ERROR Logging] error log
[2022-05-30T12:10:24Z WARN  Logging] warn log
[2022-05-30T12:10:24Z INFO  Logging] info log
[2022-05-30T12:10:24Z DEBUG Logging] debug log

$ RUST_LOG=info cargo run                        
[2022-05-30T12:11:25Z ERROR Logging] error log
[2022-05-30T12:11:25Z WARN  Logging] warn log
[2022-05-30T12:11:25Z INFO  Logging] info log

$ RUST_LOG=warn cargo run                        //Prints above all
[2022-05-30T12:12:04Z ERROR Logging] error log
[2022-05-30T12:12:04Z WARN  Logging] warn log

```
