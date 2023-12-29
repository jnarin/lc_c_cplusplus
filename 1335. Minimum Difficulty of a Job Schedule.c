/*
 * Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
 * Problem: 1335. Minimum Difficulty of a Job Schedule
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int getMax(int* jobDifficulty, int jobDifficultySize, int idx) {
    int ans = INT_MIN, i;

    for (i = idx; i < jobDifficultySize; i++) {
        ans = MAXVAL(ans, jobDifficulty[i]);
    }

    return ans;
}

static int dfs(int* jobDifficulty, int jobDifficultySize, int d, int idx, int **dp) {
    if (d == 1) {
        return getMax(jobDifficulty, jobDifficultySize, idx);
    }

    if (dp[d][idx] != -1) {
        return dp[d][idx];
    }

    int max = INT_MIN, ans = INT_MAX, i;
    for (i = idx; i < jobDifficultySize - d + 1; i++){
        max = MAXVAL(max, jobDifficulty[i]);
        ans = MINVAL(ans, max + dfs(jobDifficulty, jobDifficultySize, d - 1, i + 1, dp));
    }

    dp[d][idx] = ans;

    return ans;
}

int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d) {
    int ans = -1;
    if (d > jobDifficultySize) {
        return ans;
    }

    int **dp, i, j;
    dp = calloc(d + 1, sizeof(int *));
    for (i = 0; i < d + 1; i++){
        dp[i] = calloc(jobDifficultySize, sizeof(int));
        for (j = 0; j < jobDifficultySize; j++) {
            dp[i][j] = -1;
        }
    }

    ans = dfs(jobDifficulty, jobDifficultySize, d, 0, dp);

    for (i = 0; i < d + 1; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}

