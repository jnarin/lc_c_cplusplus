/*
 * Link: https://leetcode.com/problems/count-vowels-permutation/
 * Problem: 1220. Count Vowels Permutation
 * */


#define  MOD    (long long)(1e9 + 7)

typedef enum{
    IDX_A   = 0,
    IDX_E,
    IDX_I,
    IDX_O,
    IDX_U,
    IDX_MAX
}eVowelsIndex;

int countVowelPermutation(int n){
    long long dp[IDX_MAX], newDp[IDX_MAX];
    int i, ans = 0;
    
    for (i = 0; i < IDX_MAX; i++){
        dp[i] = 1L;
    }
    
    for (i = 1; i < n; i++){
        newDp[IDX_A] = (dp[IDX_E] + dp[IDX_I] + dp[IDX_U]) % MOD;
        newDp[IDX_E] = (dp[IDX_A] + dp[IDX_I]) % MOD;
        newDp[IDX_I] = (dp[IDX_E] + dp[IDX_O]) % MOD;
        newDp[IDX_O] = (dp[IDX_I]);
        newDp[IDX_U] = (dp[IDX_I] + dp[IDX_O]) % MOD;
        
        memcpy(dp, newDp, sizeof(dp));
    }
    
    for (i = 0; i < IDX_MAX; i++){
        ans = (ans + dp[i]) % MOD;
    }
    
    return ans;
}
