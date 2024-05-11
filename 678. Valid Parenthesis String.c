/*
 * Problem: 678. Valid Parenthesis String
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 * */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

bool checkValidString(char* s) {
    int low, high, i, len = strlen(s);
    char c;

    low = high = 0;

    for (i = 0; i < len; i++) {
        c = s[i];

        switch(c) {
            case '(':
                low++;
                high++;
                break;
            case ')':
                low--;
                low = MAXVAL(0, low);
                high--;
                break;
            case '*':
                low--;
                low = MAXVAL(0, low);
                high++;
                break;
        }
        if (high < 0) {
            return false;
        }
    }

    return low == 0;
}
