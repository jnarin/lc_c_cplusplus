/*
Problem: 1200. Minimum Absolute Difference
Link: https://leetcode.com/problems/minimum-absolute-difference/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    int **ans = calloc(arrSize, sizeof(int *)), i;
    *returnColumnSizes = calloc(arrSize, sizeof(int));

    for (i = 0; i < arrSize; i++) {
        ans[i] = calloc(2, sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    if (arrSize < 2) {
        return ans;
    }

    qsort(arr, arrSize, sizeof(int), incrCmp);

    int minDiff = INT_MAX;

    for (int i = 0; i < arrSize - 1; i++){
        minDiff = MINVAL(arr[i + 1] - arr[i], minDiff);
    }

    int idx = 0;
	for (i = 0; i < arrSize - 1; i++){
        if (arr[i + 1] - arr[i] == minDiff){
            ans[idx][0] = arr[i];
            ans[idx][1] = arr[i + 1];
            idx++;
        }
    }
    
    *returnSize = idx;

    return ans;
    
}
