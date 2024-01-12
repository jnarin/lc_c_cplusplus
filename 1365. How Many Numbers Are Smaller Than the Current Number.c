/*
Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
Problem: 1365. How Many Numbers Are Smaller Than the Current Number
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_NUM (101)

static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int sortedNums[numsSize], *ans = calloc(numsSize, sizeof(int)), i, map[MAX_NUM] = {0};
    *returnSize = numsSize;
    
    memcpy(sortedNums, nums, numsSize * sizeof(int));
    
    qsort(sortedNums, numsSize, sizeof(int), decrCmp);
    
    for (i = 0; i < numsSize; i++) {
        map[sortedNums[i]] = i;
    }
    
    for (i = 0; i < numsSize; i++) {
        ans[i] = numsSize - 1 - map[nums[i]];
    }
    
    return ans;
}

