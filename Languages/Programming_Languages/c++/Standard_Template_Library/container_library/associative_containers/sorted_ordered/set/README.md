## SET <KEY>

```

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

## Pages
- **create_insert.md**  constructors, insert(), s.make_pair(x,y)
