/*
Problem: 3863. Minimum Operations to Sort a String
Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
*/

struct MinMax {
    char min, max;
};

static void getMinMax(char *s, int len, struct MinMax *m) {
    int i;
    m->min = CHAR_MAX;
    m->max = CHAR_MIN;

    for (i = 0; i < len; i++) {
        m->min = s[i] < m->min ? s[i] : m->min;
        m->max = s[i] > m->max ? s[i] : m->max;
    }

    return;
}

int minOperations(char* s) {
    int len = strlen(s), i;
    bool sorted = true;

    for (i = 1; i < len; i++) {
        if (s[i] < s[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted == true) {
        return 0;
    }

    if (len == 2) {
        return -1;
    }

    struct MinMax m;
    getMinMax(s, len, &m);

    if (s[0] == m.min || s[len - 1] == m.max) {
        return 1;
    }

    for (i = 1; i < len - 1; i++) {
        if (s[i] == m.min || s[i] == m.max) {
            return 2;
        }
    }

    return 3;
}
