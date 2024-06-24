/*
Problem: 140. Word Break II
Link: https://leetcode.com/problems/word-break-ii/
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        
        return dfs(s, wordSet, memo);
    }

private:
    vector<string> dfs(const string &s, unordered_set<string> &wordSet, unordered_map<string, vector<string>> &memo) {
        if (memo.count(s)) {
            return memo[s];
        }
        
        if (s.empty()) {
            return {""};
        }
        
        vector<string> ans;
        
        for (int i = 1; i <= s.length(); i++) {
            string word = s.substr(0, i);
            if (wordSet.count(word)) {
                for (const string &n : dfs(s.substr(i), wordSet, memo)) {
                    ans.push_back(word + (n.empty() ? "" : " ") + n);
                }
            }
        }
        
        memo[s] = ans;
        
        return ans;
    }
};