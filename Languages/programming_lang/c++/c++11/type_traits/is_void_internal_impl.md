## is_void
- checks if a type is void
- Defined inside
```	
/usr/include/boost/type_traits/is_void.hpp
/usr/include/c++/8/type_traits.cpp
```
- Syntax
```
	template< class T >
	struct is_void;

::value returns the bool showing result meets desired specification or not?
```
- INTERNAL IMPLEMENTATION?
```	
  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
      static constexpr _Tp                  value = __v;
      typedef _Tp                           value_type;
      typedef integral_constant<_Tp, __v>   type;
      constexpr operator value_type() const noexcept { return value; }
    };

  typedef integral_constant<bool, true>     true_type;		//3

  template<>
    struct __is_void_helper<void> : public true_type { };	//2

  template<typename _Tp>
    struct is_void : public __is_void_helper<typename remove_cv<_Tp>::type>::type	//1
    { };

1. Publicly inherits __is_void_helper
2. Publicly inherits true_type
3. typedef of integral_constant
4. Implemented as integral_constant internally
```
