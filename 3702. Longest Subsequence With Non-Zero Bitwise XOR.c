/*
Problem: 3702. Longest Subsequence With Non-Zero Bitwise XOR
Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
*/

static bool allElementsAreZero(int *nums, int numsSize) {
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i]) {
            return false;
        }
    }

    return true;
}

int longestSubsequence(int* nums, int numsSize) {
    int xor = 0, i;

    if (allElementsAreZero(nums, numsSize)) {
        return xor;
    }

    for (i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }

    return xor ? numsSize : numsSize - 1;   
}
