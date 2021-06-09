## Find Majority Element
- **Majority element** is the element that appears more than `n / 2` times. Examples
```c
Input: a = [3,2,3]
Output: 3                       //a.size()=3. 3 appears 2 times

Input: a = [2,2,1,1,1,2,2]
Output: 2                       //a.size()=7. 2 appears 4 times
```
- **Algorithm**
  - _1._ Maintain a count variable. Take `a[0]` as majority element
  - _2._ Increment the count, whenever we find current element = majority element.
  - _3._ Decrement the count, whenever current element != majority element. 
  - _4._ Whenever count equals 0, forget everything Take the current element as majority element.
- **Code**
```c++
int majorityElement(vector<int>& a) {         //Faster than 50.71%. Ternary Operator Makes Code 50% Fast!!
  int Count = 0, MajorityElement = 0;
  for (auto i:a){
    if (Count == 0)                         //1
      MajorityElement = i;
    Count += (i == MajorityElement) ? 1 : -1;       //2,3
}

#if 0                                        //Simplified   //Faster than 7.10%
int majorityElement(vector<int>& a) {
  int Count = 0, MajorityElement = 0; 
  for (int i=0; i<a.size(); ++i){
    if (!Count)
      MajorityElement = a[i];
    if (a[i] == MajorityElement)
      ++Count;
    else
      --Count;
  }
  return MajorityElement;
}  
#endif 

int main() {
  vector<int> a = {2,2,1,1,1,2,2};
  cout << majorityElement(a);
}
```
