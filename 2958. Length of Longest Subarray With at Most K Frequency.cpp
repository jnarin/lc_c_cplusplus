/*
 * Problem: 2958. Length of Longest Subarray With at Most K Frequency
 * Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
 * */

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l, r, ans = 0;
        unordered_map<int, int> freq;

        for (l = 0, r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;
            while (freq[nums[r]] == k + 1) {
                freq[nums[l++]]--;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
