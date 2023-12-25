/*
 * Link: https://leetcode.com/problems/decode-ways/
 * Problem: 91. Decode Ways
 * */

int numDecodings(char * s){
    if (s == NULL || s[0] == '\0'){
        return 0;
    }

    int len = strlen(s);
    int dp[len + 1];

    memset(dp, 0, sizeof(dp));
    dp[len] = 1;
    dp[len - 1] = s[len - 1] > '0' ? 1 : 0;

    int i;
    for (i = len - 2; i >= 0; i--){
        if (s[i] == '0'){
            dp[i] = 0;
        } else {
            int t = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (t > 26){
                dp[i] = dp[i + 1];
            } else {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
        }
    }

    return dp[0];
}
