/*
Problem: 696. Count Binary Substrings
Link: https://leetcode.com/problems/count-binary-substrings
*/
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b));

int countBinarySubstrings(char* s) {
    int sLen = strlen(s), l = 0, r, ans = 0, previous = 0, current;

    while (l < sLen) {
        r = l + 1;

        while (r < sLen && s[l] == s[r]) {
            r++;
        }

        current = r - l;
        ans += MINVAL(previous, current);
        previous = current;

        l = r;
    }

    return ans; 
}
