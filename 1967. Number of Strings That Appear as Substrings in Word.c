/*
Problem: 1967. Number of Strings That Appear as Substrings in Word
Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
*/

int numOfStrings(char** patterns, int patternsSize, char* word) {
    int ans = 0;

    for (int i = 0; i < patternsSize; i++) {
        ans += strstr(word, patterns[i]) != NULL;
    }

    return ans;    
}
