## use as
- Defining shorter name for path.
```rust
use std::fmt::Result as FmtResult;
use std::io::Result as IoResult;

fn function1() -> FmtResult {
    // --snip--
}

fn function2() -> IoResult<()> {
    // --snip--
}
```
