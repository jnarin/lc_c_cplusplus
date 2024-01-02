/*
Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
Problem: 2610. Convert an Array Into a 2D Array With Conditions
*/


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<vector<int>> ans;
        
        for (auto &n : nums) {
            m[n]++;
            
            if (m[n] > ans.size()) {
                ans.push_back({});
            }
            
            ans[m[n] - 1].push_back(n);
        }
        
        return ans;
    }
};