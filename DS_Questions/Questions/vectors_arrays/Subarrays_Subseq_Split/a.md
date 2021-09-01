**Sub Array having sum equal to k**
Given an array of positive integers, find a subarray such that the sum of the subarray is equal to K. If there exists such multiple subarray, then return the one with smallest interval length subarray.
- Example
```c
Input=[1,2,3,7,5]. k=12
Output=[7,5]

Input=[1,2,3]. k=12
Output=[-1]
```

### Code
```c
#include <iostream>
#include <vector>
using namespace std;

Logic(Per test case):
	a. Store incoming array into vector.
	b. Take 1 element-i at a time
		b1. Calculate sum of (i+1), (i+n)
		b2. if (calculated_sum > exepected_sum)
			Move to next element
		    else if (calculated_sum == expected_sum)
			Start_position = (i+1)
			End_position = (k+1)
*/

/*Input set
3
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
74 665
142 112 54 69 148 45 63 158 38 60 124 142 130 179 117 36 191 43 89 107 41 143 65 49 47 6 91 130 171 151 7 102 194 149 30 24 85 155 157 41 167 177 132 109 145 40 27 124 138 139 119 83 130 142 34 116 40 59 105 131 178 107 74 187 22 146 125 73 71 30 178 174 98 113

Output set
2 4
1 5
-1
 */

int main() {	//working	[Execution time: .54sec]
	int num_of_test_cases, elements_in_array, expected_sum, array_element;
	int i,j,k,sum=0,first_pos=0,last_pos=0,sum_found=0;
	vector<int> array;
	
	cin>>num_of_test_cases;
	for(i=0;i<num_of_test_cases;i++){
	    cin>>elements_in_array;
	    cin>>expected_sum;
//	    cout<<"element_in_array="<<elements_in_array<<"expected_sum="<<expected_sum<<endl;
	    sum = 0, sum_found = 0;
	  
	    for(j=0;j<elements_in_array;j++){		//Store elements in vector
	        cin>>array_element;
	        array.push_back(array_element);
	    }
	    //cout<<"elementes in Array\n";
	    /*for(j=0;j<elements_in_array;j++){
		cout<<array[j]<<"\t";
	    } 	
	    cout<<endl;*/

	    for(k=first_pos;k<elements_in_array;k++){	//Take 1 element at a time, calculate sum.
//		cout<<"start k="<<k<<endl;
		sum = sum + array[k];
//		cout<<"sum="<<sum<<endl;
//		cout<<"expected_sum="<<expected_sum<<endl;
		if(sum == expected_sum){
			last_pos = k;
			sum_found = 1;
			break;
		}
		else if(sum > expected_sum){
			first_pos = first_pos + 1;
			k = first_pos-1;
//			cout<<"sum > expected_sum, first_pos="<<first_pos<<" k="<<k<<endl;
			sum_found = 0;		
			sum = 0;
		}else{
			sum_found = 0;
		}
//		cout<<"at end sum="<<sum<<endl<<endl;
	    }
	    if(sum_found){
//	    cout<<"\n\n------FOUND-----\n\n";
	    cout<<first_pos+1<<" "<<last_pos+1;
	    }else{
//		cout<<"Not found"<<"\n";
		cout<<"-1";
	    }
	    cout<<"\n";
	    first_pos=0, last_pos=0;
	    array.clear();
	}
	return 0;
}
