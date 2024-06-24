/*
Problem: 78. Subsets
Link: https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> r;
        
        subsetsHelper(nums, ans, r, 0);
        
        return ans;
    }
    
private:
    void subsetsHelper(vector<int> &nums, vector<vector<int>> &ans, vector<int> r, int i) {
        if (i >= nums.size()) {
            ans.push_back(r);
            r.clear();
            return;
        }
        
        r.push_back(nums[i]);
        subsetsHelper(nums, ans, r, i + 1);
        r.pop_back();
        subsetsHelper(nums, ans, r, i + 1);
        
        return;
    }
};