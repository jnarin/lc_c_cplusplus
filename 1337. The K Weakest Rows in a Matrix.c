/*
 * Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * Problem: 1337. The K Weakest Rows in a Matrix
 * */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct INT_PAIR_t{
    int row, sum;
}INT_PAIR;

static int arraySum(int *array, int arraySize){
    int sum = 0, i;

    for (i = 0; i < arraySize; i++){
        sum += array[i];
    }

    return sum;
}

static int pair_cmp_fn(const void *a, const void *b){
    INT_PAIR    *x = (INT_PAIR *)a,
                *y = (INT_PAIR *)b;
    return  x->sum != y->sum
            ? x->sum - y->sum
            : x->row - y->row;
}
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *ans = calloc(k, sizeof(int)), i, j, x;
    *returnSize = k;

    INT_PAIR t[matSize];
    memset(t, 0, sizeof(t));

    for (i = 0; i < matSize; i++){
        x = arraySum(mat[i], matColSize[i]);
        t[i].row = i;
        t[i].sum = x;
    }

    qsort(t, matSize, sizeof(INT_PAIR), pair_cmp_fn);

    for (i = 0; i < k; i++){
        ans[i] = t[i].row;
    }

    return ans;
}
