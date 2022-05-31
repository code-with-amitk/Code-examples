**log4rs**
- [Architecture](#ar)
- [Code](#co)

## [log4rs](https://docs.rs/log4rs/latest/log4rs/)
This is highly configurable logging framework modeled after Java’s Logback and log4j libraries.

<a name=ar></a>
### Architecture
#### 1. Appender
Takes log record and logs it somewhere(a file, console, or syslog)
```c
  Log to     | Feature needed
-------------|-------------------  
 console     | console_appender
  file       | file_appender
rolling_file | rolling_file_appender, configured with the compound_policy.
compound     | compound_policy
```

#### 2. Encoders
An encoder takes log record, transforms it into the appropriate output format, and writes to output.

#### 3. Filters
This filters the log events coming into that appender.

#### 4. Loggers
A log event is targeted at a specific logger, which are identified by string names. 

<a name=co></a>
### Code
- 5 log levels: error (highest priority), warn, info, debug, and trace (lowest priority)
```rs
$ Cargo.toml
[package]
name = "log4rs"
version = "0.1.0"
edition = "2021"
[dependencies]
log = {version="0.4"}
log4rs = "1.1.1"

$ main.rs
use log::{error, info, warn, trace};
use log::{debug, LevelFilter};
use log4rs::append::console::ConsoleAppender;
use log4rs::config::{Appender, Root};
use log4rs::Config;

fn main() {
    //error!(), warn!(), info!(), debug!(), and trace!()
    let stdout = ConsoleAppender::builder().build();
    let config = Config::builder()
        .appender(Appender::builder().build("stdout", Box::new(stdout)))
        .build(Root::builder().appender("stdout").build(LevelFilter::Info))      //LevelFilter::Info will show above it
        .unwrap();    
    let _handle = log4rs::init_config(config).unwrap();
    error!("{}", "error log");
    warn!("{:#?}", "warn log");
    info!("{:?}", "info log");
    debug!("debug log");
    trace!("trace log");
}
$ cargo run
2022-05-31T05:32:53.967147473+00:00 ERROR log4rs - error log
2022-05-31T05:32:53.967308293+00:00 WARN log4rs - "warn log"
2022-05-31T05:32:53.967370417+00:00 INFO log4rs - "info log"
```
