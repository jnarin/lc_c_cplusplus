/*
Problem: 2570. Merge Two 2D Arrays by Summing Values
Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAXNUM (1001)

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAXNUM (1001)

int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {
    int map[MAXNUM] = {0}, i, numElements = 0;

    for (i = 0; i < nums1Size; i++) {
        numElements += map[nums1[i][0]] == 0;
        map[nums1[i][0]] += nums1[i][1];
    }

    for (i = 0; i < nums2Size; i++) {
        numElements += map[nums2[i][0]] == 0;
        map[nums2[i][0]] += nums2[i][1];
    }
    
    int **ans = calloc(numElements, sizeof(int *)), idx = 0;
    *returnSize = numElements;
    *returnColumnSizes = calloc(numElements, sizeof(int));

    for (i = 0; i < numElements; i++) {
        ans[i] = calloc(2, sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    for (i = 0; i < MAXNUM; i++) {
        if (map[i]) {
            ans[idx][0] = i;
            ans[idx][1] = map[i];
            idx++;
        }
    }

    return ans;
}
