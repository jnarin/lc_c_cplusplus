/*
Problem: 214. Shortest Palindrome
Link: https://leetcode.com/problems/shortest-palindrome/
*/

/*
Problem: 214. Shortest Palindrome
Link: https://leetcode.com/problems/shortest-palindrome/
*/

char * shortestPalindrome(char * s){
    int sLen = strlen(s), MOD = 1e9 + 7, len  = 0, i;
    long long p, prime = 31, hash1 = 0, hash2 = 0;

    for (i = 0, p = 1; i < sLen; i++, p = (p * prime) % MOD) {
        hash1 = (hash1 * prime + s[i]) % MOD;
        hash2 = (hash2 + s[i] * p) % MOD;
        if (hash1 == hash2) {
            len = i + 1;
        }
    }

    char *ans = calloc((2 * sLen - len + 1), sizeof(char));
    for (i = 0; i < sLen - len; i++) {
        ans[i] = s[sLen - i - 1];
    }

    strcat(ans, s);
    return ans;
}
