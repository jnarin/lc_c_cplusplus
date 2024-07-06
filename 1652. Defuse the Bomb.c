/*
 * Problem: 1652. Defuse the Bomb
 * Link: https://leetcode.com/problems/defuse-the-bomb/
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int *ans = calloc(codeSize, sizeof(int));
    *returnSize = codeSize;

    if (k != 0) {
        int sum = 0, i;
        int start = k > 0 ? 1 : codeSize + k;
        int end = k > 0 ? k : codeSize - 1;

        for (i = start; i <= end; i++) {
            sum += code[i];
        }

        for (i = 0; i < codeSize; i++) {
            ans[i] = sum;
            sum -= code[start % codeSize];
            start++;

            end++;
            sum += code[end % codeSize];
        }

        return ans;
    }

    return ans;
}
