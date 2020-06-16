/* Your team is analyzing a flight of a plane. Your task is to find longest period of turbulance.
 * The height of plane above ground is measured once every second of the flight.
 *
 * Input is an Array representing Height of plane for every second.
 * [9,4,2,10,7,8,8,1,9]
 *
 * You need to find turbulence Period.
 * Turbulance Period is defined as 
 * Condition-1: When array elements are getting up and Down alternatively. Eg: 2424242. Turbulence->6
 * Contition-2: If 2 consecutive of array are either incresing or decreasing Eg: 4,8,12,16. Turbulence->2[4->8(increase),8->12(increase),12->16(increase)]
 *
 * Input: Array A[] contaning height in every second, N=Length of array
 *
 * Logic:
 * - Start from pos=1
 *   if(present_height > prev_height)
 *      increment increase counter.
 *      Make decerement counter to 1.
 *      But increment or decrement counter should take value from prev since turbulance is still continuing.
 *
 *   Calculate large of increment and decrement counter and This is turbulance period
 */

int main(){
//      int A[] = {9,4,2,10,7,8,8,1,9};
//      int b = solution(A,9);
        int A[] = {4,8,12,16};
        int b = solution(A,4);
//      int A[]={100};
//      int b = solution(A,1);
        printf("b=%d\n",b);
}

int large(int a, int b){
        if(a>b) return a;
        else    return b;
}

int solution(int A[], int N){

        int increasing = 1, decreasing = 1, i, tmp1=1,ret=1;

        for (i = 1; i < N; i++) {

            if (A[i] > A[i-1]) {
                increasing = decreasing + 1;
                decreasing = 1;
            } else if (A[i]< A[i-1]) {
                decreasing = increasing + 1;
                increasing = 1;
            } else {
                increasing = 1;
                decreasing = 1;
            }
                tmp1=large(increasing,decreasing);
                ret=large(ret,tmp1);
        }

          return ret;
}
