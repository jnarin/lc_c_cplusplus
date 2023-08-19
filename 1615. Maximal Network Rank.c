/*
 * Link: https://leetcode.com/problems/maximal-network-rank/
 * Problem: 1615. Maximal Network Rank
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize){
    int inDegree[n];
    bool connected[n][n];
    int i, j, ans = 0;

    memset(inDegree, 0, sizeof(inDegree));
    memset(connected, 0, sizeof(connected));

    for (i = 0; i < roadsSize; i++){
        inDegree[roads[i][0]]++;
        inDegree[roads[i][1]]++;
        connected[roads[i][0]][roads[i][1]] = true;
        connected[roads[i][1]][roads[i][0]] = true;
    }

    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            ans = MAXVAL(ans, inDegree[i] + inDegree[j] - (connected[i][j] == true ? 1 : 0));
        }
    }

    return ans;
}

