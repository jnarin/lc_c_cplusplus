/*
 * Problem: 59. Spiral Matrix II
 * Link: https://leetcode.com/problems/spiral-matrix-ii/
 * */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **ans, i, top, bottom, left, right, idx = 0, val = 1;
    
    assert(returnSize);
    assert(returnColumnSizes);
    
    ans = calloc(n, sizeof(int *));
    assert(ans);
    *returnSize = n;
    *returnColumnSizes = calloc(n, sizeof(int));
    assert(*returnColumnSizes);
    
    for (i = 0; i < n; i++){
        ans[i] = calloc(n, sizeof(int));
        assert(ans[i]);
        
        (*returnColumnSizes)[i] = n;
    }
    
    top = left = 0;
    bottom = right = n - 1;
    
    while (val <= (n * n)){
        i = left;
        while (i <= right){
            ans[top][i++] = val++;
        }
        top++;
        
        if (top > bottom){
            break;
        }
        
        i = top;
        while (i <= bottom){
            ans[i++][right] = val++;
        }
        right--;
        
        if (left > right){
            break;
        }
        
        i = right;
        while (i >= left){
            ans[bottom][i--] = val++;
        }
        bottom--;
        
        if (top > bottom){
            break;
        }
        
        i = bottom;
        while (i >= top){
            ans[i--][left] = val++;    
        }
        left++;
        if (left > right){
            break;
        }
    }
    
    return ans;

}
