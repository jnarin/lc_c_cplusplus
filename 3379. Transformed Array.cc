/*
Problem: 3379. Transformed Array
Link: https://leetcode.com/problems/transformed-array/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int)), i, idx;
    *returnSize = numsSize;

    for (i = 0; i < numsSize; i++) {
        ans[i] = nums[(i + nums[i] % numsSize + numsSize) % numsSize];
    }
    
    return ans;
}
