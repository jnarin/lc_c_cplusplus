/*
 * Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 * Problem: 1685. Sum of Absolute Differences in a Sorted Array
 * */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize){
    int *ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    int prefix[numsSize], suffix[numsSize], i, l, r;

    prefix[0] = nums[0];
    for (i = 1; i < numsSize; i++){
        prefix[i] = prefix[i - 1] + nums[i];
    }

    suffix[numsSize - 1] = nums[numsSize - 1];
    for (i = numsSize - 2; i >= 0; i--){
        suffix[i] = suffix[i + 1] + nums[i];
    }

    for (i = 0; i < numsSize; i++){
        l = (nums[i] * (i + 1)) - prefix[i];
        r = suffix[i] - (nums[i] * (numsSize - i));
        ans[i] = l + r;
    }

    return ans;
}
