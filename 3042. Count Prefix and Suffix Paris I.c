/*
Problem:3042. Count Prefix and Suffix Paris I
Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/
*/

static int isPrefixAndSuffix(char *pattern, char *word) {
    int patternLen = strlen(pattern), wordLen = strlen(word), i, j;

    if (patternLen > wordLen) {
        return false;
    }

    // Check prefix
    for (i = 0; i < patternLen; i++) {
        if (pattern[i] != word[i]) {
            return false;
        }
    }

    // Check suffix
    for (i = patternLen - 1, j = wordLen - 1; i >= 0 && j >= 0; i--) {
        if (pattern[i] != word[j--]) {
            return false;
        }
    }

    return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int i, j, ans = 0;

    for (i = 0; i < wordsSize; i++) {
        for (j = i + 1; j < wordsSize; j++) {
            ans += isPrefixAndSuffix(words[i], words[j]) ? 1 : 0;
        }
    }
    
    return ans;
}
