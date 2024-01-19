/*
Link: https://leetcode.com/problems/minimum-falling-path-sum/
Problem: 931. Minimum Falling Path Sum
*/

#define MIN_VAL(a, b) ({\
__typeof__(a) _a = (a);\
__typeof__(b) _b = (b);\
_a < _b ? _a : _b;\
})

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    const int len = matrixSize;
    if (len == 0){
        return 0;
    }

    int dp[len][len];
    memset(dp, 0, sizeof(dp));

    int i, j;

    for(i = 0; i < len; i++){
        dp[0][i] = matrix[0][i];
    }

    for (i = 1; i < len; i++){
        for(j = 0; j < len; j++){
            dp[i][j] = MIN_VAL(MIN_VAL(j > 0 ? dp[i - 1][j - 1] : INT_MAX, j + 1 < len ? dp[i - 1][j + 1] : INT_MAX), dp[i - 1][j]) + matrix[i][j];
        }
    }

    int ans = INT_MAX;
    for (i = 0; i < len; i++){
        ans = dp[len - 1][i] < ans ? dp[len - 1][i]  : ans;
    }

    return ans;

}