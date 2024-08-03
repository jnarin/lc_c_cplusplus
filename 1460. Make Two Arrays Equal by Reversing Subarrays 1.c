/*
Problem: 1460. Make Two Arrays Equal by Reversing Subarrays
Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    if (targetSize == arrSize) {
        qsort(target, targetSize, sizeof(int), incrCmp);
        qsort(arr, arrSize, sizeof(int), incrCmp);
        
        if (memcmp(arr, target, sizeof(int) * arrSize) == 0) {
            return true;
        }
    }
    
    return false;
}
