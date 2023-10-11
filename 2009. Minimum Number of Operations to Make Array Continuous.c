/*
Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
Problem: 2009. Minimum Number of Operations to Make Array Continuous
*/

#define DEBUG 0
#define debug_print(fmt, ...) \
            do { if (DEBUG) printf(fmt, __VA_ARGS__); } while (0)

#define MINVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}


/* Sorted array of ints as input, replaces duplicate elements
and returns new size */
static void removeDuplicates(int *nums, int numsSize, int *returnSize){
    if (numsSize < 2){
        *returnSize = numsSize;
        return;
    }
    
    int tmp[numsSize], i, idx = 0;
    tmp[idx++] = nums[0];
    
    for (i = 1; i < numsSize; i++){
        if (tmp[idx - 1] == nums[i]){
            continue;
        }
        
        tmp[idx++] = nums[i];
    }
    
    
    memcpy(&nums[0], &tmp[0], idx * sizeof(int));
    
    *returnSize = idx;
    
    return;
}

/* Returns index of the first element greater than target, 
numsSize otherwise */
static int upperBound(int *nums, int numsSize, int target){
    /* Implemented binary search instead of sequential search 
    since array is sorted - duh! */
    int l = 0, r = numsSize - 1, m;
    
    while (l < r){
        m = (l & r) + ((l ^ r) >> 1);
        
        if (target >= nums[m]){
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    if (l < numsSize && nums[l] <= target){
        l++;
    }
    
    return l;
}


static void printArray(char *s, int *nums, int numsSize){
    #ifdef DEBUG
    debug_print("%s\t[ ", s);
    int i;
    
    for (i = 0; i < numsSize; i++){
        debug_print("%d ", nums[i]);
    }
    
    debug_print("%s", "]\n");
    #endif
}


int minOperations(int* nums, int numsSize){
    int newLen = 0, ans = numsSize, i, start, end, idx, uniqueLen;
    
    qsort(nums, numsSize, sizeof(int), incrCmp);
    printArray("Sorted Array", nums, numsSize);
    
    removeDuplicates(nums, numsSize, &newLen);
    printArray("Deduplicated Array", nums, newLen);
    
    for (i = 0; i < newLen; i++){
        start = nums[i];
        end = start + numsSize - 1;
        debug_print("start [%d] end [%d]\n", start, end);
        idx = upperBound(nums, newLen, end);
        debug_print("i [%d] idx [%d]\n", i, idx);
        uniqueLen = idx - i;
        ans = MINVAL(ans, numsSize - uniqueLen);
    }
    
    return ans;
}
