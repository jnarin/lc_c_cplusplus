/*
 * Link: https://leetcode.com/problems/first-unique-character-in-a-string/
 * Problem: 387. First Unique Character in a String
 * */

int firstUniqChar(char* s) {
    int map[26] = {0}, i, len = strlen(s);

    for (i = 0; i < len; i++) {
        map[s[i] - 'a']++;
    }

    for (i = 0; i < len; i++) {
        if (map[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
