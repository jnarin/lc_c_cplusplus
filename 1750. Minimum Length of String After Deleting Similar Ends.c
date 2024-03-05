/*
Link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
Problem: 1750. Minimum Length of String After Deleting Similar Ends
*/
int minimumLength(char* s) {
    int l = 0, r = strlen(s) - 1;
    char c;
    
    while (l < r && s[l] == s[r]) {
        c = s[l];
        
        while (l <= r && c == s[l]) {
            l++;
        }
        
        while (l <= r && c == s[r]) {
            r--;
        }
    }
    
    return r - l + 1;
}