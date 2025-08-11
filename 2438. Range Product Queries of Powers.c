/*
Problem: 2438. Range Product Queries of Powers
Link: https://leetcode.com/problems/range-product-queries-of-powers/
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* result = (int *)calloc(queriesSize, sizeof(int)), mod = (int)(1e9 + 7), powers[32], count = 0;
    int i, j;
    long long product;

    for (i = 0; i < 32; i++) {
        if (n & ((unsigned int)1 << i)) {
            powers[count++] = (1 << i) % mod;
        }
    }

    for (i = 0; i < queriesSize; i++) {
        product = 1;
        for (j = queries[i][0]; j <= queries[i][1]; j++) {
            product = (product * powers[j]) % mod;
        }

        result[i] = (int)product;
    }

    *returnSize = queriesSize;

    return result;
}
