/*
 * Link:https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * Problem: 81. Search in Rotated Sorted Array II
 * */

#define MIDVAL(a, b)    (((a) & (b)) + (((a) ^ (b)) >> 1))

bool search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, m;

    while (l <= r){
        m = MIDVAL(l, r);

        if (target == nums[m]){
            return true;
        }

        if (nums[l] == nums[m] && nums[m] == nums[r]){
            l++;
            r--;
        } else if (nums[l] <= nums[m]){
            if (nums[l] <= target && nums[m] > target){
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (nums[m] < target && nums[r] >= target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    return false;
}
