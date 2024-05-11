/*
Link: https://leetcode.com/problems/bag-of-tokens/
Problem: 948. Bag of Tokens
*/

static int incr_cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power){
    
    qsort(tokens, tokensSize, sizeof(int), incr_cmp);
    int i, j, n;
    i = 0;
    j = n = tokensSize;
    
    while (i < j){
        if (power >= tokens[i]){
            power -= tokens[i];
            i++;
        } else if (i - (n - j) && j > i + 1){
            j--;
            power += tokens[j];
        } else {
            break;
        }
    }
    
    return i - (n - j);
}