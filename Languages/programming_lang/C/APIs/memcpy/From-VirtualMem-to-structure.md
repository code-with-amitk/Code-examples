## Copy from Virtual Memory to Structure

### Code
```c++
struct test{
  char a[4];
  uint32_t b;
  char c[6];
}__attribute((packed));

int main() {
  test var1;
  strcpy(var1.a, "hello");
  var1.b = 10;
  strcpy(var1.c, "abcdef");
  
  cout << &var1;             //0x7fff126cb320   Pointer to Struct is Virtual Address
  
  test var2;
  
  /*memcpy(void* dst, void* src, size)
  dst = &var2,  src = &var1
  */
  memcpy (&var2, &var1, sizeof(test));
  
  cout<<var2.b;             //10
}
```
