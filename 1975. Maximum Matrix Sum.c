/*
Problem: 1975. Maximum Matrix Sum
Link: https://leetcode.com/problems/maximum-matrix-sum/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long s = 0;
    int min = INT_MAX, numOdd = 0, i, j;
    
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[0]; j++) {
            s += abs(matrix[i][j]);
            min = MINVAL(min, abs(matrix[i][j]));
            numOdd ^= matrix[i][j] < 0 ? 1 : 0;
        }
    }
    
    return s - numOdd * min * 2;
}
