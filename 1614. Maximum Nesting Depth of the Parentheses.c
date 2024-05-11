/*
 * Problem: 1614. Maximum Nesting Depth of the Parentheses
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxDepth(char* s) {
    int count = 0, i, len = strlen(s), ans = 0;

    for (i = 0; i < len; i++) {
        if (s[i] == ')') {
            count--;
            continue;
        }

        if (s[i] == '(') {
            count++;
            ans = MAXVAL(ans, count);
        }
    }

    return ans;
}
