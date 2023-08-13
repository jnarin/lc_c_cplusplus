/*
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Problem: 33. Search in Rotated Sorted Array
 * */



int search(int* nums, int numsSize, int target){
    int l, r, m;

    l = 0;
    r = numsSize - 1;
    while (l <= r){
        m = (l & r) + ((l ^ r) >> 1);

        if (nums[m] == target){
            return m;
        }

        if (nums[m] >= nums[l]){
            if (target <= nums[m] && target >= nums[l]){
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (target >= nums[m] && target <= nums[r]){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    return -1;
}
