/*
Problem: 2200. Find All K-Distant Indices in an Array
Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int)), idx = 0, i, j;
    
    for (i = 0, j = 0; i < numsSize; i++) {
        while (j < numsSize && (nums[j] != key || j < i - k)) {
            j++;
        }

        if (j == numsSize) {
            break;
        }

        if (abs(i - j) <= k) {
            ans[idx++] = i;
        }
    }

    *returnSize = idx;

    return ans;

}
