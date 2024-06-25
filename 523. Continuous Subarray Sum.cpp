/*
Problem: 523. Continuous Subarray Sum
Link: https://leetcode.com/problems/continuous-subarray-sum/
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum, pre;
        unordered_set<int> modk;
        sum = pre = 0;

        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)){
                return true;
            }

            modk.insert(pre);
            pre = mod;
        }

        return false;
    }
};