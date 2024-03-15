/*
Link: https://leetcode.com/problems/product-of-array-except-self/
Problem: 238. Product of Array Except Self
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int left, right, *ans = calloc(numsSize, sizeof(int)), i;
    
    left = right = 1;
    
    for (i = 0; i < numsSize; i++) {
        ans[i] = left;
        left *= nums[i];
    }
    
    for (i = numsSize - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }
    
    *returnSize = numsSize;
    
    return ans;
}