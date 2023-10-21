/*
 * Link: https://leetcode.com/problems/constrained-subsequence-sum/
 * Problem: 1425. Constrained Subsequence Sum
 * */

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        deque<int> dq;
        int i, ans = INT_MIN;

        for (i = 0; i < nums.size(); i++){
            dp[i] = dq.size() ? max(dq.front(), 0) + nums[i] : nums[i];
            while (dq.size() && dq.back() < dp[i]){
                dq.pop_back();
            }

            dq.push_back(dp[i]);

            if (i >= k && dp[i - k] == dq.front()){
                dq.pop_front();
            }
        }

        for (auto &it : dp){
            ans = max(it, ans);
        }

        return ans;
    }
};
