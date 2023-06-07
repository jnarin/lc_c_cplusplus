/* 
 * Link: https://leetcode.com/problems/apply-operations-to-an-array/
 * Problem: 2460. Apply Operations to an Array
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize){
    int i;
    
    for (i = 1; i < numsSize; i++){
        if (nums[i - 1] == nums[i]){
            nums[i - 1] <<= 1;
            nums[i] = 0;
        }
    }
    
    int *ans = calloc(numsSize, sizeof(int)), j = 0;
    *returnSize = numsSize;
    for (i = 0; i < numsSize; i++){
        if (nums[i]){
            ans[j++] = nums[i];
        }
    }
    
    return ans;
}
