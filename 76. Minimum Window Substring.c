/*
 * Link: https://leetcode.com/problems/minimum-window-substring/
 * Problem: 76. Minimum Window Substring
 * */

#define MAX_CHAR_NUM    (128)
char* minWindow(char* s, char* t) {
    char *nullString = "\0";
    int sLen = strlen(s), tLen = strlen(t);
    int validMapEntries = 0;

    if (tLen > sLen) {
        return nullString;
    }

    int map[MAX_CHAR_NUM];

    for (int i = 0; i < MAX_CHAR_NUM; i++) {
        map[i] = INT_MIN;
    }

    for (int i = 0; i < tLen; i++) {
        map[t[i]] = map[t[i]] == INT_MIN ? 1 : map[t[i]] + 1;
    }

    for (int i = 0; i < MAX_CHAR_NUM; i++) {
        validMapEntries = map[i] > 0 ? validMapEntries + 1 : validMapEntries;
    }

    int left = 0, right = 0, head = INT_MAX, len = INT_MAX;

    while (right < sLen) {
        if (map[s[right]] != INT_MIN) {
            map[s[right]]--;

            if (map[s[right]] == 0) {
                validMapEntries--;
            }
        }

        right++;

        while (validMapEntries == 0) {
            int diff = right - left;
            if (diff < len) {
                head = left;
                len = diff;
            }

            if (map[s[left]] != INT_MIN) {
                map[s[left]]++;

                if (map[s[left]] > 0) {
                    validMapEntries++;
                }
            }

            left++;
        }
    }

    if (len == INT_MAX) {
        return nullString;
    }

    char *ans = calloc(len + 1, sizeof(char));
    strncpy(ans, &s[head], len);

    return ans;
}

