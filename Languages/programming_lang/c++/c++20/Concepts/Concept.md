## Concepts
### What
- If we have a template class defining templated or non templated functions. Based on template arguments, template class can select most appropriate
  - function from overloaded funtions or
  - template specialization from specializations. 
 - Concepts allow to provide constraints on templates and have the compiler enforce them.
- Named sets of such requirements are **called concepts**, Concepts is a predicate(evaluated at compile time).
  - **What is predicate?** Languages/programming_lang/c++/operator_overloading/Functor/Predicate/
  
### Example-1
1. Created a concept named 'TEST'. Any type of `<typename T>` should statify these conditions:
   - hash<T>{}(a) compiles and its result is convertible to std::size_t
2. Create a function whose arguments should adhere to `concept TEST`.
   - Hash of String "abc" can be calculated and be converted to size_t.
   - Hash of structure cannot be calculated.
```
template<typename T>
concept TEST = requires(T a) {                  //1
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;    //1
};
 
template<TEST K>                    //2
void f(K){ std::cout<<"fun"; }
 
int main() {
  f("abc"s);                        //2a
  struct st{};
  f(st);                            //2b  Error: st does not satisfy TEST
}
```

