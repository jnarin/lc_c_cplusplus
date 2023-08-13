/*
 * Link: https://leetcode.com/problems/word-break/
 * Problem: 139. Word Break
 * */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, {wordDict.begin(), wordDict.end()}, {});
    }
    
private:
    bool solve(string s, unordered_set<string> &&wordSet, unordered_map<string, bool> &&dp){
        if(wordSet.find(s) != wordSet.end()){
            return true;
        }
        
        if (dp.find(s) != dp.end()){
            return dp[s];
        }
        
        for (int i = 1; i < s.length(); i++){
            const string &pre = s.substr(0, i), &suf = s.substr(i);
            
            if (wordSet.find(pre) != wordSet.end() && solve(suf, move(wordSet), move(dp))){
                return true;
            }
        }
        
        dp[s] = false;
        
        return dp[s];
    }
};
