/*
Problem: 66. Plus One
Link: https://leetcode.com/problems/plus-one/
*/

static void reverseIntArr(int *nums, int numsSize) {
    int i;

    for (i = 0; i < numsSize / 2; i++) {
        int t = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = t;
    }

    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ans = calloc(digitsSize + 1, sizeof(int)), idx = 0, i;
    
    for (i = 0; i < digitsSize; i++) {
        ans[i] = digits[i];
    }

    reverseIntArr(ans, digitsSize);

    int c = 0, s;

    for (i = 0; i < digitsSize; i++) {
        s = i == 0 ? ans[i] + 1 + c : ans[i] + c;

        if (s > 9) { 
            s -= 10;
            c = 1;
        } else {
            c = 0;
        }

        ans[i] = s;
    }

    if (c) {
        ans[i++] = 1;
    }

    reverseIntArr(ans, i);

    *returnSize = i;

    return ans;
}
