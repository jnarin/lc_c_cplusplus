/*
Link: https://leetcode.com/problems/pascals-triangle-ii/
Problem: 119. Pascal's Triangle II
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    rowIndex++;
    
    int *ans = calloc(rowIndex, sizeof(int)), i, j;
    
    for (i = 0; i < rowIndex; i++){
        ans[i] = 1;
    }
    
    for (i = 2; i < rowIndex; i++){
        for (j = 1; j < i; j++){
            ans[i - j] += ans[i - j - 1];
        }
    }
    
    *returnSize = rowIndex;
    return ans;
}