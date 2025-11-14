/*
Problems: 2536. Increment Submatrices by One
Link: https://leetcode.com/problems/increment-submatrices-by-one/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
    int **ans, prefix[n][n + 1],
        i, j, sum;

    memset(prefix, 0, sizeof(prefix));
    ans = calloc(n, sizeof(int *));
    *returnSize = n;
    *returnColumnSizes = calloc(n, sizeof(int));

    for (i = 0; i < n; i++) {
        ans[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    for (i = 0; i < queriesSize; i++) {
        for (j = queries[i][0]; j <= queries[i][2]; j++) {
            prefix[j][queries[i][1]]++;
            prefix[j][queries[i][3] + 1]--;
        }
    }

    for (i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += prefix[i][j];
            ans[i][j] = sum;
        }
    }
    
    return ans;
}
