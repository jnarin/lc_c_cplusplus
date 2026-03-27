/*
Problem: 2946. Matrix Similarity After Cyclic Shifts
Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
*/

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int n = matColSize[0], m = matSize;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int new_j;
            if (i % 2 == 0) {
                new_j = (j + k) % n;
            } else {
                new_j = ((j - k) % n + n) % n;
            }
            if (mat[i][j] != mat[i][new_j]) {
                return false;
            }
        }
    }
    return true;
    
}
