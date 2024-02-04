/*
 * Link: https://leetcode.com/problems/partition-array-for-maximum-sum/
 * Problem: 1043. Partition Array for Maximum Sum
 * */

#define MAX_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

#define MIN_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    int dp[arrSize + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= arrSize; i++) {
        int max = INT_MIN;
        for (int j = 1; j <= MIN_VAL(i, k); j++) {
            max = MAX_VAL(max, arr[i - j]);
            dp[i] = MAX_VAL(dp[i], dp[i - j] + max * j);
        }
    }

    return dp[arrSize];
}
