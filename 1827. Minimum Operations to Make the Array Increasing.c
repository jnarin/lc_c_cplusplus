/*
 * Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
 * Problem: 1827. Minimum Operations to Make the Array Increasing
 * */



int minOperations(int* nums, int numsSize){
    int ans = 0, i;

    for (i = 1; i < numsSize; i++){
        if (nums[i] <= nums[i - 1]){
            ans += nums[i - 1] + 1 - nums[i];
            nums[i] = nums[i - 1] + 1;
        }
    }

    return ans;
}
