/*
Problem: 1593. Split a String Into the Max Number of Unique Substrings
Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
*/

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return dfs(s, seen);
    }

private:
    int dfs(string s, unordered_set<string>& seen) {
        if (s.empty()) {
            return 0;
        }

        int res = 0;
        
        for (int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if (seen.count(sub) == 0) {
                seen.insert(sub);
                res = max(res, 1 + dfs(s.substr(i), seen));
                seen.erase(sub);
            }
        }

        return res;
    }
};
