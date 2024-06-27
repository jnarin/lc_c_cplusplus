/*
Problem: 1791. Find Center of Star Graph
Link: https://leetcode.com/problems/find-center-of-star-graph/
*/

#define MAX_N   ((int)(1e5 + 1))

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int map[MAX_N], i, ans = 0, e = 0;
    
    memset(map, 0, sizeof(map));
    
    for (i = 0; i < edgesSize; i++) {
        map[edges[i][0]]++;
        map[edges[i][1]]++;
    }
    
    for (i = 0; i < MAX_N; i++) {
        if (map[i] > e) {
            e = map[i];
            ans = i;
        }
    }
    
    return ans;
}