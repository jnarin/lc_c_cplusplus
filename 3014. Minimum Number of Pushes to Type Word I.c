/*
Problem: 3014. Minimum Number of Pushes to Type Word I
Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
*/
static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumPushes(char* word) {
    int ans = 0, freqCount[26] = {0}, i;
    char *t = word;

    while (*t) {
        freqCount[*t - 'a']++;
        t++;
    }

    qsort(freqCount, 26, sizeof(int), decrCmp);

    for (i = 0; i < 26; i++) {
        ans += freqCount[i] * (i / 8 + 1);
    }
    
    return ans;
}
