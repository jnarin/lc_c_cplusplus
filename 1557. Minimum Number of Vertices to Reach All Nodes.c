/*
Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
Problem: 1557. Minimum Number of Vertices to Reach All Nodes
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int map[n];
    memset(map, 0, sizeof(map));
    
    int *ans = calloc(n, sizeof(int));
    assert(ans);
    int idx = 0, i;
    
    for (i = 0; i < edgesSize; i++){
        map[edges[i][1]]++;
    }
    
    for (i = 0; i < n; i++){
        if (map[i] == 0){
            ans[idx++] = i;
        }
    }
    
    *returnSize = idx;
    return ans;

}
