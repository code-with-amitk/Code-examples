/*	packet_stream_player.cpp

Input: Stream of n packets each of different size.
Video Player can only process packet having length as power of 2.
Task: Given input stream of packet lengths, we need to tell maximum lenghth of normalized packet.
Normalized packet means packet who

Example:
Input: {5,3,4,5,3,9,3}
Normalized array: {4,4,4,4,4,8,4)
Output: 8

(index=0) Nearst power of 5 is 4, so 5 normalized to 4 and gives its 1 to 3
(index=1) After getting 1 from 5. 3 becomes power of 2 hence normalized.
(index=2) 4 is already normalized nothing to be done
(index=3) 5 gives 1 to next element ie 3 and itself becomes 4
(index=4) 3+1=4 normalized
(index=5) 9 gives 1 to next element, since nearest power of 2 is 8
(index=6) 3+1=4 normalized

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

long f (long x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x - (x >> 1);
}

//long lr(vector<int> a){
void lr(vector<int> a){
	long lar=-1, prev, diff;

	for(int i=0;i<a.size();i++){
		prev = f(a[i]);
		diff = a[i]-prev;

		if(prev>lar)
			lar=prev;

		if(prev < a[i])
			a[i+1] += diff;
		
	}
	cout<<lar;
}

int main(){
	vector<int> v = {2,1,2,4,7,5};
	lr(v);	
}  
