/*
 * Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
 * Problem: 1347. Minimum Number of Steps to Make Two Strings Anagram
 * */

#define MAX_ALPHA           (26)
#define CHAR_TO_IDX(a)      (a - 'a')

int minSteps(char* s, char* t) {
    int mapS[MAX_ALPHA] = {0}, mapT[MAX_ALPHA] = {0}, i;
    int lenS = strlen(s), lenT = strlen(t);
    int ans = 0;

    for (i = 0; i < lenS; i++) {
        mapS[CHAR_TO_IDX(s[i])]++;
    }

    for (i = 0; i < lenT; i++) {
        mapT[CHAR_TO_IDX(t[i])]++;
    }

    for (i = 0; i < MAX_ALPHA; i++) {
        if (mapS[i] == mapT[i]) {
            continue;
        }

        if (mapT[i] < mapS[i]) {
            ans += mapS[i] - mapT[i];
        }
    }

    return ans;
}

