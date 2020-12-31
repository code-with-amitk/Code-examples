## Creating exe from object file
```c
int fun(){      //test.c
  int a=4,b=5;
  return a+b;
}

int main(){   //main.c
  fun();
}

# gcc -c test.c main.c      //Generates test.o main.o
# gcc -o TEST test.o main.o //Generates TEST as executable
# ./TEST
```
