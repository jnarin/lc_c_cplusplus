/*
Problem: 3210. Find the Encrypted String
Link: https://leetcode.com/problems/find-the-encrypted-string/
*/

char* getEncryptedString(char* s, int k) {
    int len = strlen(s), i;
    char *ans = calloc(len + 1, sizeof(char));
    
    for (i = 0; i < len; i++) {
        ans[i] = s[(i + k) % len];
    }
    
    return ans;
}