/*
 * Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * Problem: 1160. Find Words That Can Be Formed by Characters
 * */

#define MAX_ALPHA   (26)
#define CHAR_TO_INT(c)  ((c) - 'a')

int countCharacters(char** words, int wordsSize, char* chars) {
    int charsMap[MAX_ALPHA] = {0};
    int i, charsLen = strlen(chars);
    int ans = 0;

    for (i = 0; i < charsLen; i++){
        charsMap[CHAR_TO_INT(chars[i])]++;
    }

    for (i = 0; i < wordsSize; i++){
        int wordLen = strlen(words[i]);
        int wordMap[MAX_ALPHA] = {0};
        int j;
        bool skipWord = false;

        for (j = 0; j < wordLen; j++) {
            wordMap[CHAR_TO_INT(words[i][j])]++;
        }

        for (j = 0; j < wordLen; j++){
            if (wordMap[CHAR_TO_INT(words[i][j])] > charsMap[CHAR_TO_INT(words[i][j])]){
                skipWord = true;
                break;
            }
        }

        if (skipWord == false){
            ans += wordLen;
        }
    }

    return ans;
}

