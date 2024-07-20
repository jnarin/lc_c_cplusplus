/*
Problem: 1190. Reverse Substrings Between Each Pair of Parentheses
Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        int t;
        
        for (char &c : s) {
            switch(c) {
                case '(':
                    st.push(ans.length());
                    break;
                    
                case ')':
                    t = st.top();
                    st.pop();

                    reverse(ans.begin() + t, ans.end());
                    
                    break;

                default:
                    ans += c;

            }
        }
        
        return ans;
    }
};
