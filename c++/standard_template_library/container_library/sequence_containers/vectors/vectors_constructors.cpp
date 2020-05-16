/* 	vector_constructors.cpp
WHAT? 
 - This is dynamic Allocated Array.
 - Elements are stored in contiguous location.
 - Vector keeps some space reserved in advance for storage of some variables.
 - Now when this space is exhausted. It again re-allocates bigger contiguous space, copies the elements to new space, deletes present memory.  

ARRAYLIST Vs VECTORS?
 - Vectors are synchronized by default but ArrayLists are not.
 - Means if multiple threads accesses vectors then no synchronization needed but required in AL.    
Question: Implement vector class. (github: implementing_vector.cpp)

**********A.CONSTRUCTORS************
A1. DEFAULT CTR: 

A2. FILL CTR: 

A3. RANGE CTR: 

A4. COPY CTR:

A5. FIXED SIZED CTR:
     Construct container contaning n element init to 0. No copies are made.
         Until C++14: explicit vector( size_type n );
         Since C++14: explicit vector( size_type n, const Allocator& alloc = Allocator() );

A6. MOVE CTR:
     Construct the vector from 'orig' using move semantics. After the move, other is guaranteed to be empty().
         Until C++17: vector( vector&& orig )
         Since C++17: vector( vector&& orig ) noexcept;

A7. ALLOCATOR EXTENDED MOVE CTR:
     Here, original vector is not guaranteed to be empty after the move.
         Since C++11: vector( vector&& other, const Allocator& alloc );

A8. INITIALIZER LIST CTR:
     Constructs the container with the contents of the initializer list l
         Since C++11: vector( initializer_list<T> l, const Allocator& alloc = Allocator() );    
*/

#include<iostream>
#include<vector>
#include <initializer_list>
using namespace std;

int main(){
        vector<int>::iterator it;

        /*A1.DEFAULT CTR
            Constructs an empty container with a default-constructed allocator.
            Until C++17: vector()
            After C++17: vector() noexcept(noexcept(Allocator()));  
        */
        vector<int> a;
        for (it = a.begin(); it != a.end(); it++)
                cout << "  " << *it;         //Nothing printed
        cout << "\n";

 
        /*A2. FILL CTR
            Constructs a container with n elements. Each element is a copy of 'a'(if provided)
            Until C++11 explicit vector(size_type n, const T& value = T(), const Allocator& alloc = Allocator());
            Since C++11          vector(size_type n, const T& a, const Allocator& alloc = Allocator());
            Arguments(latest):
                1. n = sizeof vector to be created
                2. a = Value to which each element is assigned
                3. alloc = Default valued, not to be passed when calling
        */
        vector<int> b (5 , 10);              //vector sized 5 init to 10.
        for (it = b.begin(); it != b.end(); it++)
                cout << "  " << *it;            //10 10 10 10 10
        cout << '\n';

 
        /*A3. RANGE CTR
            Constructs the container with the contents of the range [first, last)
             template< class T >
            vector( T first, T last, const Allocator& alloc = Allocator() );        
            Arguments:
                1. first: Input iterator to the initial position in a range.
                2. second: Input iterator to the final position in a range.
                3. alloc = Default valued, not to be passed when calling
        */
        vector<int> c(b.begin(), b.end());
        for (it = c.begin(); it != c.end(); it++)
                cout << "  " << *it;            //10 10 10 10 10
        cout << '\n';

 
        /*A4. COPY CTR
            Create a new vector that is a copy of the given vector.
            Until C++11: vector( const vector& other );
            Since C++11: vector( const vector& other, const Allocator& alloc );
        */
        vector<int> d (c);
        for (it = d.begin(); it != d.end(); it++)
                cout << "  " << *it;            //10 10 10 10 10
        cout << '\n';

        //A5. FIXED SIZED CTR
        vector<int> e(4);
        for (it = e.begin(); it != e.end(); it++)
                cout << "  " << *it;            //0 0 0 0 
        cout << '\n';

        //A6. MOVE CTR
        vector<int> f (5 , 10);
        vector<int> g(move(f));
        for (it = f.begin(); it != f.end(); it++)
                cout << "  " << *it;            //Nothing printed
        cout << '\n';
        for (it = g.begin(); it != g.end(); it++)
                cout << "  " << *it;            //10 10 10 10 10 
        cout << '\n';

        //A8. INITIALIZER LIST CTR:
        vector<int> h{1,2,3,4};
        vector<int> i(initializer_list<int>{8, 80, 800});
        for (it = h.begin(); it != h.end(); it++)
                cout << "  " << *it;            //1,2,3,4
        cout << '\n';
        for (it = i.begin(); it != i.end(); it++)
                cout << "  " << *it;            //8,80,800
        cout << '\n';
}
