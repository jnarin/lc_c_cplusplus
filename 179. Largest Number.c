/*
Problem: 179. Largest Number
Link: https://leetcode.com/problems/largest-number/
*/
#define MAX_NUM_LEN (30)
static int cmp(const void *a, const void *b) {
    char s1[MAX_NUM_LEN], s2[MAX_NUM_LEN];

    sprintf(s1, "%s%s", *(char **)a, *(char **)b);
    sprintf(s2, "%s%s", *(char **)b, *(char **)a);
    
    return strcmp(s2, s1);
}

char * largestNumber(int* nums, int numsSize){
    char **strs = calloc(numsSize, sizeof(char *));
    int i;

    for(i = 0; i < numsSize; i++) {
        strs[i] = calloc(MAX_NUM_LEN, sizeof(char));
        sprintf(strs[i], "%d", nums[i]);
    }
    
    qsort(strs, numsSize, sizeof(char *), cmp);

    char *res = calloc(10000, sizeof(char));

    for(i = 0; i < numsSize; i++) {
        strcat(res, strs[i]);
    }

    if(res[0] == '0') {
        res[1] = '\0';
    }

    for (i = 0; i < numsSize; i++) {
        free(strs[i]);
    }
    free(strs);

    return res;
}
