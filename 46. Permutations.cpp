/*
Link: https://leetcode.com/problems/permutations/
Problem: 46. Permutations
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        
        dfs(nums, v, ans);
        
        return ans;
    }
    
private:
    unordered_set<int> s;
    
    void dfs(vector<int> &nums, vector<int> v, vector<vector<int>> &ans){
        if (v.size() == nums.size()){
            ans.push_back(v);
            v.clear();
            return;
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (s.find(i) != s.end()){
                continue;
            }
            
            s.insert(i);
            v.push_back(nums[i]);
            dfs(nums, v, ans);
            v.pop_back();
            s.erase(i);
        }
        
        return;
    }
};