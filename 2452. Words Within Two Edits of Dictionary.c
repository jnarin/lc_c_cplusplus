/*
Problem: 2452. Words Within Two Edits of Dictionary
Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
    char **ans = calloc(queriesSize, sizeof(char*));
    int count = 0, i, j, k, edits;

    for (i = 0; i < queriesSize; i++) {
        for (j = 0; j < dictionarySize; j++) {
            edits = 0;
            for (k = 0; k < strlen(queries[i]); k++) {
                if (queries[i][k] != dictionary[j][k]) {
                    edits++;
                    if (edits > 2) {
                        break;
                    }
                }
            }

            if (edits <= 2) {
                ans[count++] = queries[i];
                break;
            }
        }
    }

    *returnSize = count;
    return ans;
}
