/*
 * Link: https://leetcode.com/problems/determine-if-two-strings-are-close/
 * Problem: 1657. Determine if Two Strings Are Close
 * */

#define MAX_ALPHA       (26)
#define CHAR_TO_IDX(c)  ((c) - 'a')

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool closeStrings(char* word1, char* word2) {
    int lenWord1 = strlen(word1), lenWord2 = strlen(word2);
    
    if (lenWord1 != lenWord2) {
        return false;
    }
    
    int word1Map[MAX_ALPHA] = {0}, word2Map[MAX_ALPHA] = {0};
    int i;
    
    for (i = 0; i < lenWord1; i++) {
        word1Map[CHAR_TO_IDX(word1[i])]++;
    }

    for (i = 0; i < lenWord2; i++) {
        word2Map[CHAR_TO_IDX(word2[i])]++;
    }
    
    if (memcmp(word1Map, word2Map, sizeof(word1Map)) == 0) {
        return true;
    }
    
    for (i = 0; i < MAX_ALPHA; i++) {
        if (!word1Map[i] && word2Map[i]) {
            return false;
        }
        
        if (word1Map[i] && !word2Map[i]) {
            return false;
        }
    }
    
    qsort(word1Map, MAX_ALPHA, sizeof(int), incrCmp);
    qsort(word2Map, MAX_ALPHA, sizeof(int), incrCmp);
    
    if (memcmp(word1Map, word2Map, sizeof(word1Map)) == 0) {
        return true;
    }
    
    return false;
}

