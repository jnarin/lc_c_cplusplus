/*
Problem: 2221. Find Triangular Sum of an Array
Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/
*/

int triangularSum(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
   
    int dp[numsSize], i, k, ans = 0;
    
    dp[0] = 1;
    for (k = 1; k < numsSize; k++) {
        dp[k] = 0;
    }
    
    for (i = 1; i < numsSize; i++) {
        for (int k = i; k >= 1; k--) {
            dp[k] = (dp[k] + dp[k-1]) % 10;
        }
    }

    for (i = 0; i < numsSize; i++) {
        ans = (ans + (nums[i] * dp[i]) % 10) % 10;
    }
    
    return ans;
}
