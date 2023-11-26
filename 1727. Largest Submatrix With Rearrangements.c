/*
 * Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
 * Problem: 1727. Largest Submatrix With Rearrangements
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

static int decrCmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, ans = 0;

    for (j = 0; j < matrixColSize[0]; j++){
        for (i = matrixSize - 1; i >= 0; i--){
            if (matrix[i][j] && i < matrixSize - 1){
                matrix[i][j] = matrix[i + 1][j] + 1;
            }
        }
    }

    for (i = 0; i < matrixSize; i++){
        qsort(matrix[i], matrixColSize[i], sizeof(int), decrCmp);

        for (j = 0; j < matrixColSize[i]; j++){
            if (matrix[i][j] == 0){
                break;
            }

            ans = MAXVAL(ans, (j + 1) * matrix[i][j]);
        }
    }

    return ans;
}

