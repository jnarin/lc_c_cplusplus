/*
Problem: 3000. Maximum Area of Longest Diagonal Rectangle
Link: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int diag[dimensionsSize], i, maxDiag = -1;
    
    for (i = 0; i < dimensionsSize; i++) {
        diag[i] = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
        maxDiag = MAXVAL(maxDiag, diag[i]);
    }
    
    int ans = 0, area = 0;
    for (i = 0; i < dimensionsSize; i++) {
        if (diag[i] == maxDiag) {
            area = dimensions[i][0] * dimensions[i][1];
            ans = MAXVAL(ans, area);
        }
    }
    
    return ans;
}
