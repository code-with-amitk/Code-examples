/*      set_constructors.cpp

WHAT? 
- Ordered container always stores unique values in sorted order.
- Sorting is done using Compare() function.
- Implemented internally as RB Trees.

********COMPLEXITY***********
- insert, remove, search: O(logn)

**********CONSTRUCTORS************
1. Default Ctr
2. Range Ctr
3. Copy Ctr: Since C++11
4. Move Ctr: Since C++11
5. Initializer-list constructor: Since C++11


********HOW SET IS IMPLEMENTED INTERNALLY***********
- Every container is defined as template class. class provides templated contructors/functions. 

/usr/include/c++/8/profile/set.h
namespace std _GLIBCXX_VISIBILITY(default){
    namespace __profile{

        template<typename _Key, typename _Compare = std::less<_Key>,
           typename _Allocator = std::allocator<_Key> >

        class set                                                       <<<<<SET CLASS
        : public _GLIBCXX_STD_C::set<_Key,_Compare,_Allocator>,
        public _Ordered_profile<set<_Key, _Compare, _Allocator> >{
            set() = default;
            set(const set&) = default;
            set(set&&) = default;
            ~set() = default;

        //////////RANGE CTR//////////
        template<typename T>
        set(T __first, T __last, const _Compare& __comp = _Compare(),
            const _Allocator& __a = _Allocator())
        : _Base(__first, __last, __comp, __a) { }
            
        //////////COPY CTR///////////
        explicit set(const _Allocator& __a) : _Base(__a) { }    

        //////////MOVE CTR//////////
        set(set&& __x, const _Allocator& __a)
        noexcept( noexcept(_Base(std::move(__x), __a)) )
        : _Base(std::move(__x), __a) { }

        /////////INITIALIZER LIST CTR////////
        set(initializer_list<value_type> __l, const _Allocator& __a)
        : _Base(__l, __a) { }
        }
    }
}
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
        /*1. DEFAULT CTR
           Constructs empty container.
         explicit set( const Allocator& alloc );
         */
        set<string> a;
        for(auto i:a)
                cout<<i;                //Nothing printed
        cout<<endl;
        a.insert("cat");
        a.insert("dog");
        a.insert("horse");
        for(auto i:a)
                cout<<i<<" ";           //cat dog horse
        cout<<endl;


        /*2. RANGE CTR
          Constructs the container from range [first, last). 
          If multiple elements in the range have keys that compare equivalent,
          it is unspecified which element is inserted.

         template< typename T >
         set( T first, T last, const Allocator& alloc) : 
         set(first, last, Compare(), alloc) {}    
         */
        set<string> b(a.find("dog"), a.end());
        for(auto i: b)
                cout << i << ' ';               //dog horse
        cout << endl;


        /*3. COPY CTR
         Constructs the container with the copy of the contents of other.

         set( const set& other, const Allocator& alloc );
         */
        set<string> c(a);
        c.insert("another horse");              //another horse cat dog horse
        for(auto i: c)
                cout << i << ' ';
        cout << endl;


        /*4. MOVE CTR
         Constructs the container with the contents of other using move semantics.

         set( set&& other );                            //Since C++11
         set( set&& other, const Allocator& alloc );    //Since C++11
         */
        set<string> d(move(a));
        for(auto i : d)
                cout << i << ' ';               //cat dog horse
        cout << endl;
        cout << "Original set:";
        for(auto i : a)
                cout << i << ' ';               //Nothing
        cout << endl;


        /* 5. INITIALIZER LIST CTR
        Constructs the container with the contents of the initializer list init.
        if multiple elements in the range have keys that compare equivalent,
        it is unspecified which element is inserted

        set( initializer_list<value_type> init, const Compare& comp = Compare(),
        const Allocator& alloc = Allocator() );
        */
        set<string> e {"one", "two", "three", "five", "eight"};
        for(auto i: e)
                cout << i << ' ';
        cout << '\n';
}
