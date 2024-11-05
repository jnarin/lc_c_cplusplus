/*
Problem: 2914. Minimum Number of Changes to Make Binary String Beautiful
Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
*/

int minChanges(char* s) {
    int ans = 0, len = strlen(s), i;
    
    for (i = 0; i + 1 < len; i += 2) {
        ans += s[i] == s[i + 1] ? 0 : 1;
    }
    
    return ans;
}
