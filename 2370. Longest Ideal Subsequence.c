/*
 * Problem: 2370. Longest Ideal Subsequence
 * Link: https://leetcode.com/problems/longest-ideal-subsequence/
 * */
#define MAX_ALPHA   (26)
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static int getMaxReachable(int *dp, int dpSize, int c, int k) {
    int first = MAXVAL(0, c - k), last = MINVAL(25, c + k), 
                maxReachable = 0, i;
    for (i = first; i <= last; i++) {
        maxReachable = MAXVAL(maxReachable, dp[i]);
    }
    
    return maxReachable;
}

static int getMax(int *array, int arraySize) {
    int ans = INT_MIN, i;
    
    for (i = 0; i < arraySize; i++) {
        ans = MAXVAL(ans, array[i]);
    }
    
    return ans;
}

int longestIdealString(char* s, int k) {
    int dp[MAX_ALPHA] = {0}, i, len = strlen(s);
    int c;
    
    for (i = 0; i < len; i++) {
        c = s[i] - 'a';
        dp[c] = 1 + getMaxReachable(dp, MAX_ALPHA, c, k);
    }
    
    return getMax(dp, MAX_ALPHA);
}
