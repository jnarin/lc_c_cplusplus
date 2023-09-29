/*
Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/
Problem: 2185. Counting Words With a Given Prefix
*/
int prefixCount(char ** words, int wordsSize, char * pref){
    int prefLen = strlen(pref), i, ans = 0;
    
    for (i = 0; i < wordsSize; i++){
        ans = (strncmp(words[i], pref, prefLen) == 0) ? ans + 1 : ans;
    }
    
    return ans;

}