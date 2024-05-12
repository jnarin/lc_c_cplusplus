/*
 * Problem: 3075. Maximize Happiness of Selected Children
 * Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/
 * */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long ans = 0;
    int i, dec = 0;

    qsort(happiness, happinessSize, sizeof(int), decrCmp);

    for (i = 0; i < k; i++) {
        ans += MAXVAL(0, happiness[i] - dec);
        dec++;
    }

    return ans;
}
