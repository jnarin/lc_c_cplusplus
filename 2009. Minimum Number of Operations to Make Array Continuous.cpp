/*
Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
Problem: 2009. Minimum Number of Operations to Make Array Continuous
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len, ans, i, start, end, idx, uniqueLen;
        len = ans = nums.size();
        
        sort(nums.begin(), nums.end());
        
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

        for (i = 0; i < nums.size(); i++){
            start = nums[i];
            end = start + len - 1;
            idx = upper_bound(nums.begin(), nums.end(), end) - nums.begin();
            uniqueLen = idx - i;
            ans = min(ans, len - uniqueLen);
        }
        
        return ans;
    }
};