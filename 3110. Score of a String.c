/*
Problem: 3110. Score of a String
Link: https://leetcode.com/problems/score-of-a-string/
*/

int scoreOfString(char* s) {
    int ans = 0, i, len = strlen(s);
    
    for (i = 1; i < len; i++) {
        ans += abs(s[i - 1] - s[i]);
    }
    
    return ans;
}