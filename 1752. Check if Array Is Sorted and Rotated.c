/*
Problem: 1752. Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
*/

int incrCmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

bool check(int* nums, int numsSize){
    int sortedArray[numsSize];
    int i, j, tmp;

    memcpy(sortedArray, nums, numsSize * sizeof(int));
    qsort(sortedArray, numsSize, sizeof(int), incrCmp);
    
    for (i = 0; i < numsSize; i++){
        if (memcmp(nums, sortedArray, numsSize * sizeof(int)) == 0) {
            return true;
        }
        
        j = 0;
        tmp = sortedArray[j];
        
        for (j = 1; j < numsSize; j++){
            sortedArray[j - 1] = sortedArray[j];
        }
        
        sortedArray[numsSize - 1] = tmp;        
    }

    return false;
}
