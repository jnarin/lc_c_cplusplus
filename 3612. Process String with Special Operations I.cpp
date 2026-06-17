/*
Problem: 3612. Process String with Special Operations I
Link: https://leetcode.com/problems/process-string-with-special-operations-i/
*/

class Solution {
public:
    string processStr(string s) {
        string ans;

        for (auto& c : s) {
            if (c == '*') {
                if (ans.length()) ans.pop_back();
                continue;
            }

            if (c == '#') {
                if (ans.length()) ans += ans;
                continue;
            }

            if (c == '%') {
                if (ans.length()) reverse(ans.begin(), ans.end());
                continue;
            }

            ans += c;
        }
        
        return ans;
    }
};
