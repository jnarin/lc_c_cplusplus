/*
Problem: 539. Minimum Time Difference
Link: https://leetcode.com/problems/minimum-time-difference/
*/

#define MAX_TIME_VAL    (24 * 60)
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int findMinDifference(char** timePoints, int timePointsSize) {
    int ans = MAX_TIME_VAL, first = MAX_TIME_VAL, last = -1, i, time, prev;
    bool isTimeExist[MAX_TIME_VAL] = {0};
    char *p;
    int h, m, t;
    
    for (i = 0; i < timePointsSize; i++) {
        p = timePoints[i];
        sscanf(p, "%2d:%2d", &h, &m);
        t = (h * 60) + m;
        
        first = MINVAL(first, t);
        if (isTimeExist[t] == true) {
            return 0;
        }
        
        isTimeExist[t] = true;
        last = MAXVAL(last, t);
    }
    
    prev = first;
    for (i = first + 1; i <= last; i++) {
        if (isTimeExist[i]) {
            ans = MINVAL(ans, i - prev);
            prev = i;
        }
    }
    
    return MINVAL(ans, 24 * 60 - prev + first);
}
