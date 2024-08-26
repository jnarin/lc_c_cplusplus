/*
Problem: 2828. Check if a String Is an Acronym of Words
Link: https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/
*/

bool isAcronym(char ** words, int wordsSize, char * s){
    int len = strlen(s), i;
    
    if (len != wordsSize) {
        return false;
    }

    for (i = 0; i < len; i++) {
        if (s[i] != words[i][0]) {
            return false;
        }
    }
    
    return true;
}
