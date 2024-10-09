/*
Problem: 2696. Minimum String Length After Removing Substrings
Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
*/

int minLength(char * s){
    int i, sLen = strlen(s), idx = 0;
    char stack[sLen + 1];
    memset(stack, 0, sizeof(stack));
        
    for (i = 0; i < sLen; i++) {
        if (s[i] == 'B' && (idx > 0 && stack[idx - 1] == 'A')) {
            idx--;
            continue;
        }
        
        if (s[i] == 'D' && (idx > 0 && stack[idx - 1] == 'C')) {
            idx--;
            continue;
        }
        
        stack[idx++] = s[i];
    }
    
    return idx;
}
