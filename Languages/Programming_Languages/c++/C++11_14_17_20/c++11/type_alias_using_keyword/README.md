**Type Alias/using keyword**
- **typedef vs using**
  - [using is compatible with Templates, typedef not](#temp)
- **Where using can be used?**
  - [using in place of typedef](#case1)
  - [Bring member into scope](#case2)


## Type Alias / using keyword

### typedef vs using
<a name=temp></a>
#### 1. typedef are not compatible with templates, using are
```cpp
///////////////////////typedef//////////////////
template <typename T> 
struct A {};

template <typename T> 
struct B
{
  typedef whatever<T> type; // to make it possible to substitue the whatever in future.
};
rebind<int>::type variable;
template <typename U> struct bar { typename rebind<U>::type _var_member; }

/////////////using//////////////////
template <typename T> using my_type = A<T>;
my_type<int> variable;
template <typename U> struct baz { my_type<U> _var_member; }
```

### Where using can be used?
<a name=case1></a>
#### using in place of typedef
```cpp
  C++03: typedef long counter;           //Here syntax of typedefs gets ugly with complex typedefs
  C++11: using counter = long;           //type alias.
```    
<a name=case2></a>
#### Bring member from namespace into current scope
- or Bring all members from the namespace into the current scope. 
- or Bring a base class method or variable into the current class’s scope.
```cpp
  using boost::any;        //Bringing any from boost namespace to current scope.
  vector<any> a;            //Now we can use 'any', else we have to define as: vector<boost::any> a
```    
