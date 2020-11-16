## [Design an Ordered Stream](https://leetcode.com/contest/weekly-contest-215/problems/design-an-ordered-stream/)
- There are n (id, value) pairs, where id is an integer between 1 and n and value is a string. No two pairs have the same id.
- Design a stream that takes the n pairs in an arbitrary order, and returns the values over several calls in increasing order of their ids.

- Implement the OrderedStream class:
- OrderedStream(int n) Constructs the stream to take n values and sets a current ptr to 1.
- String[] insert(int id, String value) Stores the new (id, value) pair in the stream. After storing the pair:
-If the stream has stored a pair with id = ptr, then find the longest contiguous incrementing sequence of ids starting with id = ptr and return a list of the values associated with those ids in order. Then, update ptr to the last id + 1.
Otherwise, return an empty list.

## Example
```c
Input
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
Output
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

Explanation
OrderedStream os= new OrderedStream(5);
os.insert(3, "ccccc"); // Inserts (3, "ccccc"), returns [].
os.insert(1, "aaaaa"); // Inserts (1, "aaaaa"), returns ["aaaaa"].
os.insert(2, "bbbbb"); // Inserts (2, "bbbbb"), returns ["bbbbb", "ccccc"].
os.insert(5, "eeeee"); // Inserts (5, "eeeee"), returns [].
os.insert(4, "ddddd"); // Inserts (4, "ddddd"), returns ["ddddd", "eeeee"].
```

## Logic

|bool,string->|1,aaaa|1,bbbb|1,cccc|1,eeeee|1,ddddd|
|index->|0|1|2|3|4|5|

## Code
```c++
class OrderedStream {
    vector<pair<bool, string>> vecStream;
    int iPointer;
public:
    OrderedStream(int a) : vecStream(a), iPointer(0) {}

    vector<string> insert(int x, string strValue) {
        vecStream[x - 1].first = true;
        vecStream[x - 1].second = strValue;

        vector<string> strResponse;

        while (iPointer < vecStream.size() &&
               vecStream[iPointer].first) {
            strResponse.push_back(vecStream[iPointer].second);
            ++iPointer;
        }
        return strResponse;
    }
};
```
