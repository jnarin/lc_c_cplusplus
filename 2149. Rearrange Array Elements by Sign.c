/*
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
Problem: 2149. Rearrange Array Elements by Sign
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int));
    int i, p, n;
    
    i = p = n = 0;
    
    while (i < numsSize) {
        while (p < numsSize && nums[p] < 0) {
            p++;
        }
        
        if (p < numsSize) {
            ans[i++] = nums[p++];
        }
        
        while (n < numsSize && nums[n] > 0) {
            n++;
        }
        
        if (n < numsSize) {
            ans[i++] = nums[n++];
        }
        
    }
    
    *returnSize = numsSize;
    return ans;
}