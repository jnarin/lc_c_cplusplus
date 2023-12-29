/*
 * Link: https://leetcode.com/problems/string-compression-ii/
 * Problem: 1531. String Compression II
 * */

#define KMAX    (101)
#define MAXVAL(a, b) \
    ({  __typeof(a) _a = (a);\
     __typeof(b) _b = (b);\
     _a > _b ? _a : _b;  })

#define MINVAL(a, b) \
    ({  __typeof(a) _a = (a);\
     __typeof(b) _b = (b);\
     _a < _b ? _a : _b;  })


static int getLen(int maxFreq){
    if (maxFreq == 1){
        return 1;
    }

    if (maxFreq < 10){
        return 2;
    }

    if (maxFreq < 100){
        return 3;
    }

    return 4;
}

static int compression(char *s, int len, int i, int k, int **dp){
    if (k < 0){
        return KMAX;
    }

    if (i == len || len - i <= k){
        return 0;
    }

    if (dp[i][k] != KMAX){
        return dp[i][k];
    }

    int maxFreq = 0, count[128] = {0}, j;

    for (j = i; j < len; j++){
        count[s[j]]++;
        maxFreq = MAXVAL(count[s[j]], maxFreq);

        int x = getLen(maxFreq) +
            compression(s, len, j + 1, k - (j - i + 1 - maxFreq), dp);
        dp[i][k] = MINVAL(x, dp[i][k]);
    }

    return dp[i][k];
}

int getLengthOfOptimalCompression(char* s, int k) {
    int len = strlen(s), i, j, ans;
    int **dp = calloc(len, sizeof(int *));

    for (i = 0; i < len; i++){
        dp[i] = calloc(k + 1, sizeof(int));
        for (j = 0; j < k + 1; j++){
            dp[i][j] = KMAX;
        }
    }

    ans = compression(s, len, 0, k, dp);

    for (i = 0; i < len; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}
