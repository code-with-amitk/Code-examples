#include<iostream>
#include<vector>
using namespace std;
/*Problem: Print the maximum sum of the contiguous sub-array in a separate line for each test case.
Expected Time Limit < 0.372sec
Input
        3       //no of test cases
        5       //array elements in each test case
        1 2 3 -2 5
        4
        -1 -2 -3 -4
        3
        -2 5 -1
Output
        9       //Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray
        -1
        5

Logic:
        a. Store elements in vector
        b. Traverse each element in vector
                largest_sum = vector_element[0]
                sum = sum + vector_element[i]
                if(vector_element[i] > sum)
                        sum = vector_element[i]
                if(sum > largest_sum)
                        largest_sum = sum
*/
int main()
{
        int num_of_test_cases, elements_in_array, sum=0, array_element, larget_sum;
        vector<int> array;
        int i,j,k,l;

        cin>>num_of_test_cases;
        for(i=0;i<num_of_test_cases;i++){
                cin>>elements_in_array;
                for(j=0;j<elements_in_array;j++){           //Store elements in vector
                        cin>>array_element;
                        array.push_back(array_element);
                }
                larget_sum = array[0];
                for(k=0;k<elements_in_array;k++){
                        sum = sum + array[k];
                        if (array[k] > sum)
                                sum = array[k];
                        if (sum > larget_sum)
                            larget_sum = sum;
                }
                //cout<<"largest_sum="<<larget_sum;
                cout<<larget_sum<<"\n";
                array.clear();
                sum = 0;
        }
        //cout << "Maximum contiguous sum is " << max_sum; 
        return 0;
}
