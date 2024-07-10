/*
Problem: 1598. Crawler Log Folder
Link: https://leetcode.com/problems/crawler-log-folder/
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        
        for (string& path : logs) {
            if (path == "./") {
                continue;
            }
            
            if (path == "../") {
                if (s.size()) {
                    s.pop();
                }
                continue;
            }
            
            s.push(path);            
        }
        
        return s.size();
    }
};
