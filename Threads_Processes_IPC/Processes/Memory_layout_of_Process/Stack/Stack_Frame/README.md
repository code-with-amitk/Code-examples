## Stack Frame
- {Input_parameters} {Return_address} {Local_variables}
```c
  add(int a, int b){
    int c;               //Local
  }
  main(argv[0],argv[1]){            
    int a ,b;
    add(a,b);
  }   

--------stack allocated in this direction---->
[ argv[1] argv[0] | 0x45 | b a ]  [ | b a | 0x68 | c | ]     //Input parameters are pushed in reverse order
<---    sf of main()  --------->  <--sf of add()---->
```
