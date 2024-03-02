/*
 * Link: https://leetcode.com/problems/squares-of-a-sorted-array/
 * Problem: 977. Squares of a Sorted Array
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SQUARE(n) ((n) * (n))

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    int l, r, idx;

    l = 0;
    r = idx = numsSize - 1;

    while (l <= r) {
        if (abs(nums[l]) > abs(nums[r])) {
            ans[idx] = SQUARE(nums[l]);
            l++;
        } else {
            ans[idx] = SQUARE(nums[r]);
            r--;
        }

        idx--;
    }

    return ans;
}
