/*
Problem: 2022. Convert 1D Array Into 2D Array
Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    if (m * n != originalSize) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int i, j, k = 0;
    int **ans = calloc(m, sizeof(int *));
    *returnSize = m;
    *returnColumnSizes = calloc(m, sizeof(int));
    
    for (i = 0; i < m; i++) {
        ans[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    for (i = 0; i < m; i++) {
        memcpy(&ans[i][0], &original[k], n * sizeof(int));
        k += n;
    }
    
    return ans;    
}
