/*
Problem: 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int longestMonotonicSubarray(int* nums, int numsSize) {
    int ans = 1, increasing = 1, decreasing = 1, i;

    for (i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            decreasing++;
            increasing = 1;
        } else if (nums[i - 1] < nums[i]) {
            increasing++;
            decreasing = 1;
        } else {
            increasing = decreasing = 1;
        }

        ans = MAXVAL(ans, MAXVAL(increasing, decreasing));
    }
    
    return ans;
}
