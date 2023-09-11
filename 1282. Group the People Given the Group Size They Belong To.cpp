/*
Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
Problem: 1282. Group the People Given the Group Size They Belong To
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m; // group size, vector of indices
        
        for (int i = 0; i < groupSizes.size(); i++){
            m[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        for (auto &[s, v] : m){
            assert(v.size() % s == 0);
            
            vector<int> t;
            
            for (int i = 0; i < v.size(); i++){
                if (i && (i % s) == 0){
                    ans.push_back(t);
                    t.clear();
                }
                
                t.push_back(v[i]);
            }
            
            ans.push_back(t);
        }
        
        return ans;
        
    }
};