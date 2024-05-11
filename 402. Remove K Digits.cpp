/*
 * Problem: 402. Remove K Digits
 * Link: https://leetcode.com/problems/remove-k-digits/
 * */

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> s;

        for (auto &c : num){
            while (s.size() && k > 0 && s.top() > c){
                s.pop();
                k--;
            }

            if (s.size() || c != '0'){
                s.push(c);
            }
        }

        while (s.size() && k--){
            s.pop();
        }

        if (s.size() == 0){
            return "0";
        }

        while (s.size()){
            num[n - 1] = s.top();
            s.pop();
            n--;
        }

        return num.substr(n);

    }
};
