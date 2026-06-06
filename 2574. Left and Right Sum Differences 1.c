/*
Problem: 2574. Left and Right Sum Differences
Link: https://leetcode.com/problems/left-and-right-sum-differences/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize){
    int leftSum[numsSize], rightSum[numsSize], i, *ans = calloc(numsSize, sizeof(int));

    leftSum[0] = 0;
    for (i = 1; i < numsSize; i++) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }

    rightSum[numsSize - 1] = 0;
    for (i = numsSize - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }
    
    for (i = 0; i < numsSize; i++) {
        ans[i] = abs(leftSum[i] - rightSum[i]);
    }

    *returnSize = numsSize;
    return ans;
}
