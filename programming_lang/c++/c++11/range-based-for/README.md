## RANGE BASED FOR LOOP
  - **What** For loop executing over a range.
  - **Why RBL** 
    a. Less suceptible to segmentation fault. i++ can cause writing over the range.
    b. RBL are faster wrt traditional loops in nanoseconds precision.
```    
      for (auto i : v)                          //10575 nanosec. Calculated using chrono
            cout << i << ' ';
      for(auto i=v.begin();i!=v.end();i++)     //11317 nanosec.
            cout<<*i<<' ';
```


### SYNTAX
```
(until C++20)
  attr(optional) for ( range_declaration : range_expression ) loop_statement                //1
  
(since C++20)  
  attr(optional) for ( init-statement(optional)range_declaration : range_expression ) loop_statement  //2
  
range_declaration: is a named variable whose type is same as range_expression OR is refrence to range_expression
range_expression: any suitable sequence Either array or object which has begin(), end() functions defined or a braced-init-list.
loop_statement: any compound statement, which is the body of the loop

1 is same as:
{
  auto && __range = range_expression ;
  auto __begin = begin_expr ;
  auto __end = end_expr ;
  for ( ; __begin != __end; ++__begin) {
    range_declaration = *__begin;
    loop_statement
  }
}  
```

### Example-1  (vector)
```
  vector<int> v{1,2,5,3,4};
  for (auto i : v) {                    //i variable takes value of vector variables for each iteration. No need to do ++
    cout <<i<<' ';        //1 2 3 4 5
  }
```

### Example-2 (map)
```
  for (auto&& [first,second] : mymap) {
    // use first and second
  }
```
