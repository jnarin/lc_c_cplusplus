/*
 * Link: https://leetcode.com/problems/strange-printer/
 * Problem: 664. Strange Printer
 * */


#define MINVAL(a, b)\
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int solve(int **dp, char *s, int i, int j){
    int k;

    if (i > j){
        return 0;
    }

    if (dp[i][j] > 0){
        return dp[i][j];
    }

    dp[i][j] = solve(dp, s, i + 1, j) + 1;

    for (k = i + 1; k <= j; k++){
        if (s[i] == s[k]){
            dp[i][j] = MINVAL(dp[i][j], solve(dp, s, i, k - 1) + solve(dp, s, k + 1, j));
        }
    }

    return dp[i][j];
}

int strangePrinter(char * s){
    int len = strlen(s), **dp, i;
    int ans;

    dp = calloc(len, sizeof(int *));
    for (i = 0; i < len; i++){
        dp[i] = calloc(len, sizeof(int));
    }

    ans = solve(dp, s, 0, len - 1);

    for (i = 0; i < len; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}
