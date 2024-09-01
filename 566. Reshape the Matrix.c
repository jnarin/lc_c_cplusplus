/*
Problem: 566. Reshape the Matrix
Link: https://leetcode.com/problems/reshape-the-matrix/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = *matColSize;

    if (m * n != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int **ans = calloc(r, sizeof(int *)), i;
    *returnColumnSizes = calloc(r, sizeof(int));

    for (i = 0; i < r; i++) {
        ans[i] = calloc(c, sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    *returnSize = r;

    for (i = 0; i < m * n; i++) {
        ans[i / c][i % c] = mat[i / n][i % n];
    }

    return ans;
}
