/*
Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
Problem: 1846. Maximum Element After Decreasing and Rearranging
*/

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    int i;
    
    qsort(arr, arrSize, sizeof(int), incrCmp);
    arr[0] = 1;
    
    for (i = 1; i < arrSize; i++){
        arr[i] = MINVAL(arr[i], arr[i - 1] + 1);
    }
    
    return arr[arrSize - 1];    
}