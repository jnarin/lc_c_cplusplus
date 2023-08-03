/*
Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Problem: 17. Letter Combinations of a Phone Number
*/

static const char *char_map[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};


static void backTrack(char *digits, int digits_len,
                     int idx, char **res, char *t, 
                      int *returnSize){
    int i;
    if (digits_len == idx){
        t[idx] = 0;
        char *temp = (char *)calloc(digits_len + 1, sizeof(char));
        assert(temp);
        strncpy(temp, t, digits_len + 1);
        res[(*returnSize)++] = temp;
    } else {
        char *s = char_map[digits[idx] - '0'];
        int s_len = strlen(s);
        for (i = 0; i < s_len; i++){
            t[idx] = s[i];
            backTrack(digits, digits_len, idx + 1, res, t, returnSize);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static char ** letterCombinations(char * digits, int* returnSize){
    int digits_len = strlen(digits);
    char **ret = NULL;
    char *t = NULL;
    int size, i;
    
    assert(returnSize);
    *returnSize = 0;
    
    if (digits_len < 1){
        return ret;
    }

    size = 1;
    for (i = 0; i < digits_len; i++){
        int t = strlen(char_map[digits[i] - '0']);
        size *= t;
    }
    
    ret = (char **)calloc(size, sizeof(char *));
    assert(ret);
    t   = (char *)calloc(digits_len + 1, sizeof(char));
    assert(t);
    
    backTrack(digits, digits_len, 0, ret, t, returnSize);
    
    free(t);
    
    return ret;
}