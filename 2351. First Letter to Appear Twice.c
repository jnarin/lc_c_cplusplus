/*
 * Link: https://leetcode.com/problems/first-letter-to-appear-twice/
 * Problem: 2351. First Letter to Appear Twice
 * */

char repeatedCharacter(char* s) {
    int map[26] = {0}, i, len = strlen(s);

    for (i = 0; i < len; i++) {
        map[s[i] - 'a']++;

        if (map[s[i] - 'a'] == 2) {
            return s[i];
        }
    }

    return 0;
}
