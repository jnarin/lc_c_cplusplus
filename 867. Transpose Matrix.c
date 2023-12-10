/*
 * Link: https://leetcode.com/problems/transpose-matrix/
 * Problem: 867. Transpose Matrix
 * */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define DEBUG   0
#define  debug_printf(fmt, ...) \
            do { if (DEBUG) printf(fmt, __VA_ARGS__); } while (0)

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int **ans;
    int i, j;

    // Original Matrix:
    // R = matrixSize, C = matrixColSize[0]
    // Transposed Matrix:
    // R' = matrixColSize[0], C' = matrixSize;

    ans = calloc(matrixColSize[0], sizeof(int *));
    *returnSize = matrixColSize[0];
    *returnColumnSizes = calloc(matrixColSize[0], sizeof(int));

    for (i = 0; i < matrixColSize[0]; i++){
        ans[i] = calloc(matrixSize, sizeof(int));
        (*returnColumnSizes)[i] = matrixSize;
    }

    for (i = 0; i < matrixSize; i++){
        for (j = 0; j < matrixColSize[0]; j++){
            ans[j][i] = matrix[i][j];
        }
    }

    return ans;
}

