/*
 * Link: https://leetcode.com/problems/painting-the-walls/
 * Problem: 2742. Painting the Walls
 * */

#define MINVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

#define MAXVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int paintWalls(int* cost, int costSize, int* time, int timeSize){
    int i, walls;
    unsigned long dp[costSize + 1];

    dp[0] = 0;
    for (i = 1; i + 1 < costSize; i++){
        dp[i] = (int)INT_MAX;
    }

    for (i = 0; i < costSize; i++){
        for (walls = costSize; walls > 0; walls--){
            dp[walls] = MINVAL(dp[walls], dp[MAXVAL(walls - time[i] - 1, 0)] + cost[i]);
        }
    }

    return (int)dp[costSize];
}
