/*
Problem: 2486. Append Characters to String to Make Subsequence
Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
*/

int appendCharacters(char* s, char* t) {
    int i, j;
    int sLen = strlen(s), tLen = strlen(t);
    
    i = j = 0;
    
    while (i < sLen && j < tLen) {
        if (s[i] == t[j]) {
            j++;
        }
        
        i++;
    }
    
    return tLen - j;
}