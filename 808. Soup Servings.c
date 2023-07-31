/*
 * Link: https://leetcode.com/problems/soup-servings/
 * Problem: 808. Soup Servings
 * */

#define MAX_DP_SIZE (4800/25)

static double dfs(double dp[MAX_DP_SIZE][MAX_DP_SIZE], int a, int b){
    if (a <= 0 && b <= 0){
        return 0.5;
    }

    if (a <= 0){
        return 1.0;
    }

    if (b <= 0){
        return 0.0;
    }

    if (dp[a][b] > 0){
        return dp[a][b];
    }

    dp[a][b] = 0.25 * (dfs(dp, a - 4, b) + dfs(dp, a - 3, b - 1) + dfs(dp, a - 2, b - 2) + dfs(dp, a - 1, b - 3));
    return dp[a][b];
}

double soupServings(int n){
    double dp[MAX_DP_SIZE][MAX_DP_SIZE] = {0};

    if (n >= 4800){
        return 1.0;
    }

    return dfs(dp, (n + 24) / 25, (n + 24) / 25);
}

