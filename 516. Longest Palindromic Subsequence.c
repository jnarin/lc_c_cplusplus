/*
Link: https://leetcode.com/problems/longest-palindromic-subsequence/
Problem : 516. Longest Palindromic Subsequence
*/
#define MAX_VAL(a, b) ({\
__typeof__(a) _a = (a); \
__typeof__(b) _b = (b); \
a > b ? a : b;\
})

int longestPalindromeSubseq(char * s){
    int len = strlen(s);
    int i, j;
    int dp[len][len];
    memset(dp, 0, sizeof(dp));

    for (i = len - 1; i >= 0; i--){
        dp[i][i] = 1;
        for (j = i + 1; j < len; j++){
            dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : MAX_VAL(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][len - 1];
}