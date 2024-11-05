/*
Problem: 2914. Minimum Number of Changes to Make Binary String Beautiful
Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
*/

int minChanges(char* s) {
    int ans = 0;
    
    while (*s && *(s + 1)) {
        ans += *s == *(s + 1) ? 0 : 1;
        s += 2;
    }
    
    return ans;
}
