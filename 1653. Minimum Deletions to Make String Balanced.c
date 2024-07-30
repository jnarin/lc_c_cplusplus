/*
Problem: 1653. Minimum Deletions to Make String Balanced
Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int minimumDeletions(char* s) {
    int ans = 0, bCount = 0, i, len = strlen(s);
    
    for (i = 0; i < len; i++) {
        if (s[i] == 'a') {
            ans = MINVAL(ans + 1, bCount);
        } else {
            bCount++;
        }
    }
    
    return ans;
}
