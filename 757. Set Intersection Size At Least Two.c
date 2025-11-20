/*
Problem: 757. Set Intersection Size At Least Two
Link: https://leetcode.com/problems/set-intersection-size-at-least-two/
*/

static int intervelCmp(const void *a, const void *b) {
    const int *intervalA = *(const int**)a, *intervalB = *(const int**)b;
    int endA = intervalA[1], endB = intervalB[1];

    if (endA != endB) {
        return endA - endB;
    }

    return intervalB[0] - intervalA[0];
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    int ans = 0, mx = -1, secondMax = -1, i;

    qsort(intervals, intervalsSize, sizeof(int*), intervelCmp);

    for (i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0], end = intervals[i][1];
        
        if (mx >= start && secondMax >= start){
            continue;
        }

        if (mx >= start) {
            secondMax = mx;
            mx = end;
            ans += 1;
        } else {
            mx = end;
            secondMax = end - 1;
            ans += 2;
        }
    }

    return ans;
}
