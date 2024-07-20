/*
Problem: 1605. Find Valid Matrix Given Row and Column Sums
Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int N = rowSumSize, M = colSumSize, 
            **originalMatrix, i, j, 
            currRowSum[N], currColSum[M];
    
    memset(currRowSum, 0, sizeof(currRowSum));
    memset(currColSum, 0, sizeof(currColSum));
    
    originalMatrix = calloc(N, sizeof(int *));
    *returnSize = N;
    *returnColumnSizes = calloc(N, sizeof(int *));
    for (i = 0; i < N; i++) {
        originalMatrix[i] = calloc(M, sizeof(int));
        (*returnColumnSizes)[i] = M;
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            originalMatrix[i][j] = MINVAL(rowSum[i] - currRowSum[i], colSum[j] - currColSum[j]);
            
            currRowSum[i] += originalMatrix[i][j];
            currColSum[j] += originalMatrix[i][j];
        }
    }
    
    return originalMatrix;    
}
