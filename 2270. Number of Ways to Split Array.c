/*
Problem: 2270. Number of Ways to Split Array
Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/
*/

static long arraySum(int *nums, int numsSize) {
    long ans = 0, i;

    for (i = 0; i < numsSize; i++) {
        ans += nums[i];
    }

    return ans;
}

int waysToSplitArray(int* nums, int numsSize) {
    int ans = 0, i; 
    long prefix = 0, suffix = arraySum(nums, numsSize);
    
    for (i = 0; i < numsSize - 1; i++) {
        prefix += nums[i];
        suffix -= nums[i];
        ans += prefix >= suffix ? 1 : 0;
    }

    return ans;
}
