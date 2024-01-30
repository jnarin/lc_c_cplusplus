/*
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
Problem: 150. Evaluate Reverse Polish Notation
*/

#define MAX_NUMS    (10001)

int evalRPN(char** tokens, int tokensSize) {
    long nums[MAX_NUMS] = {0}, a, b;
    int i, idx = 0;
    char *c;
    
    for (i = 0; i < tokensSize; i++) {
        c = tokens[i];

        if (c[0] == '+' && c[1] == '\0') {
            a = nums[--idx];
            b = nums[--idx];
            nums[idx++]  = a + b;
        } else if (c[0] == '-' && c[1] == '\0') {
            a = nums[--idx];
            b = nums[--idx];
            nums[idx++]  = b - a;
        } else if (c[0] == '*') {
            a = nums[--idx];
            b = nums[--idx];
            nums[idx++]  = a * b;
        } else if (c[0] == '/') {
            a = nums[--idx];
            b = nums[--idx];
            nums[idx++]  = b / a;
        } else {
            nums[idx++] = atoi(c);
        }
    }
    
    return (int)nums[idx - 1];
    
}