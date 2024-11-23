/*
Problem: 1861. Rotating the Box
Link: https://leetcode.com/problems/rotating-the-box/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){
    int m = boxSize, n = boxColSize[0], i, j, k;
    
    char **ans = calloc(n, sizeof(char *));
    *returnSize = n;
    *returnColumnSizes = calloc(n, sizeof(int));
    
    for (i = 0; i < n; i++) {
        ans[i] = calloc(m, sizeof(int));
        (*returnColumnSizes)[i] = m;
        memset(ans[i], '.', m * sizeof(char));
    }
    
    for (i = 0; i < m; i++) {
        for (j = n - 1, k = n - 1; j >= 0; j--) {
            if (box[i][j] != '.') {
                if (box[i][j] == '*') {
                    k = j;
                }
                
                ans[k--][m - i - 1] = box[i][j];
            }
        }
    }
    
    return ans;
}
