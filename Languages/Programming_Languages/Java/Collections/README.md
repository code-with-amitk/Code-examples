**Collections**
- [Hashmap](#hm)
- [Hashset](#hs)

## Collections
<a name=hm></a>
### HashMap `<key,value>`
- Cannot store duplicate keys on hashmap, original value will be replaced.
```java
map <--implements-- AbstractMap <--extends-- HashMap

      HashMap<Integer, String> hash_map = new HashMap<Integer, String>();
  
      /// Insert
      hash_map.put(10, "Geeks");
      hash_map.put(15, "4");
      hash_map.put(20, "Geeks");
        
      /// Search Key
      boolean a = hash_map.containsKey(20));          //return true/false if key is present or not
      String value = hash_map.get(15);          //Return value for key
      
      /// Print all
      for (Map.Entry temp:hm.entrySet())
            S.o.p(temp.getValue());
```

<a name=hs></a>
### Hashset
HashSet contains unique elements only.
```java
import java.util.*;  
class HashSet1{  
 public static void main(String args[]){  
      HashSet<String> set=new HashSet();  
      
      /// Insert
      set.add("One");         
      set.add("two");    
      
      /// Print
      Iterator<String> i=set.iterator();  
      while(i.hasNext())  
           System.out.println(i.next());
```
