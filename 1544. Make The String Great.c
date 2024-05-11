/*
 * Problem: 1544. Make The String Great
 * Link: https://leetcode.com/problems/make-the-string-great/
 * */

char * makeGood(char * s){
    int len = strlen(s), i = 0, st = 0;
    char *stack, t;

    stack = calloc(len + 1, sizeof(char));

    stack[st] = s[i];
    i++;

    for (; i < len; i++){
        if (st >= 0){
            t = stack[st];
            if (t - 'a' + 'A' == s[i] || t - 'A' + 'a' == s[i]){
                stack[st] = 0;
                st--;
                continue;
            }
        }
        st++;
        stack[st] = s[i];
    }

    return stack;
}
