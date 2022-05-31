**slog**
- [Elements](#e)

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
