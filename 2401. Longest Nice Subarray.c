/*
Problem: 2401. Longest Nice Subarray
Link: https://leetcode.com/problems/longest-nice-subarray/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int longestNiceSubarray(int* nums, int numsSize) {
    int ans = 0, m = 0, l, r;

    for (l = 0, r = 0; r < numsSize; r++) {
        while (m & nums[r]) {
            m ^= nums[l++];
        }

        m |= nums[r];
        ans = MAXVAL(ans, r - l + 1);
    }

    return ans;    
}
