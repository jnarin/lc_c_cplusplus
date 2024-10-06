/*
Problem: 1813. Sentence Similarity III
Link: https://leetcode.com/problems/sentence-similarity-iii/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int sentenceParse(char *s, int sLen, int *longestWordLen) {
    int words = 1, i;
    int longestLen = INT_MIN, p = 0;
    
    for (i = 0; i < sLen; i++) {
        if (s[i] == ' ') {
            *longestWordLen = MAXVAL(*longestWordLen, i - p);
            p = i;
            words++;
        }
    }
    
    *longestWordLen = words == 1 ? sLen : MAXVAL(*longestWordLen, sLen - p - 1);
    
    return words;
}

static void extractWords(char *s, int sLen, char **words) {
    int i, p = 0, word = 0;
    for (i = 0; i < sLen; i++) {
        if (s[i] == ' ') {
            words[word][i - p] = '\0';
            p = i + 1;
            word++;
        } else {
            words[word][i - p] = s[i];
        }
    }
    words[word][sLen - p] = '\0';
}

bool areSentencesSimilar(char* sentence1, char* sentence2) {
    int len1 = strlen(sentence1), len2 = strlen(sentence2);
    if (len1 == len2) {
        return strcmp(sentence1, sentence2) == 0;
    }
    
    if (len1 == 0 || len2 == 0) {
        return true;
    }
        
    int longestWord1 = 0, longestWord2 = 0;
    int numWords1 = sentenceParse(sentence1, len1, &longestWord1), numWords2 = sentenceParse(sentence2, len2, &longestWord2);

    if (numWords1 > numWords2) {
        return areSentencesSimilar(sentence2, sentence1);
    }
    
    char **words1, **words2;
    words1 = calloc(numWords1, sizeof(char *));
    words2 = calloc(numWords2, sizeof(char *));
    
    int i;
    
    for (i = 0; i < numWords1; i++) {
        words1[i] = calloc(longestWord1 + 1, sizeof(char));
    }
    
    for (i = 0; i < numWords2; i++) {
        words2[i] = calloc(longestWord2 + 1, sizeof(char));
    }
    
    extractWords(sentence1, len1, words1);
    extractWords(sentence2, len2, words2);

    bool ans;
    i = 0;
    
    while (i < numWords1 && strcmp(words1[i], words2[i]) == 0) {
        i++;
    }

    while (i < numWords1 && strcmp(words1[i], words2[i + numWords2 - numWords1]) == 0) {
        i++;
    }
    
    ans = i == numWords1;
    
    for (i = 0; i < numWords1; i++) {
        free(words1[i]);
    }
    free(words1);
    
    for (i = 0; i < numWords2; i++) {
        free(words2[i]);
    }
    free(words2);
    
    return ans;
}
