/*
Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
Problem: 1662. Check If Two String Arrays are Equivalent
*/

#define MAX_LEN (1001)

static void combineWord(char **word, int wordSize, char *s, int sLen){
    int i, j, k;
    j = 0;
    
    for (i = 0; i < wordSize; i++){
        k = 0;

        while (word[i][k]){            
            s[j++] = word[i][k++];
        }
    }
    
}

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    char s1[MAX_LEN + 1] = {0}, s2[MAX_LEN + 1] = {0};
    
    combineWord(word1, word1Size, s1, MAX_LEN);
    combineWord(word2, word2Size, s2, MAX_LEN);
    
    return memcmp(s1, s2, MAX_LEN * sizeof(char)) == 0;    
}