/*
Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
Problem: 1582. Special Positions in a Binary Matrix
*/

int numSpecial(int** mat, int matSize, int* matColSize) {
    int rows[matSize], cols[matColSize[0]];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    
    int i, j;
    
    for (i = 0; i < matSize; i++){
        for (j = 0; j < matColSize[0]; j++){
            if (mat[i][j]){
                rows[i]++;
                cols[j]++;
            }
        }
    }
    
    
    int ans = 0;
    
    for (i = 0; i < matSize; i++){
        for (j = 0; j < matColSize[0]; j++){
            if (mat[i][j] && rows[i] == 1 && cols[j] == 1){
                ans++;
            }
        }
    }
    
    return ans;
}