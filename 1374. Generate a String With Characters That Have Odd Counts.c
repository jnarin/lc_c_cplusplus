/*
 * Link: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
 * Problem: 1374. Generate a String With Characters That Have Odd Counts
 * */

char* generateTheString(int n) {
    char *ans = calloc(n + 1, sizeof(char));
    int i = 0;

    if (n & 1) {
        while (i < n) {
            ans[i++] = 'a';
        }
    } else {
        while (i < n - 1) {
            ans[i++] = 'a';
        }

        ans[i] = 'b';
    }

    return ans;
}

