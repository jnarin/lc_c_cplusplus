/*
Problem: 3174. Clear Digits
Link: https://leetcode.com/problems/clear-digits/
*/

char* clearDigits(char* s) {
    int len = strlen(s), i = 0;
    char *ans = calloc(len + 1, sizeof(char)), idx = 0;
    
    while (i < len) {
        if (s[i] >= '0' && s[i] <= '9' && idx) {
            i++;
            idx--;
            continue;
        }
        
        ans[idx++] = s[i++];
    }
    
    ans[idx] = '\0';
    
    return ans;
    
}