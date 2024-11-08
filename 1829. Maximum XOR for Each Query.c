/*
Problem: 1829. Maximum XOR for Each Query
Link: https://leetcode.com/problems/maximum-xor-for-each-query
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    
    int i, curr, mask = (1 << maximumBit) - 1;
    
    for (i = 0, curr = 0; i < numsSize; i++) {
        curr ^= nums[i];
        ans[numsSize - i - 1] = ~curr & mask;
    }
    
    return ans;
}
