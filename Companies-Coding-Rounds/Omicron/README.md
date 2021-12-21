Forget the mistake remember the lesson. **Lesson:**
- _1. Understand Question Completely._ 
  - Read. Repeat(and ask questions). Doctest(small, medium, big inputs). Visualize

## Round-1 (Video call)
- MTU vs MSS, spinlock vs other synchronization mechanisms, project related

## Round-2 (Tasterday / Onsite Interview)
### 1. Logical Question
- **Q1a. 3 Bulbs & 3 switches?** There are 3 bulbs and room-1 and 3 switches on other room-2. From 1 room you cannot see anything in other room. Identify which switch is for which bulb?
- _Ans:_ 
  - Turn on switch1 for 1 hour, then switch it off. Turn on switch2 and run immediately to room-2. Most hot bulb=switch1, Turned on bulb=switch2, off cold bulb=switch3.
### 2. C/C++ Output related question
- static, global variable questions.
- **Q2b. Will it compile,run in C/C++? Point 3 mistakes**
```c
$ cat test.c
int main() {
  int a = 42;
  printf("%d\n",a);
}

//C complied with warning. Because libc(C Standard library) has defined it already.
$ gcc test.c
test.c:3:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n",a);
     ^~~~~~
test.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’
test.c:3:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’

//C++ did not compile. C++ always need header include
$ g++ test.c
test.c: In function ‘int main()’:
test.c:3:5: error: ‘printf’ was not declared in this scope
     printf("%d\n",a);
```
- **3 Mistakes**
  - _1._ return statement missing from main. Return value is stored in rax which presently stores 3 (return value from printf) which is wrong.
  - _2._ Header file include is missing
  - _3._ main() should be main(int argc, char** argv) 
