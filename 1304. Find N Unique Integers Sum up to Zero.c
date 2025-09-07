/*
Problem: 1304. Find N Unique Integers Sum up to Zero
Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    int *ans = calloc(n, sizeof(int)), idx = 0, i = 0;
    *returnSize = n;

    if (n & 1) {
        ans[idx++] = i;
    }

    i++;

    while (idx < n) {
        ans[idx++] = i;
        ans[idx++] = -i;
        i++;
    }

    return ans;    
}
