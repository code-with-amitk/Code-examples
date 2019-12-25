#include <bits/stdc++.h>
using namespace std;


/* Logic-1: O(n3)       //n cube
 - Run 3 nested for loops.
        x = a[0]*a[0]     
        y = a[1]*a[1]     
        z = a[2]*a[2]
        
        check any combination satisfies the rule?
        if (a==b+c || b==c+a || c==a+b)
                return true
 */
bool method-1(int arr[], int sizeofArr){
    for (int i = 0; i < sizeofArr; i++) {
        for (int j = i + 1; j < sizeofArr; j++) {
            for (int k = j + 1; k < sizeofArr; k++) {

                int x = ar[i]*ar[i], y = ar[j]*ar[j], z = ar[k]*ar[k];

                if (x == y + z || y == x + z || z == x + y)
                    return true;
            }
        }
    }
    return false;
}


/* Logic-2(Sorting): O(n2)                              //n square
  - Square the elements in original array.              O(n)
  - Sort the squared elements.                          O(nlogn)
  - iterate through the array to find triplet           O(n2)
        a = last_element_of_array, Largest
        l = first_element
        r = last-1

        while(l<r)
                if(ar[l] + ar[r] == ar[a])
                        found
                if(first_element+(last-1) < a)
                        first_element++
                else
                        last-1-1

*/
bool method-2(int arr[], int sizeofArr){
    int i;

    for(i = 0; i < sizeofArr; i++)              //Square the elements O(n)
        arr[i] = arr[i]*arr[i];

    sort(arr, arr + sizeofArr);                 //Sort array elements. O(nlogn)

    for (i = sizeofArr - 1; i >= 2; i--) {
        int l = 0;                              //index of the first element in arr[0..i-1] 
        int r = i - 1;                          //index of the last element in arr[0..i-1] 
        while (l < r) {
            if (arr[l] + arr[r] == arr[i])
                return true;

            (arr[l] + arr[r] < arr[i]) ? l++ : r--;
        }
    }
    return false;
}

/*Logic-3: using Hashing.       BUT I AM NOT CLEAR WITH THIS.
{ 3, 2, 4, 6, 5 }
 a. Find maximum element from array. Here 6
 b. Take hash_array of size max_element+1 = 7, Initialize to 0.
 c. Make all elements of hash_array=1 whose index=original_element.
 d. 
 */
bool checkTriplet(int arr[], int n)
{
    int maximum = 0;

    for (int i = 0; i < n; i++) {               //O(n). Find max element from array
        maximum = max(maximum, arr[i]);
    }

    int hash[maximum + 1] = { 0 };

    for (int i = 0; i < n; i++){
        hash[arr[i]] = 1;
    }

    // Iterate for all possible a 
    for (int i = 1; i < maximum + 1; i++) {

        // If a is not there 
        if (hash[i] == 0)
            continue;

        // Iterate for all possible b 
        for (int j = 1; j < maximum + 1; j++) {

            // If a and b are same and there is only one a 
            // or if there is no b in original array 
            if ((i == j && hash[i] == 1) || hash[j] == 0)
                continue;

            // Find c 
            int val = sqrt(i * i + j * j);

            // If c^2 is not a perfect square 
            if ((val * val) != (i * i + j * j))
                continue;

            // If c exceeds the maximum value 
            if (val > maximum)
                continue;

            // If there exists c in the original array, 
            // we have the triplet 
            if (hash[val]) {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = { 3, 2, 4, 6, 5 };
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    if (checkTriplet(arr, sizeOfArr))
        cout << "Yes";
    else
        cout << "No";
}
