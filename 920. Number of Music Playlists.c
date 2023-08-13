/*
 * Link: https://leetcode.com/problems/number-of-music-playlists/
 * Problem: 920. Number of Music Playlists
 * */

#define MAXVAL(a, b)\
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

const int MOD = (1e9 + 7);

static long solve(int n, int k, int i, int j, long **dp){
    if (i == 0){
        return j == 0;
    }

    if (j == 0){
        return 0;
    }

    if (dp[i][j] >= 0){
        return dp[i][j];
    }

    dp[i][j] = (solve(n, k, i - 1, j - 1, dp) * (n - (j - 1))
                + solve(n, k, i - 1, j, dp) * MAXVAL(0, j - k)) % MOD;

    return dp[i][j];
}

int numMusicPlaylists(int n, int goal, int k){
    long **dp, ans;
    int i, j;

    dp = calloc(goal + 1, sizeof(long *));
    for (i = 0; i < goal + 1; i++){
        dp[i] = calloc(n + 1, sizeof(long));
        for (j = 0; j < n + 1; j++){
            dp[i][j] = -1;
        }
    }

    ans = solve(n, k, goal, n, dp);

    for (i = 0; i < goal + 1; i++){
        free(dp[i]);
    }

    free(dp);

    return ans;
}
