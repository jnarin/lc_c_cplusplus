/*
Problem: 2594. Minimum Time to Repair Cars
Link: https://leetcode.com/problems/minimum-time-to-repair-cars/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static long long minVal(int *array, int arraySize) {
    long long ans = INT_MAX;
    int i;

    for (i = 0; i < arraySize; i++) {
        ans = MINVAL(ans, array[i]);
    }

    return ans;
}

static long long numCarsFixed(int *ranks, int ranksSize, long long m) {
    long long c = 0;
    int i;

    for (i = 0; i < ranksSize; i++) {
        c += sqrt(m / ranks[i]);
    }

    return c;
}

long long repairCars(int* ranks, int ranksSize, int cars) {
    long long l = 0, r = minVal(ranks, ranksSize) * cars * cars, m;

    while (l < r) {
        m = (l + r) / 2;

        if (numCarsFixed(ranks, ranksSize, m) >= cars) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    return l;
}
