/*
Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
Problem: 2108. Find First Palindromic String in the Array
*/
#define MAX_WORD_SIZE   (100 + 1)
bool isPalindrome(char *word) {
    int len = strlen(word), i;
    
    for (i = 0; i < (len >> 1); i++) {
        if (word[i] != word[len - 1 - i]) {
            return false;
        }
    }
    
    return true;
}

char* firstPalindrome(char** words, int wordsSize) {
    char i, *ans = calloc(MAX_WORD_SIZE, sizeof(char));
    
    for (i = 0; i < wordsSize; i++) {
        if (isPalindrome(words[i])) {
            strcpy(ans, words[i]);
            break;
        }
    }
    
    return ans;
}