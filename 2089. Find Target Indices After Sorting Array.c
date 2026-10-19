/* 
Problem: 2089. Find Target Indices After Sorting Array
Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), incrCmp);

    int count = 0, i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            count++;
        }
    }

    *returnSize = count;
    int* result = calloc(count, sizeof(int));
    int index = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            result[index++] = i;
        }
    }

    return result;
}
