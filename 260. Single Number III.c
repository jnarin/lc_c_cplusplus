/*
Problem: 260. Single Number III
Link: https://leetcode.com/problems/single-number-iii/
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* singleNumber(int* nums, int numsSize, int* returnSize){
    int *ans = calloc(2, sizeof(int)), i;
    *returnSize = 2;
    
    long xor_sum, t;
    xor_sum = t = 0;
    
    for (i = 0; i < numsSize; i++){
        xor_sum ^= nums[i];
    }
    
    t = xor_sum & -(xor_sum);
    
    for (i = 0; i < numsSize; i++){
        if (nums[i] & t){
            ans[0] ^= nums[i];
        } else {
            ans[1] ^= nums[i];
        }
    }
    
    return ans;
}