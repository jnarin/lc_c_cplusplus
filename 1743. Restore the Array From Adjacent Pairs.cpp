/*
Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
Problem: 1743. Restore the Array From Adjacent Pairs
*/

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> m;
        vector<int> ans;
        int a, b, n;
        
        for (auto &it : adjacentPairs){
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }
        
        // The first and last element in the array will have
        // adjacency of 1. So we have the first two elements
        for (auto &it : m){
            if (it.second.size() == 1){
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }
        
        n = (adjacentPairs.size() + 1);
        while (ans.size() < n){
            a = ans[ans.size() - 1];
            b = ans[ans.size() - 2];
            
            if (m[a][0] == b){
                ans.push_back(m[a][1]);
            } else {
                ans.push_back(m[a][0]);
            }
        }
        
        return ans;
    }
};