/*
Problem: 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
*/

int isPrefixOfWord(char* sentence, char* searchWord) {
    int len = strlen(sentence), sLen = strlen(searchWord);
    int i = 0;
    int ans = 1;
    
    while (i < len) {
        if (strncmp(&sentence[i], searchWord, sLen) == 0) {
            return ans;
        }
        
        while (i < len && sentence[i] != ' ') {
            i++;
        }
        
        if (i == len) {
            return -1;
        }
        
        ans++;
        i++;
    }
    
    return ans;
}
