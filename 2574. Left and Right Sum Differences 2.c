/*
Problem: 2574. Left and Right Sum Differences
Link: https://leetcode.com/problems/left-and-right-sum-differences/
*/

static int arraySum(int *nums, int numsSize) {
    int sum = 0, i;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return sum;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int)), leftSum, rightSum, i;

    leftSum = 0;
    rightSum = arraySum(nums, numsSize);

    for (i = 0; i < numsSize; i++) {
        rightSum -= nums[i];
        ans[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }
    
    *returnSize = numsSize;
    return ans;
}
