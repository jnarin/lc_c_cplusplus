/*
Problem: 1078. Occurrences After Bigram
Link: https://leetcode.com/problems/occurrences-after-bigram/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
    char** ans = calloc(1000, sizeof(char*));
    *returnSize = 0;

    char* token = strtok(text, " ");
    char* prev = NULL;
    char* prevPrev = NULL;
    
    while(token != NULL) {
        if(prevPrev != NULL && strcmp(prevPrev, first) == 0 && strcmp(prev, second) == 0) {
            ans[*returnSize] = (char*)malloc(strlen(token) + 1);
            strcpy(ans[*returnSize], token);
            (*returnSize)++;
        }
        prevPrev = prev;
        prev = token;
        token = strtok(NULL, " ");
    }

    return ans;
}
