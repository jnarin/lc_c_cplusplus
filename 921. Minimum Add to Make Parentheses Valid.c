/*
Problem: 921. Minimum Add to Make Parentheses Valid
Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/

int minAddToMakeValid(char* s) {
    int sLen = strlen(s), i, idx = 0;
    char stack[sLen + 1];
    memset(stack, 0, sizeof(stack));
    
    for (i = 0; i < sLen; i++) {
        if (s[i] == ')' && (idx > 0 && stack[idx - 1] =='(')) {
            idx--;
        } else {
            stack[idx++] = s[i];
        }
    }
    
    return idx;
}
