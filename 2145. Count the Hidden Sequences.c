/*
Problem: 2145. Count the Hidden Sequences
Link: https://leetcode.com/problems/count-the-hidden-sequences/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int numberOfArrays(int* differences, int differencesSize, int lower, int upper) {
    long long s, max, min;
    int i;

    s = max = min = 0;

    for (i = 0; i < differencesSize; i++) {
        s += differences[i];
        max = MAXVAL(s, max);
        min = MINVAL(s, min);
    }

    return MAXVAL(upper - lower - (max - min) + 1, 0);
}
