/*
Link: https://leetcode.com/problems/longest-string-chain/
Problem: 1048. Longest String Chain
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {

        unordered_map<string, int> m;
        int ans = 0, i;
        
        sort(words.begin(), words.end(),
            [](string &a, string &b){
                return a.length() < b.length()
                    ? true : false;
            });
        for (auto &word : words){
            m.insert({word, 1});
            
            for (i = 0; i < word.length(); i++){
                string t = word;
                t.erase(t.begin() + i);
                
                if (m.find(t) != m.end()){
                    m[word] = max(m[word], m[t] + 1);
                }
            }
            
            ans = max(ans, m[word]);
        }
        
        return ans;
    }
};