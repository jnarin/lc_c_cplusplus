/*
Problem: 1574. Shortest Subarray to be Removed to Make Array Sorted
Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int findLengthOfShortestSubarray(int* arr, int arrSize) {
   int left = 0, right = arrSize - 1;

   while (left < arrSize - 1 && arr[left] <= arr[left + 1]) {
       left++;
   }

   while (right > 0 && arr[right] >= arr[right - 1]) {
       right--;
   }

   int ans = MINVAL(arrSize - left - 1, right);

   int i = left, j = arrSize - 1;

   while (i >= 0 && j >= right && j > i) {
       if (arr[i] <= arr[j]) {
           j--;
       } else {
           i--;
       }

       ans = MINVAL(ans, j - i);
   }

    return ans;
}
