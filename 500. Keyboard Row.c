/*
Problem: 500. Keyboard Row
Link: https://leetcode.com/problems/keyboard-row/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static bool checkRow(char *w, char *row) {
    int len = strlen(w), i;
    
    for (i = 0; i < len; i++) {
        if (strchr(row, w[i]) == NULL) {
            return false;
        }
    }
    
    return true;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    char **ans;
    int i, idx = 0;
    char *row1 = "qwertyuiopQWERTYUIOP",
         *row2 = "asdfghjklASDFGHJKL",
         *row3 = "zxcvbnmZXCVBNM";
    
    ans = calloc(wordsSize, sizeof(char *));
    for (i = 0; i < wordsSize; i++) {
        ans[i] = calloc(102, sizeof(char));
    }
    
    for (i = 0; i < wordsSize; i++) {
        if (checkRow(words[i], row1) || checkRow(words[i], row2) || checkRow(words[i], row3)) {
            strcpy(ans[idx++], words[i]);
        }
    }
    
    *returnSize = idx;
    return ans;
}
