/*
 * Link: https://leetcode.com/problems/count-all-possible-routes/
 * Problem: 1575. Count All Possible Routes
 * */

#define MODVAL  (int)(1e9 + 7)

static int count(int* locations, int locationsSize, int start, int finish, int fuel, int **dp){
    if (fuel < 0){
        return 0;
    }

    if (dp[start][fuel] != -1){
        return dp[start][fuel];
    }

    int ans = (start == finish) ? 1 : 0;

    int i;

    for (i = 0; i < locationsSize; i++){
        if (i == start){
            continue;
        }

        ans = (ans + count(locations, locationsSize, i, finish, fuel - (abs(locations[start] - locations[i])), dp)) % MODVAL;
    }

    dp[start][fuel] = ans;

    return ans;
}

int countRoutes(int* locations, int locationsSize, int start, int finish, int fuel){
    int **dp, i, j, ans;

    dp = calloc(locationsSize, sizeof(int *));
    for (i = 0; i < locationsSize; i++){
        dp[i] = calloc(fuel + 1, sizeof(int));
        for (j = 0; j < fuel + 1; j++){
            dp[i][j] = -1;
        }
    }

    ans = count(locations, locationsSize, start, finish, fuel, dp);

    for (i = 0; i < locationsSize; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}
