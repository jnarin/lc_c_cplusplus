/*
Problem: 3531. Count Covered Buildings
Link: https://leetcode.com/problems/count-covered-buildings/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    int northernMost[n + 1], southernMost[n + 1], westernMost[n + 1], easternMost[n + 1], 
        i, ans = 0;

    for (i = 0; i < n + 1; i++) {
        northernMost[i] = westernMost[i] = INT_MAX;
        southernMost[i] = easternMost[i] = 0;
    }

    for (i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0], y = buildings[i][1];
        northernMost[x] = MINVAL(northernMost[x], y);
        southernMost[x] = MAXVAL(southernMost[x], y);
        westernMost[y] = MINVAL(westernMost[y], x);
        easternMost[y] = MAXVAL(easternMost[y], x);
    }

    for (i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0], y = buildings[i][1];
        ans += (northernMost[x] < y && y < southernMost[x] && westernMost[y] < x && x < easternMost[y]);
    }

    return ans;
}
