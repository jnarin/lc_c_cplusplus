/*
Problem: 674. Longest Continuous Increasing Subsequence
Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int findLengthOfLCIS(int* nums, int numsSize) {
    int l, r, ans;

    for (l = 0, r = 0; r < numsSize; r++) {
        if (r > 0 && nums[r] <= nums[r - 1]) {
            l = r;
        }
        
        ans = MAXVAL(ans, r - l + 1);
    }
    
    return ans;
}
