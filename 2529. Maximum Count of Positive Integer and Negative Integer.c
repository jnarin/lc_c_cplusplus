/*
Problem: 2529. Maximum Count of Positive Integer and Negative Integer
Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*/

#define MAXVAL(a, b) ((a) > (b) ? (a) : (b))

static int lastNegative(int *nums, int numsSize) {
    int left = 0, right = numsSize - 1, ans = -1, mid;

    while (left <= right) {
        mid = (left + right) >> 1;

        if (nums[mid] < 0) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

static int firstPositive(int *nums, int numsSize) {
    int left = 0, right = numsSize - 1, ans = numsSize, mid;

    while (left <= right) {
        mid = (left + right) >> 1;

        if (nums[mid] > 0) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int maximumCount(int* nums, int numsSize) {
    int lastNegPos = lastNegative(nums, numsSize) + 1, 
        firstPosPos = numsSize - firstPositive(nums, numsSize);

    return MAXVAL(lastNegPos, firstPosPos);
}
