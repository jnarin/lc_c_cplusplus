/*
Link: https://leetcode.com/problems/longest-common-subsequence/
Problem: 1143. Longest Common Subsequence
*/
#define MAX_VAL(a, b) ({\
    __typeof__(a) _a;\
    __typeof__(b) _b;\
    a > b ? a : b; })

int longestCommonSubsequence(char * text1, char * text2){
    int m = strlen(text1), n = strlen(text2), dp[m + 1][n + 1], i, j;

    memset(dp, 0, sizeof(dp));

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            dp[i + 1][j + 1] = text1[i] == text2[j] ? 1 + dp[i][j] : MAX_VAL(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    return dp[m][n];
}