/*
Problem: 2411. Smallest Subarrays With Maximum Bitwise OR
Link: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static void fillArray(int *array, int arraySize, int val) {
    int i;

    for (i = 0; i < arraySize; i++) {
        array[i] = val;
    }

    return;
}

int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int b[30], *ans, i, j, t, idx = 0;

    ans = calloc(numsSize, sizeof(int));
    fillArray(b, 30, -1);

    for (i = numsSize - 1; i >= 0; i--) {
        t = 1;
        for (j = 0; j < 30; j++) {
            if ((nums[i] >> j) & 1) 
            {
                b[j] = i;
            } else if (b[j] != -1) {
                t = MAXVAL(t, b[j] - i + 1);
            }
        }

        ans[i] = t;
    }

    *returnSize = numsSize;
    return ans;
}
