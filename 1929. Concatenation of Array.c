/*
Problem: 1929. Concatenation of Array
Link: https://leetcode.com/problems/concatenation-of-array/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize * 2, sizeof(int));
    *returnSize = numsSize * 2;
    
    memcpy(&ans[0], nums, numsSize * sizeof(int));
    memcpy(&ans[numsSize], nums, numsSize * sizeof(int));
    
    return ans;
}
