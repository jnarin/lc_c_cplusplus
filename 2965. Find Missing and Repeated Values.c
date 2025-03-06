/*
Problem: 2965. Find Missing and Repeated Values
Link: https://leetcode.com/problems/find-missing-and-repeated-values/
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int *ans = calloc(2, sizeof(int)), maxNum = gridSize * *gridColSize;
    int map[maxNum + 1], i, j;
    *returnSize = 2;

    memset(map, 0, sizeof(map));

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            map[grid[i][j]]++;
            if (map[grid[i][j]] == 2) {
                ans[0] = grid[i][j];
            }
        }
    }
    
    for (i = 1; i <= maxNum; i++) {
        if (map[i] == 0) {
            ans[1] = i;
            break;
        }
    }

    return ans;    
}
