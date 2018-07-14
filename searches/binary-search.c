/* Logic:
 * 	- Divide array into 2 halves.
 * 	- Jump in mid+1 if element to be found > ar[mid]
 * 	- Else jump in 0 to mid-1 half
 */
#include<stdio.h>
int bin (int ar[], int start, int end, int ele) {
	int val;
	if (start >= end) return 0;
	int mid = (end + start) / 2;
	if (ar[mid] == ele || ar[end] == ele || ar[start] == ele)
		return 1;
	if (ar[mid] < ele)
		val = bin (ar, mid+1, end, ele);
	else
		val = bin (ar, start, mid-1, ele);
	return val;
}
void main() {
	int a[] = {1,2,3,4,5,6,7,8, 9};
	int ele = 90;	//element to be searched
	//bin(array, startIndex, endIndex, elementToBeSearched)
	if (bin (a, 0, 8,  ele))
		printf("Element Found");
	else
		printf("Not Found");
}

/* Output
 * Not Found
 */
