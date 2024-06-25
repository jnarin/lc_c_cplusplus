/*
Problem: 945. Minimum Increment to Make Array Unique
Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
*/

class Solution {
 public:
  int minIncrementForUnique(vector<int>& nums) {
    int ans = 0;
    int minAvailable = 0;

    ranges::sort(nums);

    for (const int num : nums) {
      ans += max(minAvailable - num, 0);
      minAvailable = max(minAvailable, num) + 1;
    }

    return ans;
  }
};