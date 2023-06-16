/*
 * Link: https://leetcode.com/problems/shifting-letters/
 * Problem: 848. Shifting Letters
 * */

char * shiftingLetters(char * s, int* shifts, int shiftsSize){
    int i, t;

    shifts[shiftsSize - 1] %= 26;

    for (i = shiftsSize - 2; i >= 0; i--){
        shifts[i] %= 26;
        shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }

    for (i = 0; i < shiftsSize; i++){
        t = s[i] - 'a';
        t = ((t + shifts[i]) % 26) + 'a';
        s[i] = t;
    }

    return s;
}
