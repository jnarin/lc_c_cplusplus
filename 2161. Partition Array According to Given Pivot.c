/*
Problem: 2161. Partition Array According to Given Pivot
Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int left[numsSize], right[numsSize], i, l = 0, r = 0, pivotCount = 0;
     
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));

    for (i = 0;  i < numsSize; i++) {
        if (nums[i] < pivot) {
            left[l++] = nums[i];
        } else if (nums[i] == pivot) {
            pivotCount++;
        } else {
            right[r++] = nums[i];
        }
    }
    
    int *ans = calloc(numsSize, sizeof(int)), idx = 0;
    *returnSize = numsSize;

    for (i = 0; i < l; i++) {
        ans[idx++] = left[i];
    }

    while (pivotCount--) {
        ans[idx++] = pivot;
    }

    for (i = 0; i < r; i++) {
        ans[idx++] = right[i];
    }

    return ans;
}
