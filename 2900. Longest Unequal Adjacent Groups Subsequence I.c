/*
Problem: 2900. Longest Unequal Adjacent Groups Subsequence I
Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    char** result = calloc(wordsSize, sizeof(char *));
    int count = 0, i;

    for (i = 0; i < wordsSize; i++) {
        if (i == 0 || groups[i] != groups[i - 1]) {
            result[count] = calloc(strlen(words[i]) + 1, sizeof(char *));
            strcpy(result[count], words[i]);
            count++;
        }
    }

    *returnSize = count;

    return result;
}
