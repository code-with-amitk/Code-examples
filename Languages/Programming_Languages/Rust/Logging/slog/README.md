**slog**
- [Elements](#e)
- Code
  - [1. Configure log level at compile time](#c1)
  - [2. Configure log level from function](#c2)

## slog /Structured logging for Rust
- [Advantages over log crate](https://docs.rs/slog/latest/slog/#core-advantages-over-log-crate)
- **log levels:** error (highest priority), warn, info, debug, and trace (lowest priority)
- **Notable Features**
  - _1._ When release build is prepared: slog by default removes trace and debug level statements. warn,info,error are kept.
  - _2._ When debug build is prepared: trace level records are removed. While debug and higher are kept.

<a name=e></a>
### Elements
#### 1. Drain = Destination for logs
Drains are responsible for handling logging statements (Records) from Loggers associated with them: filtering, modifying, formatting and writing the log records into given destination(s).

#### 2. Logger
This is logging handle used to execute logging statements

#### [3. Log macro](https://docs.rs/slog/latest/slog/macro.log.html)

### Code
- **Log levels:** error (highest priority), warn, info, debug, and trace (lowest priority)

<a name=ct></a>
#### 1. Configure log level at compile time
```rs
$ Cargo.toml
[package]
name = "slog"
version = "0.1.0"
edition = "2021"

[dependencies]
slog = {version="2.7.0", features = ["max_level_warn"]}     //warn is Max Log level. It will log all above it
slog-term = "2.9.0"
slog-async = "2.7.0"

$ main.rs
#[macro_use]
extern crate slog;
extern crate slog_term;
extern crate slog_async;
use slog::Drain;

fn main() {
    let decorator = slog_term::TermDecorator::new().build();

    //Create drain which outputs messages to terminal(default)
    let drain = slog_term::FullFormat::new(decorator).build().fuse();
    let drain = slog_async::Async::new(drain).build().fuse();

    //Create Root Logger
    //Every application must have a root logger, to provide some initial logging such as app version.
    //Once we have logger ready, we can log the stuff
    let log = slog::Logger::root(drain, o!());

    error!(log, "log");
    warn!(log, "log");
    info!(log, "info");
    debug!(log, "log");
    trace!(log, "log");
}
$ cargo run
May 31 06:57:30.221 ERRO log
May 31 06:57:30.221 WARN log
```

#### 2. Configure log level from function
```rs
$ Cargo.toml
[package]
name = "slog"
version = "0.1.0"
edition = "2021"

[dependencies]
slog = {version="2.7.0", features = ["max_level_warn"]}
slog-term = "2.9.0"
slog-async = "2.7.0"
sloggers = {version="2.0"}
serde = { version = "1.0", features = ["derive"] }
serde_json = "1.0"

$ src/main.rs
#[macro_use]
extern crate slog;
extern crate slog_term;
extern crate slog_async;
use sloggers::file::FileLoggerBuilder;
use sloggers::types::{Format, OverflowStrategy, Severity, SourceLocation, TimeZone};
use sloggers::Build;
use slog::Drain;
use serde::{Deserialize, Serialize};

fn convert_to_severity(level: &str) -> Severity {
    match level {
        "trace" => Severity::Trace,
        "debug" => Severity::Debug,
        "info" => Severity::Info,
        "warning" => Severity::Warning,
        "error" => Severity::Error,
        "critical" => Severity::Critical,
        _ => Severity::Warning,
    }
}
fn main() {
  let log_path = "/home/amit/file.log".to_string();
  let severity = convert_to_severity("warn");                     //Log level = warn. Log all above warn
  
  let k = FileLoggerBuilder::new(log_path)                        //Log file path
    .timezone(TimeZone::Local)
    .format(Format::Full)
    .source_location(SourceLocation::LocalFileAndLine)
    .rotate_size(1024*1024 as u64)                                //Rotate when size > 1MB
    .level(severity)
    .channel_size(4096)
    .overflow_strategy(OverflowStrategy::DropAndReport)
    .build().unwrap();

    error!(k,"log");
    warn!(k,"log");
    info!(k,"info");
    debug!(k,"log");
    trace!(k,"log");
}
$ cargo run
$ cat file.log
May 31 07:42:09.794 ERRO log, module: src/main.rs:88
May 31 07:42:09.794 WARN log, module: src/main.rs:89
```
