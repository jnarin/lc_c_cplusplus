/*
Link: https://leetcode.com/problems/binary-search/
Problem: 704. Binary Search
*/

#define MID(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid;
    while (left <= right){
        mid = MID(left, right);
        
        if (nums[mid] == target){
            return mid;
        }
        
        if (nums[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
