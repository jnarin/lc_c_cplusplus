/*
Link: 1356. Sort Integers by The Number of 1 Bits
Problem: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int countBits(int n){
    int c;
    
    for (c = 0; n; c++){
        n &= n - 1;
    }
    
    return c;
}

static int cmpBitCount(const void *a, const void *b){
    int bitCountA = countBits(*(int *)a), bitCountB = countBits(*(int *)b);
    
    return (bitCountA != bitCountB) ? bitCountA - bitCountB : *(int *)a - *(int *)b;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    qsort(arr, arrSize, sizeof(int), cmpBitCount);
    
    *returnSize = arrSize;
    return arr;
}