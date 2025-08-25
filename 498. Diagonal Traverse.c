/*
Problem: 498. Diagonal Traverse
https://leetcode.com/problems/diagonal-traverse/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize, n = *matColSize;
    int *ans = calloc(m * n, sizeof(int));
    int r = 0, c = 0, d = 1; // direction: 1 for up, -1 for down
    
    for (int i = 0; i < m * n; i++) {
        ans[i] = mat[r][c];
        r -= d;
        c += d;
        if (r >= m) { 
            r = m - 1; 
            c += 2; 
            d = -d; 
        }

        if (c >= n) {
            c = n - 1;
            r += 2; 
            d = -d; 
        }

        if (r < 0) {
            r = 0;
             d = -d; 
            }

        if (c < 0) { 
            c = 0; 
            d = -d; 
        }
    }

    *returnSize = m * n;
    return ans;
    
}
