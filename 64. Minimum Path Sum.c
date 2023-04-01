/*
Link: https://leetcode.com/problems/minimum-path-sum/
Problem: 64. Minimum Path Sum
*/

#define MIN_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    a < b ? a : b;  })

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i, j;
    
    for (i = 0; i < gridSize; i++){
        for (j = 0; j < gridColSize[i]; j++){
            if (i > 0 && j > 0){
                grid[i][j] += MIN_VAL(grid[i - 1][j], grid[i][j - 1]);
                continue;
            }
            
            if (i > 0){
                grid[i][j] += grid[i - 1][0];
                continue;
            }
            
            if (j > 0){
                grid[i][j] += grid[0][j - 1];
                continue;
            }
        }
    }
    
    return grid[gridSize - 1][gridColSize[0] - 1];
}