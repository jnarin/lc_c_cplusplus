/*
Problem: 1072. Flip Columns For Maximum Number of Equal Rows
Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, k, max = 0, count, n = *matrixColSize;
    int a[n];
    
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < n; j++) {
            a[j] = matrix[i][j] ^ matrix[i][0];
        }
        
        count = 0;
        for (j = 0; j < matrixSize; j++) {
            for (k = 0; k < n; k++) {
                if (a[k] != (matrix[j][k] ^ matrix[j][0])) {
                    break;
                }
            }
            if (k == n) {
                count++;
            }
        }
        
        max = MAXVAL(max, count);
    }

    return max;
}
