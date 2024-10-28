/*
Problem: 2501. Longest Square Streak in an Array
Link: https://leetcode.com/problems/longest-square-streak-in-an-array/
*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> s(nums.begin(), nums.end());
        int ans = -1, t;
        long long x;
        for (int& v : nums) {
            t = 0;
            x = v;
          
            while (s.count(x)) {
                x *= x;
                ++t;
            }
            if (t > 1) {
              ans = max(ans, t);
            }
        }
      
        return ans;
    }
};
