/* Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
 * Problem: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
 * */

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int incr_cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int minCost(int n, int* cuts, int cutsSize){
    int t[cutsSize + 2];
    memcpy(t, cuts, sizeof(int) * cutsSize);
    t[cutsSize] = 0;
    t[cutsSize + 1] = n;

    qsort(t, cutsSize + 2, sizeof(int), incr_cmp);

    int dp[cutsSize + 2][cutsSize + 2];
    memset(dp, 0, sizeof(dp));

    int i, j, k, l;

    for (k = 2; k < cutsSize + 2; k++){
        for (i = 0; i + k < cutsSize + 2; i++){
            j = i + k;

            dp[i][j] = INT_MAX;
            for (l = i + 1; l < j; l++){
                dp[i][j] = MINVAL(dp[i][j], t[j] - t[i] + dp[i][l] + dp[l][j]);
            }
        }
    }

    return dp[0][cutsSize + 1];
}
