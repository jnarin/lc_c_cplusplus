/*
Problem: 3356. Zero Array Transformation II
Link: https://leetcode.com/problems/zero-array-transformation-ii/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int minZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int line[numsSize + 1], decrement = 0, k = 0, i = 0, l, r, val;
    memset(line, 0, sizeof(line));

    for (i = 0; i < numsSize; i++) {
        while (decrement + line[i] < nums[i]) {
            if (k == queriesSize) {
                return -1;
            }

            l = queries[k][0];
            r = queries[k][1];
            val = queries[k][2];

            k++;

            if (r < i) {
                continue;
            }

            line[MAXVAL(l, i)] += val;
            line[r + 1] -= val;
        }

        decrement += line[i];
    }

    return k;    
}
