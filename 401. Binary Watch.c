/*
Problem: 401. Binary Watch
Link: https://leetcode.com/problems/binary-watch/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int countSetBits(int n) {
    int c;
    
    for (c = 0; n; c++) {
        n &= n - 1;
    }

    return c;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** result = calloc(1024, sizeof(char *));
    int h, m;

    *returnSize = 0;

    for(h = 0; h < 12; h++) {
        for(m = 0; m < 60; m++) {
            if(countSetBits(h) + countSetBits(m) == turnedOn) {
                result[*returnSize] = calloc(6, sizeof(char));
                sprintf(result[*returnSize], "%d:%02d", h, m);
                (*returnSize)++;
            }
        }
    }
    
    return result;
}
