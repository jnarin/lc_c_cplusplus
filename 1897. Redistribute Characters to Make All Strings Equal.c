/*
 * Link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
 * Problem: 1897. Redistribute Characters to Make All Strings Equal
 * */

#define NUM_CHARS   (26)
bool makeEqual(char ** words, int wordsSize){
    int m[NUM_CHARS] = {0}, i, t = 0;

    if (wordsSize == 1){
        return true;
    }

    for (i = 0; i < wordsSize; i++){
        int len = strlen(words[i]), j;
        for (j = 0; j < len; j++){
            m[words[i][j] - 'a']++;
        }
    }

    for (i = 0; i < NUM_CHARS; i++){
        if (m[i] == 0){
            continue;
        }

        if (m[i] % wordsSize != 0){
            return false;
        }
    }

    return true;
}

