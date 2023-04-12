/*
Link: https://leetcode.com/problems/simplify-path/
Problem: 71. Simplify Path
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string e = "", t = path + "/";
        
        
        for (auto &c : t){
            if (c == '/'){
                if (e == ".."){
                    if (s.size()){
                        s.pop();
                    }
                } else if (e.length() && e != "."){
                    s.push(e);
                }
                e = "";
            } else {
                e += c;
            }
        }
        
        vector<string> v;
        while (s.size()){
            v.push_back(s.top());
            s.pop();
        }
        
        reverse(v.begin(), v.end());
        
        string ans = v.size() ? "" : "/";
        
        for (auto &it : v){
            ans += "/" + it;
        }
        
        return ans;
    }
};