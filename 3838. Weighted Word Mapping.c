/*
Problem: 3838. Weighted Word Mapping
Link: https://leetcode.com/problems/weighted-word-mapping/
*/

char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char *ans = calloc(wordsSize + 1, sizeof(char));
    int idx = 0, i;

    for (i = 0; i < wordsSize; i++) {
        char *c= words[i];
        int wordSum = 0;
        while (*c) {
            wordSum += weights[*c - 'a'];
            c++;
        }

        ans[idx++] = 'z' - (wordSum % 26);
    }
    
    return ans;
}
