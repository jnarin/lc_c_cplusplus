/*
 * Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/ 
 * Problem: 1930. Unique Length-3 Palindromic Subsequences
 * */

#define MINVAL(a, b)    (((a) < (b)) ? (a) : (b))

static int getUniqueChars(char *s, int start, int end){
    int count, i, ans;

    count = ans = 0;

    for (i = start; i < end; i++){
        count |= 1 << (s[i] - 'a');
    }

    while (count){
        ans += (count & 1);
        count >>= 1;
    }

    return ans;
}

int countPalindromicSubsequence(char* s) {
    int ans = 0, i;
    int firstSeen[26], lastSeen[26];
    int len = strlen(s);

    for (i = 0; i < 26; i++){
        firstSeen[i]= len;
        lastSeen[i] = 0;
    }

    for (i = 0; i < len; i++){
        char c = s[i] - 'a';
        firstSeen[c] = MINVAL(firstSeen[c], i);
        lastSeen[c] = i;
    }

    for (i = 0; i < 26; i++){
        if (firstSeen[i] < lastSeen[i]){
            ans += getUniqueChars(s, firstSeen[i] + 1, lastSeen[i]);
        }
    }

    return ans;
}
