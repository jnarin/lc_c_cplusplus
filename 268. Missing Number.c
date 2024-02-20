/*
Link: https://leetcode.com/problems/missing-number/
Problem: 268. Missing Number
*/

static int arraySum(int *nums, int numsSize) {
    int sum = 0, i;
    
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    return sum;
}

int missingNumber(int* nums, int numsSize) {
    return ((numsSize * (numsSize + 1)) >> 1) - arraySum(nums, numsSize);
}