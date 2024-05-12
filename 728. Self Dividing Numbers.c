/*
 * Problem: 728. Self Dividing Numbers
 * Link: https://leetcode.com/problems/self-dividing-numbers/
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_OUT (350)

static int checkNum(int n) {
    int t = n, d;

    while (t) {
        d = t % 10;

        if (d == 0) {
            return false;
        }

        if (n % d) {
            return false;
        }

        t /= 10;
    }

    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int *ans = calloc(MAX_OUT, sizeof(int)), idx = 0, i;

    for (i = left; i <= right; i++) {
        if (checkNum(i)) {
            ans[idx++] = i;
        }
    }

    *returnSize = idx;

    return ans;
}
