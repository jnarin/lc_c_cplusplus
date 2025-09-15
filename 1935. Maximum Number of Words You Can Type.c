/*
Problem: 1935. Maximum Number of Words You Can Type
Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
*/

int canBeTypedWords(char* text, char* brokenLetters) {
    char broken[26] = {0};
    int i, canType = 1, ans = 0;

    for (i = 0; brokenLetters[i]; i++) {
        broken[brokenLetters[i] - 'a'] = 1;
    }

    for (i = 0; ; i++) {
        if (text[i] == ' ' || text[i] == '\0') {
            if (canType) {
                ans++;
            }

            canType = 1;

            if (text[i] == '\0') {
                break;
            }
        } else {
            if (broken[text[i] - 'a']) {
                canType = 0;
            }
        }
    }

    return ans;
}
