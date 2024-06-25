/*
Problem: 409. Longest Palindrome
Link: https://leetcode.com/problems/longest-palindrome/
*/

int longestPalindrome(char* s) {
    int map[256] = {0}, i, len = strlen(s);
    
    for (i = 0; i < len; i++) {
        map[s[i]] += 1;
    }
    
    int ans = 0;
    
    for (i = 0; i < 256; i++) {
        if (map[i]) {
            ans += (map[i] & 1) ? map[i] - 1 : map[i];
        }
    }
    
    for (i = 0; i < 256; i++) {
        if (map[i] & 1) {
            ans += 1;
            break;
        }
    }
    
    return ans;
}