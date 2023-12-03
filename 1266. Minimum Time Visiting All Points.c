/*
 * Link: https://leetcode.com/problems/minimum-time-visiting-all-points/
 * Problem: 1266. Minimum Time Visiting All Points
 * */

#define MAXVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0, i;

    for (i = 1; i < pointsSize; i++){
        ans += MAXVAL(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i -1][1]));
    }

    return ans;
}


