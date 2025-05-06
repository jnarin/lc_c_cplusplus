/*
Problem: 1920. Build Array from Permutation
Link: https://leetcode.com/problems/build-array-from-permutation/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int i, *ans = calloc(numsSize, sizeof(int));

    for (i = 0; i < numsSize; i++) {
        ans[i] = nums[nums[i]];
    }
    
    *returnSize = numsSize;
    return ans;
}
