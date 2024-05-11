/*
 * Problem: 442. Find All Duplicates in an Array
 * Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int)), idx = 0, i;

    for (i = 0; i < numsSize; i++) {
        nums[abs(nums[i]) - 1] *= -1;

        if (nums[abs(nums[i]) - 1] > 0) {
            ans[idx++] = abs(nums[i]);
        }
    }

    *returnSize = idx;
    return ans;
}

