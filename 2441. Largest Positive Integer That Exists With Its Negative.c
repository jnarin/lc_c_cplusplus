/*
 * Problem: 2441. Largest Positive Integer That Exists With Its Negative
 * Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
 * */

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int findMaxK(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), incrCmp);

    int l = 0, r = numsSize - 1;

    while (l < r) {
        if (nums[l] == nums[r]) {
            break;
        }

        if (abs(nums[l]) == nums[r]) {
            return nums[r];
        }

        if (abs(nums[l]) > nums[r]) {
            l++;
        } else {
            r--;
        }
    }

    return -1;
}
