/*
Problem: 131. Palindrome Partitioning
Link: https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        backTrack(0, s, t, ans);
        return ans;
    }

private:
    void backTrack(int idx, string& s, vector<string>& t, vector<vector<string>>& ans){
        if (s.length() == idx){
            ans.push_back(t);
            return;
        }

        for (int i = idx; i < s.length(); i++){
            if (isPalindrome(s, idx, i)){
                t.push_back(s.substr(idx, i - idx + 1));
                backTrack(i + 1, s, t, ans);
                t.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r){
        while (l <= r){
            if (s[l++] != s[r--]){
                return false;
            }
        }

        return true;
    }
};