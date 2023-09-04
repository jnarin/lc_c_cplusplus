/*
Link: https://leetcode.com/problems/extra-characters-in-a-string/
Problem: 2707. Extra Characters in a String
*/
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dictSet;
        int i, j;
        
        for (auto &it : dictionary){
            dictSet.insert(it);
        }
        
        vector<int> dp(s.length() + 1, s.length());
        dp[0] = 0;
        
        for (i = 1; i <= s.length(); i++){
            for (j = 0; j < i; j++){
                if (dictSet.find(s.substr(j, i - j)) != dictSet.end()){
                    dp[i] = min(dp[i], dp[j]);
                } else {
                    dp[i] = min(dp[i], dp[j] + i - j);
                }
            }
        }
        
        return dp[s.length()];
        
    }
};