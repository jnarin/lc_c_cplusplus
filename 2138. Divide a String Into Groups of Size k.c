/*
Problem: 2138. Divide a String Into Groups of Size k
Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s), ansLen = (len / k) + ((len % k) != 0), i, j;
    char **ans;

    ans = calloc(ansLen, sizeof(char *));
    for (i = 0; i < ansLen; i++) {
        ans[i] = calloc(k + 1, sizeof(char));
        memset(ans[i], fill, k);
    }

    for (i = 0, j = 0; i < ansLen; i++) {
        memcpy(ans[i], &s[j], (j + k < len) ? k : len - j);
        j += k;
    }

    *returnSize = ansLen;
    return ans;
}
