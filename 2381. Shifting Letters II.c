/*
Problem: 2381. Shifting Letters II
Link: https://leetcode.com/problems/shifting-letters-ii/description
*/

char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int c = 0, len = strlen(s), t[len + 1], i, d;
    char n;

    memset(t, 0, sizeof(t));

    for (i = 0; i < shiftsSize; i++) {
        d = shifts[i][2] == 0 ? -1 : 1;
        t[shifts[i][0]] += d;
        t[shifts[i][1] + 1] -= d;
    }

    for (i = 0; i < len; i++) {
        c = (c + t[i]) % 26;
        n = (s[i] - 'a' + c + 26) % 26;
        s[i] = n + 'a';
    }

    return s;
}
