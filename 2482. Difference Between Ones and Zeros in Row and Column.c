/*
Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
Problem: 2482. Difference Between Ones and Zeros in Row and Column
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int rows[gridSize], cols[gridColSize[0]];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    
    int i, j;
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++){
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }
    
    
    int **ans;
    ans = calloc(gridSize, sizeof(int *));
    *returnSize = gridSize;
    *returnColumnSizes = calloc(gridSize, sizeof(int));
    
    for (i = 0; i < gridSize; i++){
        ans[i] = calloc(gridColSize[0], sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[0];
    }
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++){
            ans[i][j] = (2 * rows[i]) + (2 * cols[j]) - gridSize - gridColSize[0];
        }
    }
    
    return ans;
}

