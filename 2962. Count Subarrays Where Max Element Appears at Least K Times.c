/*
 * Problem: 2962. Count Subarrays Where Max Element Appears at Least K Times
 * Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
 * */

static int getMax(int *nums, int numsSize) {
    int ans = INT_MIN, i;

    for (i = 0; i < numsSize; i++) {
        ans = nums[i] > ans ? nums[i] : ans;
    }

    return ans;
}

long long countSubarrays(int* nums, int numsSize, int k) {
    long long ans = 0;
    int maxElement = getMax(nums, numsSize), l, r, freq = 0;

    for (l = 0, r = 0; r < numsSize; r++) {
        freq = nums[r] == maxElement ? freq + 1 : freq;

        while (freq == k) {
            freq = nums[l++] == maxElement ? freq - 1 : freq;
        }

        ans += l;
    }

    return ans;
}

