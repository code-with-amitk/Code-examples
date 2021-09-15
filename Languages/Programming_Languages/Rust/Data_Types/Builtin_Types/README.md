- [Result`<T, E>`](#res)

<a name=res></a>
### [`Result<T, E>`](https://doc.rust-lang.org/std/result/enum.Result.html#variant.Ok)
Result is a type that represents either success (Ok) or failure (Err).
```c
pub enum Result<T, E> {
    Ok(T),                  //Contains the success value
    Err(E),                 //Contains the error value
}
```

