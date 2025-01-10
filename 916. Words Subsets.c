/*
Problem: 916. Words Subsets.c
Link: https://leetcode.com/problems/word-subsets/description/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static void computeFreq(int *f, char *s) {
    int len = strlen(s), i;

    for (i = 0; i < len; i++) {
        f[s[i] - 'a']++;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    char **ans = calloc(words1Size, sizeof(char *));
    int idx = 0, i, j, maxFreqWords2[26] = {0}, f[26];
    bool flag;

    for (i = 0; i < words2Size; i++) {
        memset(f, 0, sizeof(f));

        computeFreq(f, words2[i]);

        for (j = 0; j < 26; j++) {
            maxFreqWords2[j] = MAXVAL(maxFreqWords2[j], f[j]);
        }
    }

    for (i = 0; i < words1Size; i++) {
        flag = true;
        memset(f, 0, sizeof(f));
        
        computeFreq(f, words1[i]);

        for (j = 0; j < 26; j++) {
            if (f[j] < maxFreqWords2[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans[idx] = calloc(strlen(words1[i]) + 1, sizeof(char));
            strcpy(ans[idx], words1[i]);
            idx++;
        }
    }
    
    *returnSize = idx;
    return ans;
}
