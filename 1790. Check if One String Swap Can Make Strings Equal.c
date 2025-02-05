/*
Problem: 1790. Check if One String Swap Can Make Strings Equal
Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
*/

bool areAlmostEqual(char* s1, char* s2) {
    if (strcmp(s1, s2) == 0) {
        return true;
    }

    int s1Map[26] = {0}, s2Map[26] = {0}, i, len = strlen(s1);

    for (i = 0; i < len; i++) {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;   
    }

    if (memcmp(s1Map, s2Map, sizeof(s1Map)) != 0) {
        return false;
    }

    int c = 0;
    for (i = 0; i < len; i++) {
        c += s1[i] != s2[i];
        if (c > 2) {
            return false;
        }
    }

    return c == 2;
}
