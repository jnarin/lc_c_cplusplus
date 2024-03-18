/*
Link: https://leetcode.com/problems/contiguous-array/
Problem: 525. Contiguous Array
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int findMaxLength(int* nums, int numsSize) {
    int i, maxLen, count, arrayLen = (numsSize << 1) + 1, array[arrayLen];
    
    for (i = 0; i < arrayLen; i++) {
        array[i] = -2;
    }
    
    array[numsSize] = -1;
    
    maxLen = count = 0;
    
    for (i = 0; i < numsSize; i++) {
        count += nums[i] ? 1 : -1;
        
        if (array[count + numsSize] >= -1) {
            maxLen = MAXVAL(maxLen, i - array[count + numsSize]);
        } else {
            array[count + numsSize] = i;
        }
    }
    
    return maxLen;    
}