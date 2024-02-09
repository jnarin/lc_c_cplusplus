/*
Link: https://leetcode.com/problems/largest-divisible-subset/
Problem: 368. Largest Divisible Subset
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int)), i, lis[numsSize + 1], 
        n = 1, p = -1, j, idx = 0;
    
    qsort(nums, numsSize, sizeof(int), incrCmp);
    
    for (i = 0; i < numsSize + 1; i++) {
        lis[i] = 1;
    }
    
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && lis[i] < (lis[j] + 1)) {
                lis[i] = lis[j] + 1;
                
                n = n < lis[i] ? lis[i] : n;
            }
        }
    }
    
    for (i = numsSize - 1; i >= 0; i--) {
        if (lis[i] == n && (p == -1 || p % nums[i] == 0)) {
            ans[idx++] = nums[i];
            n -= 1;
            p = nums[i];
        }
    }
    
    *returnSize = idx;
    
    return ans;
}