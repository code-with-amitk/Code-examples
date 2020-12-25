## Constructors

### 1. DEFAULT
- Constructs an empty container with a default-constructed allocator.
 ```c++
vector<int> a;
```

### 2. FILL
- Constructs a container with n elements. Each element is a copy of 'a'(if provided)
 ```c++
 
vector<int> b (5 , 10);              //vector sized 5 init to 10.
for (it = b.begin(); it != b.end(); it++)
 cout << "  " << *it;            //10 10 10 10 10
cout << '\n';
```

### 3. RANGE 
- Constructs the container with the contents of the range `[first, last)`
```c++
vector<int> c(b.begin(), b.end());
for (it = c.begin(); it != c.end(); it++)
 cout << "  " << *it;            //10 10 10 10 10
cout << '\n';
```                                                           

### 4. COPY
- Create a new vector that is a copy of the given vector.
```c++                                         
Until C++11: vector( const vector& other );
Since C++11: vector( const vector& other, const Allocator& alloc );

vector<int> d (c);
for (it = d.begin(); it != d.end(); it++)
 cout << "  " << *it;            //10 10 10 10 10
cout << '\n';
```

### 5. FIXED SIZED
- Construct container contaning n element init to 0. No copies are made.
```c++                       
Until C++14: explicit vector( size_type n );
Since C++14: explicit vector( size_type n, const Allocator& alloc = Allocator() );

vector<int> e(4);
for (it = e.begin(); it != e.end(); it++)
 cout << "  " << *it;            //0 0 0 0 
cout << '\n';
```

### 6. MOVE
- Construct the vector from 'orig' using move semantics. After the move, other is guaranteed to be empty()
```
Until C++17: vector( vector&& orig )
Since C++17: vector( vector&& orig ) noexcept;

vector<int> f (5 , 10);
vector<int> g(move(f));
for (it = f.begin(); it != f.end(); it++)
 cout << "  " << *it;            //Nothing printed
cout << '\n';
for (it = g.begin(); it != g.end(); it++)
 cout << "  " << *it;            //10 10 10 10 10 
cout << '\n';
```

### 7. ALLOCATOR EXTENDED MOVE
- Here, original vector is not guaranteed to be empty after the move.
```c++
Since C++11: vector( vector&& other, const Allocator& alloc );
```

### 8. INITIALIZER LIST
- Constructs the container with the contents of the initializer list l
```c++
//Since C++11: vector( initializer_list<T> l, const Allocator& alloc = Allocator() );  

#include <initializer_list>
vector<int> h{1,2,3,4};
vector<int> i(initializer_list<int>{8, 80, 800});
for (it = h.begin(); it != h.end(); it++)
 cout << "  " << *it;            //1,2,3,4
cout << '\n';
for (it = i.begin(); it != i.end(); it++)
 cout << "  " << *it;            //8,80,800
cout << '\n';
```
