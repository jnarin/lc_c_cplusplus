/*
Problem: 1092. Shortest Common Supersequence
Link: https://leetcode.com/problems/shortest-common-supersequence/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static void reverse(char *s, int len) {
    int i = 0, j = len - 1;
    char t;
    while (i < j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

char* shortestCommonSupersequence(char* str1, char* str2) {
    int lenStr1 = strlen(str1), lenStr2 = strlen(str2), i, j, dp[lenStr1 + 1][lenStr2 + 1], idx = 0;

    char *ans = calloc(lenStr1 + lenStr2 + 1, sizeof(char));
    ;

    memset(dp, 0, sizeof(dp));

    for(i = 1; i <= lenStr1; i++) {
        for(j = 1; j <= lenStr2; j++) {
            dp[i][j] = str1[i - 1] == str2[j - 1] ? dp[i - 1][j - 1] + 1 : MAXVAL(dp[i - 1][j], dp[i][j - 1]);
        }

    }

    i = lenStr1;
    j = lenStr2;

    while (i || j) {
        if (i == 0) {
            ans[idx++] = str2[j - 1];
            j--;
        } else if (j == 0) {
            ans[idx++] = str1[i - 1];
            i--;
        } else if (str1[i - 1] == str2[j - 1]) {
            ans[idx++] = str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans[idx++] = str1[i - 1];
            i--;
        } else {
            ans[idx++] = str2[j - 1];
            j--;
        }
    }

    ans[idx] = '\0';
    reverse(ans, idx);

    return ans;
    
}
