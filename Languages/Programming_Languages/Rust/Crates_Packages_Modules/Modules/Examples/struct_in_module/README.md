## struct inside module
- _1._ To access structure has to declared public, but still all feilds of struct remains private.
- _2._ To access any field, that feild has to be made public.
- _3._ We need to define a implementation fo access fields in `module_a::st` since there is a private member.
- _4._ Then we can access members using dotted notation.
```rust
mod module_a {
    pub struct st{           //1
        pub a:u32,          //2
        b:u16,              //This remains pvt
    }

    impl test {                         //3
        pub fn fun(x: u32) -> st {
            st {
                a: x,
                b: 10,
            }
        }//fun
    }//test
}//module_a

pub fn fun1 {
  let mut var = crate::test::fun(30);         //4
  println!("{}", var.st.a);               //30
  println!("{}", var.st.b);               //10
}
```
