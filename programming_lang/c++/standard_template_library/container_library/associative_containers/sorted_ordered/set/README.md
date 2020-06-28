## SET
- **What** Ordered container always stores unique values in sorted order.
- Sorting is done using Compare() function.
- **COMPLEXITY** insert, remove, search: O(logn)
- **Implemented** internally as RB Trees.
  - Every container is defined as template class. class provides templated contructors/functions. 
```
/usr/include/c++/8/profile/set.h
namespace std _GLIBCXX_VISIBILITY(default){
    namespace __profile{

        template<typename _Key, typename _Compare = std::less<_Key>,
           typename _Allocator = std::allocator<_Key> >

        class set                                                       <<<<<SET CLASS
        : public _GLIBCXX_STD_C::set<_Key,_Compare,_Allocator>,
        public _Ordered_profile<set<_Key, _Compare, _Allocator> >{
            set() = default;
            set(const set&) = default;
            set(set&&) = default;
            ~set() = default;
```

### SORTED MEANING
  - All elements are always sorted means All elements are in order(ascending/descending).
  - Some operations does not make sense Eg: push_back(), push_front()
