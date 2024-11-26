/*
Problem: 2924. Find Champion II
Link: https://leetcode.com/problems/find-champion-ii/
*/

int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    int inDegree[n];
    memset(inDegree, 0, sizeof(inDegree));
    
    int i, ans = -1;
    
    for (i = 0; i < edgesSize; i++) {
        inDegree[edges[i][1]]++;
    }
    
    for (i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            if (ans != -1) {
                return -1;
            }
            
            ans = i;
        }
    }
    
    return ans;
}
