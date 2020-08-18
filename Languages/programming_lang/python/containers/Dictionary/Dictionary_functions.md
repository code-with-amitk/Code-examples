## Dictonary Functions

| Function | What|
|---|---|
|1. del(dic`[key]`) | Delete key from Dictionary |
|2. list(dic)| Print all keys|
|3. sorted(dic) | Print keys in sorted order|
|4. items()|retrieve (key,value) from dictionary|
|5. enumerate()|retrieve (index,key) from dictionary|
|6. zip(*iterables)|takes iterables(zero or more), packs them in a tuple, and return it. iterables like: list, string, dict|

```
d = {5: 'e', 1: 'a', 2: 'b', 3: 'c', 4: 'd'}

print(d)                            #{5: 'e', 1: 'a', 2: 'b', 3: 'c', 4: 'd'}

del(a[3])                           #{5: 'e', 1: 'a', 2: 'b', 4: 'd'}   //1

print(list(d))                      #[5, 1, 2, 4]   //2
print(sorted(d))                    #[1, 2, 4, 5]   //3

for i,j in d.items():               
  print (i,j)                       #5 e    1 a   2 b   4 d   //4
  
for i, j in enumerate(d):
  print(i,j)                        #0 5    1 1   2 2   3 4   //5

questions=['a','b','c']             //6
answers=['x','y','z']
for i, j in zip(questions, answers):
  print(format('Question:{0} Answer:{1}'.format(i,j)))    #Question:a Answer:x
```
