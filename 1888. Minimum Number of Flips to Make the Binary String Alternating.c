/*
Problem: 1888. Minimum Number of Flips to Make the Binary String Alternating
Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
*/
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int minFlips(char* s) {
    int count[2][2] = {0}, i, len = strlen(s), ans;

    for (i = 0; i < len; i++) {
        count[s[i] - '0'][i & 1]++;
    }

    ans = MINVAL(count[1][0] + count[0][1], count[0][0] + count[1][1]);

    for (i = 0; i < len; i++) {
        count[s[i] - '0'][i & 1]--;
        count[s[i] - '0'][(len + i) & 1]++;
        ans = MINVAL(ans, MINVAL(count[1][0] + count[0][1], count[0][0] + count[1][1]));
    }

    return ans;
}
