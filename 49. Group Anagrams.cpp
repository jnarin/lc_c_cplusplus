/*
Link: https://leetcode.com/problems/group-anagrams/
Problem: 49. Group Anagrams
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;

       
        for (string s : strs){
            string sorted_string = s;
            sort(sorted_string.begin(), sorted_string.end());

            m[sorted_string].push_back(s);
        }

        for (auto& it : m){
            ans.push_back(it.second);
        }

        return ans;
    }
};