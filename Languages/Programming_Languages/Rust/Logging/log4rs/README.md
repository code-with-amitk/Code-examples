**log4rs**

## [log4rs](https://docs.rs/log4rs/latest/log4rs/)
This is highly configurable logging framework modeled after Java’s Logback and log4j libraries.

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
```rs
use log::error;
use log::info;
use log::warn;
use log::{debug, LevelFilter};
use log4rs::append::console::ConsoleAppender;
use log4rs::config::{Appender, Root};
use log4rs::Config;

fn main() {
    let stdout = ConsoleAppender::builder().build();    
    let config = Config::builder()
        .appender(Appender::builder().build("stdout", Box::new(stdout)))
        .build(Root::builder().appender("stdout").build(LevelFilter::Trace))
        .unwrap();    
    let _handle = log4rs::init_config(config).unwrap();    
    debug!("Mary has a little lamb");
    error!("{}", "Its fleece was white as snow");
    info!("{:?}", "And every where that Mary went");
    warn!("{:#?}", "The lamb was sure to go");
}
```
