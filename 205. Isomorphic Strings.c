/*
 * Problem: 205. Isomorphic Strings
 * Link: https://leetcode.com/problems/isomorphic-strings/
 * */

#define MAX_CHAR_NUM    (256)
static bool checkMap(char *s, char *t, int len) {
    int map[MAX_CHAR_NUM] = {0}, i;

    for (i = 0; i < len; i++) {
        char c = s[i];
        if (map[c] == 0) {
            map[c] = t[i];
        } else {
            if (map[c] != t[i]) {
                return false;
            }
        }
    }

    return true;
}

bool isIsomorphic(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);

    if (sLen != tLen) {
        return false;
    }

    return checkMap(s, t, sLen) && checkMap(t, s, sLen);
}

