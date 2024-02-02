/*
Link: https://leetcode.com/problems/sequential-digits/
Problem: 1291. Sequential Digits
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM_RANGE   (40)

static int countDigits(int n) {
    int ans;
    
    for (ans = 0; n; ans++) {
        n /= 10;
    }
    
    return ans;
}

int* sequentialDigits(int low, int high, int* returnSize) {
    int *ans = calloc(MAX_NUM_RANGE, sizeof(int)), ansIdx = 0;
    int i, j;
    int nLow = countDigits(low), nHigh = countDigits(high);
    const char *digits = "123456789";
    
    for (i = nLow; i <= nHigh; i++) {
        for (j = 0; j < (10 - i); j++) {
            char t[10] = {0}, *p = t;
            int k;
            
            for (k = j; k < j + i; k++) {
                *p++ = digits[k];
            }
            
            int n = atoi(t);
            
            if (n >= low && n <= high) {
                ans[ansIdx++] = n;
            }
        }
    }

    
    *returnSize = ansIdx;
    
    return ans;   
}