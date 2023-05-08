/*
Link: https://leetcode.com/problems/matrix-diagonal-sum/
Problem: 1572. Matrix Diagonal Sum
*/
int diagonalSum(int** mat, int matSize, int* matColSize){
    int i, j, ans= 0, t = matSize - 1;
    
    for (i = 0; i < matSize; i++){
        ans += mat[i][i] + mat[t - i][i];
    }
    
    ans = t & 1 ? ans : ans - mat[t >> 1][t >> 1];
    
    return ans;

}