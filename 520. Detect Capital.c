/*
Problem: 520. Detect Capital
Link: https://leetcode.com/problems/detect-capital/
*/

bool detectCapitalUse(char * word){
    int len = strlen(word);

    char uWord[len + 1], lWord[len + 1];
    memset(uWord, 0, sizeof(uWord));
    memset(lWord, 0, sizeof(lWord));

    int i;

    for (i = 0; i < len; i++){
        uWord[i] = toupper(word[i]);
        lWord[i] = tolower(word[i]);
    }

    if (strncmp(uWord, word, len) == 0 || strncmp(lWord, word, len) == 0){
        return true;
    }

    if (word[0] < 'A' || word[0] > 'Z'){
        return false;
    }

    for (i = 1; i < len; i++){
        if (word[i] >= 'A' && word[i] <= 'Z'){
            return false;
        }
    }

    return true;

}
