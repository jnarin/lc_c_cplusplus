/*
Problem: 884. Uncommon Words from Two Sentences
Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        string t;
        
        for (auto& it : s1) {
            if (it == ' ') {
                m[t]++;
                t = "";
                continue;
            }
            
            t += it;
        }
        
        m[t]++;
        t = "";
        
        for (auto& it : s2) {
            if (it == ' ') {
                m[t]++;
                t = "";
                continue;
            }
            
            t += it;
        }
        
        m[t]++;
        t = "";

        vector<string> ans;
        
        for (auto& it : m) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
