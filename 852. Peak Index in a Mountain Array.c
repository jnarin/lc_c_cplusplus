/*
Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
Problem: 852. Peak Index in a Mountain Array
*/
#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

int peakIndexInMountainArray(int* arr, int arrSize){
    int l = 0, r = arrSize - 1, m;
    
    while (l < r){
        m = MIDVAL(l, r);
        if (arr[m] >= arr[m + 1]){
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    return l;

}