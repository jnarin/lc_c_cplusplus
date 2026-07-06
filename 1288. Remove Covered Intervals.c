/*
Problem: 1288. Remove Covered Intervals
Link: https://leetcode.com/problems/remove-covered-intervals/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int incrCmp(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] - intervalB[0];
    } else {
        return intervalB[1] - intervalA[1];
    }
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), incrCmp);
    int ans = 0, i, maxLeft = INT_MIN, maxRight = INT_MIN;

    for (i = 0; i < intervalsSize; i++) {
        if (intervals[i][0] > maxLeft && intervals[i][1] > maxRight) {
            ans++;
            maxLeft = intervals[i][0];
        }

        maxRight = MAXVAL(maxRight, intervals[i][1]);
    }
    
    return ans;    
}
