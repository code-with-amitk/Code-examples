## Concepts
### What
- If we have a template class defining templated or non templated functions. Based on template arguments, template class can select most appropriate
  - function from overloaded funtions or
  - template specialization from specializations. 
 - Concepts allow to provide constraints on templates and have the compiler enforce them.
- Named sets of such requirements are **called concepts**, Concepts is a predicate(evaluated at compile time).
  - **What is predicate?** Languages/programming_lang/c++/operator_overloading/Functor/Predicate/
  
### Example
- `requires` is clause
- This tells that paramter `T` should support concept `Sortable`.
  - Sortable means requirements of algorithms that permute sequences into ordered sequences (for example, ranges::sort).
```
template <typename T> require Sortable<T>
void test(T &Sortable);
```

