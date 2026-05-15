/*
Problem: 153. Find Minimum in Rotated Sorted Array
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

int findMin(int* nums, int numsSize) {
    int ret = nums[0];
    int l, r, m;

    l = 0;
    r = numsSize;
    
    while (l < r){
        m = (l & r) + ((l ^ r) >> 1);
        if (ret > nums[m]){
            ret = nums[m];
            r = m;
        } else {
            l = m+1;
        }
    }

    return ret;    
    
}
