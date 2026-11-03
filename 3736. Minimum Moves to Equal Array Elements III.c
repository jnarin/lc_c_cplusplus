/*
Problem: 3736. Minimum Moves to Equal Array Elements III
Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
*/

static int getMax(int *nums, int numsSize) {
    int max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
    }

    return max;
}

int minMoves(int* nums, int numsSize) {
    int ans = 0, max;

    max = getMax(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        ans += max - nums[i];
    }

    return ans;
}
