/*
 * Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
 * Problem: 1758. Minimum Changes To Make Alternating Binary String
 * */

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

int minOperations(char* s) {
    int len = strlen(s), i, x, y;

    x = y = 0;

    for (i = 0; i < len; i++){
        if (s[i] - '0' == (i & 1)){
            x++;
        }
    }

    y = len - x;

    return MINVAL(x, y);
}
