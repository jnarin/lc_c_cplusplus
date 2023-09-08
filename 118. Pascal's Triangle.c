/*
Link: https://leetcode.com/problems/pascals-triangle/
Problem: 118. Pascal's Triangle
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **ans = calloc(numRows, sizeof(int *)), i, j;
    *returnSize = numRows;
    *returnColumnSizes = calloc(numRows, sizeof(int *));
    
    for (i = 0; i < numRows; i++){
        ans[i] = calloc(i + 1, sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        
        for (j = 0; j < i + 1; j++){
            ans[i][j] = 1;
        }
        
        for (j = 1; j < i; j++){
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
    }
    
    return ans;
}