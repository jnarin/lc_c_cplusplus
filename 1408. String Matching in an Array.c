/*
Problem: 1408. String Matching in an Array.c
https://leetcode.com/problems/string-matching-in-an-array/description/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    char **ans = calloc(wordsSize, sizeof(char *));
    int i, j, idx = 0;

    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < wordsSize; j++) {
            if (i != j) {
                if (strstr(words[j], words[i])) {
                    ans[idx] = calloc(strlen(words[i]) + 1, sizeof(char));
                    strcpy(ans[idx++], words[i]);
                    break;
                }
            }
        }
    }

    *returnSize = idx;
    return ans;
}
