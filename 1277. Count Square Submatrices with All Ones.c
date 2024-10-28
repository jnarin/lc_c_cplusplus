/*
Problem: 1277. Count Square Submatrices with All Ones
Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize, cols = matrixColSize[0], count = 0, i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] == 1 && i > 0 && j > 0) {
                matrix[i][j] = 1 + MINVAL(matrix[i-1][j-1], 
                                  MINVAL(matrix[i-1][j], matrix[i][j-1]));
            }
            
            count += matrix[i][j];
        }
    }

    return count;
}
