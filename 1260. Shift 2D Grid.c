/*
Problem: 1260. Shift 2D Grid
Link: https://leetcode.com/problems/shift-2d-grid/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int **ans = calloc(gridSize, sizeof(int*));
    *returnColumnSizes = calloc(gridSize, sizeof(int));

    for (int i = 0; i < gridSize; i++) {
        ans[i] = calloc(gridColSize[i], sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i];
    }

    int totalElements = gridSize * gridColSize[0];
    k = k % totalElements; // Normalize k to avoid unnecessary full rotations

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int newIndex = (i * gridColSize[i] + j + k) % totalElements;
            int newRow = newIndex / gridColSize[i];
            int newCol = newIndex % gridColSize[i];
            ans[newRow][newCol] = grid[i][j];
        }
    }

    *returnSize = gridSize;
    return ans;
}
