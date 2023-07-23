**slog**
- [Advantages](#adv)
- [Elements: Drain, Logger, Log Levels](#e)
- Code
  - [1. Configure log level at compile time](#c1)
  - [2. Configure log level from function](#c2)
  - [3. Dynamic log level from console](#c3)

## [slog /Structured logging for Rust](https://docs.rs/slog/latest/slog/enum.Level.html)
<a name=adv></a>
#### Advantages
- **Structured Logging:** Slog allows developers to log data in a structured format, such as JSON or key-value pairs, which makes it easier to parse and analyze logs using external tools.
- **Thread safety:** It can be used in multi-threaded environments without worrying about data races or concurrency issues.
- **Runtime Log Level Modification:** Log level can be changed dynamically at runtime
- **[Advantages over log crate](https://docs.rs/slog/latest/slog/#core-advantages-over-log-crate)**

<a name=e></a>
### Elements
#### 1. Drain(Backend) for logging
- Drain reads logging statements(modifies if needed) and sends to destination.
- Backends(called drains) can be combined and extended easily to create complex logging pipelines

#### 2. Logger (type = Logger)
- This is logging handle used to execute logging statements
- logging interface, allowing applications to write log messages to various destinations(eg: console, file, remote)

#### 3. log levels 
When setting the log level, messages of the specified level and all higher levels in the hierarchy will be displayed.
```c
Error (highest severity) //includes critical errors
Warning
Info
Debug
Trace (lowest severity)
```
#### 4. Notable Features
  - _1._ When release build is prepared: slog by default removes trace and debug level statements. warn,info,error are kept.
  - _2._ When debug build is prepared: trace level records are removed. While debug and higher are kept.

### Code
<a name=c1></a>
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

<a name=c2></a>
#### 2. Configure log level from function
```rs
$ Cargo.toml
[package]
name = "slog"
version = "0.1.0"
edition = "2021"

[dependencies]
slog = {version="2.7.0"}
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

fn main() {
  let log_path = "/home/amit/file.log".to_string();                //Log file path
  
  let k = FileLoggerBuilder::new(log_path)
    .timezone(TimeZone::Local)
    .format(Format::Full)
    .source_location(SourceLocation::LocalFileAndLine)
    .rotate_size(1024*1024 as u64)                                //Rotate when size > 1MB
    .level(Severity::Warning)
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

<a name=c3></a>
#### 3. Dynamic log level from console
```rs
/// A. Set logger for console

let json = slog_json::Json::new(std:io::stdout())      //1. Creates json output drain using key-value pair
.set_newlines(true)
.set_pretty(false)
.add_key_value(slog::o!(
  "tid" => FnValue(|_: &Record| rinfo.level().as_str()),
  "msg" => FnValue(|_: &Record| rinfo.level().to_string()), 
   "level" => FnValue (|rinfo: &Record|rinfo.level().as_str()),
   "time" => FnValue(|_:&Record|get_log_time()),
)).build();

slog::Logger::root(Mutex::new(json.filter_level(severity)).fuse(),    //2. Creates a logger with the JSON output drain 
            slog::o!("type" => env!("CARGO_PKG_NAME")),
);

let logger_guard = slog_scope::set_global_logger(logger.clone());    //3. Sets the created logger as the global logger

logger_guard.cancel_reset();      //4. Prevents global logger from being reset if another part of the application tries to set a different logger as the global logger
```
