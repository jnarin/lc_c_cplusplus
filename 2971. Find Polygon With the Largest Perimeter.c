/*
Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
Problem: 2971. Find Polygon With the Largest Perimeter
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static long long sumArray(int *array, int size) {
    long long sum = 0;
    int i;
    
    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    
    return sum;
}

long long largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), incrCmp);
    
    int i;
    
    long long p = sumArray(nums, numsSize), l;
    
    for (i = numsSize - 1; i >= 0; i--) {
        l = p - nums[i];
        
        p = l <= nums[i] ? p - nums[i] : p;
    }
    
    return p != 0 ? p : -1;
    
}