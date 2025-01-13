/*
Problem: 3223. Minimum Length of String After Operations
Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/
*/


int minimumLength(char* s) {
    int map[26] = {0}, len = strlen(s), i, ans = 0;

    for (i = 0; i < len; i++) {
        map[s[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        map[i] = map[i] > 2 ? ((map[i] & 1) ? 1 : 2) : map[i];
        ans += map[i];
    }

    return ans;
}
