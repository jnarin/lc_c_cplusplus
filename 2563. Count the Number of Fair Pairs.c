/*
Problem: 2563. Count the Number of Fair Pairs
Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

long long countLess(int *nums, int numsSize, int target) {
    long long count = 0;
    int left = 0, right = numsSize - 1;

    while (left < right) {
        if (nums[left] + nums[right] <= target) {
            count += right - left;
            left++;
        } else {
            right--;
        }
    }

    return count;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), incrCmp);

    return countLess(nums, numsSize, upper) - countLess(nums, numsSize, lower - 1);
}
