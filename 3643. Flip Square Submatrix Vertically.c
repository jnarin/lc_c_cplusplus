/*
Problem: 3643. Flip Square Submatrix Vertically
Link: https://leetcode.com/problems/flip-square-submatrix-vertically
*/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    int **result = calloc(gridSize, sizeof(int *));
    *returnColumnSizes = calloc(gridSize, sizeof(int));
    
    for (int i = 0; i < gridSize; i++) {
        result[i] = calloc(gridColSize[i], sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i];

        memcpy(result[i], grid[i], gridColSize[i] * sizeof(int));
    }

    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k; j++) {
            int temp = result[x + i][y + j];
            result[x + i][y + j] = result[x + k - 1 - i][y + j];
            result[x + k - 1 - i][y + j] = temp;
        }
    }
    
    *returnSize = gridSize;
    return result;
}
