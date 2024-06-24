/*
Problem: 1255. Maximum Score Words Formed by Letters
Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MAXALPHA    (26)

static int subsetScore(int *subset, int *score, int *freqMap) {
    int ans = 0, i;
    
    for (i = 0; i < MAXALPHA; i++) {
        ans += subset[i] * score[i];
        
        if (subset[i] > freqMap[i]) {
            return 0;
        }
    }
    
    return ans;
}

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    int freqMap[MAXALPHA] = {0}, i, j, ans = 0, subset[MAXALPHA], mask = 0;
    
    for (i = 0; i < lettersSize; i++) {
        freqMap[letters[i] - 'a']++;
    }
    
    for (mask = 0; mask < (1 << wordsSize); mask++) {
        memset(subset, 0, sizeof(subset));
        
        for (i = 0; i < wordsSize; i++) {
            if ((mask & (1 << i )) > 0) {
                int len = strlen(words[i]);
                for (j = 0; j < len; j++) {
                    subset[words[i][j] - 'a']++;
                }
            }
        }
        
        ans = MAXVAL(ans, subsetScore(subset, score, freqMap));
    }
    
    return ans;
}