/*
 * Link: https://leetcode.com/problems/remove-outermost-parentheses/
 * Problem: https://leetcode.com/problems/remove-outermost-parentheses/
 * */

char * removeOuterParentheses(char * s){
    int i, open = 0, len = strlen(s), idx = 0;
    char *ans = calloc(len, sizeof(char));

    for (i = 0; i < len; i++){
        if (s[i] == '('){
            open++;
            if (open > 1){
                ans[idx++] = s[i];
            }
        } else {
            open--;
            if (open > 0){
                ans[idx++] = s[i];
            }
        }
    }

    return ans;
}
