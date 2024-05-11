/*
 * Problem: 2444. Count Subarrays With Fixed Bounds
 * Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
 * */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long ans = 0;
    int i, j, prevMinKIndex, prevMaxKIndex;

    j = prevMinKIndex = prevMaxKIndex = -1;

    for (i = 0; i <numsSize; i++) {
        j = nums[i] < minK || nums[i] > maxK ? i : j;
        prevMinKIndex = nums[i] == minK ? i : prevMinKIndex;
        prevMaxKIndex = nums[i] == maxK ? i : prevMaxKIndex;

        ans += MAXVAL(0, MINVAL(prevMinKIndex, prevMaxKIndex) - j);
    }

    return ans;
}
