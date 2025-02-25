/*
Problem: 1524. Number of Sub-arrays With Odd Sum
Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
*/

#define MOD ((int)(1e9 + 7))

int numOfSubarrays(int* arr, int arrSize) {
    int c[2] = {1, 0}, i, ans = 0, sum = 0;

    for (i = 0; i < arrSize; i++) {
        sum += arr[i];
        ans = (ans + c[sum & 1 ^ 1]) % MOD;
        c[sum & 1]++;
    }
    
    return ans;
}
