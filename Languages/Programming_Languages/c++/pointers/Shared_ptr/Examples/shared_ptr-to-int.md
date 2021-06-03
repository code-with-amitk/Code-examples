### Pointing shared_ptr to int
- _1._ ptr is pointer to integer having value=5
- _2._ ptr,ptr1 now points to same memory.
```c++
int main(){
  shared_ptr <int> ptr (new int(5));         //1
  shared_ptr <int> ptr1 = ptr;               //2

  cout << *ptr;                             //Ouput:5
  cout<<*ptr1;                              //Output:5

  ptr.reset();                               //Deleting ptr
  cout << *ptr1;                             //5   But ptr1 still points to memory

  ptr1.reset();                               //Deleting ptr1
  //cout<<*ptr;                              //Segmentation Fault
}
```
