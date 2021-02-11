## Print Binary
```c
void PrintBinary(int& a){
  int b = 1, i=1;
  while(i++<=sizeof(a)*8){
    if (b&a)
      std::cout << 1;
    else
      std::cout << 0;
    b <<= 1;
  }
  std::cout<<"\n";
}

int main(){
  int a = 0x8;
  std::cout<<a<<"\n";
  PrintBinary(a);
}

# ./a.out
8
00010000000000000000000000000000
```
