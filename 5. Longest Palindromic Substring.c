/*
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 * Problem: 5. Longest Palindromic Substring
 * */

char * longestPalindrome(char * s){
    int len = strlen(s), i, j, k, maxLen, startIdx;
    bool dp[len][len];
    char *ans;

    memset(dp, false, sizeof(dp));
    maxLen = 1;
    startIdx = 0;

    for (i = 0; i < len; i++){
        // Every character is a palindrome
        dp[i][i] = true;
    }

    for (i = 0; i < len - 1; i++){
        // Check if adjacent character is same
        if (s[i] == s[i + 1]){
            dp[i][i + 1] = true;
            startIdx = i;
            maxLen = 2;
        }
    }

    for (k = 3; k <= len; k++){
        // Check if each k characters form a palindrome
        for (i = 0; i < len - k + 1; i++){
            j = i + k - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]){
                dp[i][j] = true;
                if (k > maxLen){
                    startIdx = i;
                    maxLen = k;
                }
            }
        }
    }

    ans = calloc(maxLen + 1, sizeof(char));
    strncpy(ans, s + startIdx, maxLen);

    return ans;
}
