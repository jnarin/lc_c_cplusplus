/*
 * Problem: 41. First Missing Positive
 * Link: https://leetcode.com/problems/first-missing-positive/
 * */

int firstMissingPositive(int* nums, int numsSize) {
    int i;

    for (i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1])
        {
            int t, a;
            a = t = nums[i];

            nums[i]  = nums[a - 1];
            nums[a - 1] = t;
        }
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return numsSize + 1;
}

