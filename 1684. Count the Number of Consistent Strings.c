/*
Problem: 1684. Count the Number of Consistent Strings
Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
*/

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    char allowedMap[26] = {0}, c;
    int allowedLen = strlen(allowed), i, wordLen, ans = 0, j;
    bool isConsistent;
    
    for (i = 0; i < allowedLen; i++) {
        allowedMap[allowed[i] - 'a']++;
    }
    
    for (i = 0; i < wordsSize; i++) {
        wordLen = strlen(words[i]);
        isConsistent = true;
        
        for (j = 0; j < wordLen; j++) {
            c = words[i][j];
            
            if (allowedMap[c - 'a'] == 0) {
                isConsistent = false;
                break;
            }
        }
        
        ans += isConsistent ? 1 : 0;
    }

    return ans;
}
