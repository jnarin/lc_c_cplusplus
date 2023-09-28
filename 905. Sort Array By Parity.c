/*
Link: https://leetcode.com/problems/sort-array-by-parity/
Problem: 905. Sort Array By Parity
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int odd_even_cmp(const void *a, const void *b){
    int x = *(int *)a, y = *(int *)b;
    
    if (x & 1){
        return 1;
    }
    
    if (y & 1){
        return -1;
    }
    
    return x < y ? -1 : 1;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), odd_even_cmp);
    *returnSize = numsSize;
    
    return nums;
}