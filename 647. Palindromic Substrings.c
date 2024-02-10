/*
 * Link: https://leetcode.com/problems/palindromic-substrings/
 * Problem: 647. Palindromic Substrings
 * */

int countSubstrings(char * s){
    int size = strlen(s);
    bool dp[size][size];
    int i, k;
    int ans = size;

    memset(dp, 0, sizeof(dp));
    for (i = 0; i < size; i++){
        dp[i][i] = true;
    }

    for (i = 0; i < size - 1; i++){
        if (s[i] == s[i + 1]){
            dp[i][i + 1] = true;
            ans++;
        }
    }

    for (k = 3; k <= size; k++){
        for (int i = 0; i < size - k + 1; i++){
            int j = i + k - 1;
            if (dp [i + 1][j - 1] && s[i] == s[j]){
                dp[i][j] = true;
                ans++;
            }
        }
    }

    return ans;
}
