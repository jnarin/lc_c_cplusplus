/*
Problem: 2315. Count Asterisks
Link: https://leetcode.com/problems/count-asterisks/
*/

int countAsterisks(char* s) {
    int len = strlen(s), i, ans = 0;
    char skip = 0;
    
    for (i = 0; i < len; i++) {
        if (s[i] == '|') {
            skip ^= 1;
        }
        
        if (skip == 0 && s[i] == '*') {
            ans++;
        }
    }
    
    return ans;
}
