/*
Problem: 763. Partition Labels
Link: https://leetcode.com/problems/partition-labels/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int i, lastIndex[26] = {0}, len = strlen(s), idx = 0;

    for (i = 0; i < len; i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    int *result = calloc(len, sizeof(int));
    int size = 0, end = 0;

    for (i = 0; i < len; i++) {
        size++;
        end = MAXVAL(end, lastIndex[s[i] - 'a']);

        if (i == end) {
            result[idx++] = size;
            size = 0;
        }
    }
    
    *returnSize = idx;
    return result;
}
