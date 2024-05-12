/*
 * Problem: 2997. Minimum Number of Operations to Make Array XOR Equal to K
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
 * */

static int getSetBits(int n) {
    int c;

    for (c = 0; n; c++) {
        n &= (n - 1);
    }

    return c;
}

int minOperations(int* nums, int numsSize, int k) {
    int xor_total = 0, i;

    for (i = 0; i < numsSize; i++) {
        xor_total ^= nums[i];
    }

    int t = xor_total ^ k;

    return getSetBits(t);
}
