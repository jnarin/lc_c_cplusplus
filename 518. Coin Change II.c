/*
 * Link: https://leetcode.com/problems/coin-change-ii/
 * Problem: 518. Coin Change II
 * */

int change(int amount, int* coins, int coinsSize){
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    int i, j;

    for (i = 0; i < coinsSize; i++){
        for (j = coins[i]; j <= amount; j++){
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}
