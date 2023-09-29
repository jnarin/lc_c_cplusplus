/*
Link: https://leetcode.com/problems/monotonic-array/
Problem: 896. Monotonic Array
*/
bool isMonotonic(int* nums, int numsSize){
    bool ans = true, increasing;
    int i;
    
    if (numsSize < 2){
        return ans;
    }
    
    for (i = 1; i < numsSize; i++){
        if (nums[i - 1] != nums[i]){
            break;
        }
    }
    
    if (i >= numsSize){
        return true;
    }
    
    increasing = nums[i - 1] < nums[i];
    
    if (increasing){
        for (; i < numsSize; i++){
            if (nums[i - 1] > nums[i]){
                ans = false;
                break;
            }
        }
    } else {
        for (; i < numsSize; i++){
            if (nums[i - 1] < nums[i]){
                ans = false;
                break;
            }
        }
    }
    
    return ans;
}