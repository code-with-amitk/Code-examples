### Problem-1
- Given a `unsigned long (size=8 bytes)` array of 5 elements. (size=5x8=40 bytes)
- Copy to complete array to other memory location.
#### Code
```c
int main(){
  uint64_t u64Array[] = {10,20,30,40,50};                     //size=40 bytes
  
  //new Syntax:  *ptr = new type[size]
  uint64_t *pcDest = new uint64_t[new sizeof(uint64_t)*5];    //Take memory of 40 bytes
  
  //Typecast destination pointer to void before copy
  memcpy((void*)pcDest, (void*)u64Array, 40);
  OR
  memcpy(reinterpret_cast<void*>(pcDest), reinterpret_cast<const void*>(u64Array), 40);
  
  for(int i=0; i<5; i++)
    cout<<pcDest[i];              //10 20 30 40 50
}
```

### Problem-2
- Given a `unsigned long (size=8 bytes)` array of 5 elements. (size=5x8=40 bytes)
- Copy 24 bytes from offset=16 (ie 2nd,3rd,4th elements)
#### Code
```c
int main(){
  uint64_t u64Array[] = {10,20,30,40,50};                     //size=40 bytes
  
  //new Syntax:  *ptr = new type[size]
  uint64_t *pcDest = new uint64_t[new sizeof(uint64_t)*3];    //Take memory of 24 bytes
  
  //Typecast destination pointer to void before copy
  //Typecast src pointer to char. This way we can advance 16 steps from start.
  //NOTE: addition,substraction operations are not allowed on void*
  memcpy((void*)pcDest, ((char*)u64Array)+16, 24);
  OR
  memcpy(reinterpret_cast<void*>(pcDest), reinterpret_cast<const char*>(u64Array)+16, 24);
  
  for(int i=0; i<3; i++)
    cout<<pcDest[i];              //20 30 40
}
```
