/*
Problem: 2942. Find Words Containing Character
Link: https://leetcode.com/problems/find-words-containing-character/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int *ans = calloc(wordsSize, sizeof(int)), idx = 0, i;

    for (i = 0; i < wordsSize; i++) {
        if (strchr(words[i], x)) {
            ans[idx++] = i;
        }
    }

    *returnSize = idx;
    return ans;
}
