/*
Problem: 1813. Sentence Similarity III
Link: https://leetcode.com/problems/sentence-similarity-iii/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

struct sentenceProps {
    char *p;
    int len;
    int longestWordLen;
    int numWords;
    char **words;
};

static void sentenceParse(struct sentenceProps *s) {
    int i, t = 0;
    
    for (i = 0; i < s->len; i++) {
        if (s->p[i] == ' ') {
            s->longestWordLen = MAXVAL(s->longestWordLen, i - t);
            t = i;
            s->numWords++;
        }
    }
    
    s->longestWordLen = s->numWords == 1 ? s->len : MAXVAL(s->longestWordLen, s->len - t - 1);
}

static void extractWords(struct sentenceProps *s) {
    int i, t = 0, word = 0;

    for (i = 0; i < s->len; i++) {
        if (s->p[i] == ' ') {
            s->words[word][i - t] = '\0';
            t = i + 1;
            word++;
        } else {
            s->words[word][i - t] = s->p[i];
        }
    }

    s->words[word][s->len - t] = '\0';
}

bool areSentencesSimilar(char* sentence1, char* sentence2) {
    struct sentenceProps s1 = {0}, s2 = {0};

    s1.p = sentence1;
    s2.p = sentence2;

    s1.len = strlen(sentence1);
    s2.len = strlen(sentence2);

    if (s1.len == s2.len) {
        return strcmp(sentence1, sentence2) == 0;
    }
    
    if (s1.len == 0 || s2.len == 0) {
        return true;
    }

    s1.numWords = s2.numWords = 1;
    s1.longestWordLen = s2.longestWordLen = INT_MIN;

    sentenceParse(&s1);
    sentenceParse(&s2);

    if (s1.numWords > s2.numWords) {
        return areSentencesSimilar(sentence2, sentence1);
    }
    
    s1.words = calloc(s1.numWords, sizeof(char *));
    s2.words = calloc(s2.numWords, sizeof(char *));
    
    int i;
    
    for (i = 0; i < s1.numWords; i++) {
        s1.words[i] = calloc(s1.longestWordLen + 1, sizeof(char));
    }
    
    for (i = 0; i < s2.numWords; i++) {
        s2.words[i] = calloc(s2.longestWordLen + 1, sizeof(char));
    }
    
    extractWords(&s1);
    extractWords(&s2);

    bool ans;
    i = 0;
    
    while (i < s1.numWords && strcmp(s1.words[i], s2.words[i]) == 0) {
        i++;
    }

    while (i < s1.numWords && strcmp(s1.words[i], s2.words[i + s2.numWords - s1.numWords]) == 0) {
        i++;
    }
    
    ans = i == s1.numWords;
    
    for (i = 0; i < s1.numWords; i++) {
        free(s1.words[i]);
    }
    free(s1.words);
    
    for (i = 0; i < s2.numWords; i++) {
        free(s2.words[i]);
    }
    free(s2.words);
    
    return ans;
}
