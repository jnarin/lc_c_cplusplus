/*
 * Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
 * Problem: 1624. Largest Substring Between Two Equal Characters
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maxLengthBetweenEqualCharacters(char* s) {
    int indexMap[26], i, len = strlen(s), ans = -1;

    for (i = 0; i < 26; i++){
        indexMap[i] = -1;
    }

    for (i = 0; i < len; i++) {
        if (indexMap[s[i] - 'a'] > -1) {
            ans = MAXVAL(ans, i - indexMap[s[i] - 'a'] - 1);
        } else {
            indexMap[s[i] - 'a'] = i;
        }
    }

    return ans;
}

