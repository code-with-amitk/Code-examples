//# g++ lru_cache.cpp -std=c++11

#include<iostream>
#include <bits/stdc++.h>
#include<unordered_map>
/*
 * How Simple it became to implement from STLs, else ..
 *
 * Logic:
 * Datastructures for cache implementation:
 *      a. std::list <int> - Doubly LL storing contents of cache
 *      b. std::unordered_map<int, std::list<int>::iterator> - hash table for O(1)
 *              - A key can exist only once in hash table.
 *      
 * How cache is maintained?
 *  1. Check (key) if is not present in hashtable. This means:
 *      -> value is not present in Actual cache. Since key maps to value
 *      -> value not present means, either cache is full of completely empty
 *              - if (cache==full)      Remove LRU(last entry) from cache
 *                else (cache==empty)   Place entry at front
 *  2. if key is present in hashtable
 *      - Remove last entry.
 *      - Place new key in front of cache. list.push_front()
 */
typedef enum{ choclate, strawberry, vanilla, pound }cakes;

class cache{            //Implemets LRUCache for pastry shop

        //Doubly LL storing contents of cache
        std::list <int> double_queue;

        //unordered map to implement hash table
        std::unordered_map<int, std::list<int>::iterator> ht;

        //Max capacity of cache
        int cache_size;
public:
        cache(int a){   //Constructor to initialize cache
                cache_size = a;
        }
        void find(int);
        void display();
};

//
void cache::find(int key_value){
/* find(key) returns iterator if element is found
 * std::unordered_map<std::string,double>::const_iterator got = mymap.find (input);
 *   if ( got == mymap.end() )
 *      std::cout << "not found";
 *   else
 *      std::cout << got->first << " is " << got->second;
 */

/* end() Returns an iterator pointing to the past-the-end element in the unordered_map container.
 * iterator returned by end does not point to any element.
 */
        //Key is not found in map.
        if(ht.find(key_value) == ht.end()){

                if(double_queue.size() == cache_size){//Queue is already full

                        //Get Least Recently used item
                        int last = double_queue.back();

                        //Remove last item
                        double_queue.pop_back();

                        //Erase key from Hashtable
                        ht.erase(last);
                }
         }

         else{  //key present in cache
                        //Erase value from double linked list
                        double_queue.erase(ht[key_value]);
         }

        //Place the element in front
         double_queue.push_front(key_value);
         ht[key_value] = double_queue.begin();
}

void cache::display(){
        for(auto var = double_queue.begin(); var != double_queue.end(); var++){
                std::cout<<(*var)<<" ";
//              cout<<endl;
        }
        std::cout<<std::endl;
}

int main(){
        cache obj(3);   //Let's take a cache of size=3
        obj.find(1);
        obj.display();

        obj.find(2);
        obj.display();

        obj.find(3);
        obj.display();

        obj.find(4);
        obj.display();

        obj.find(3);
        obj.display();
}
