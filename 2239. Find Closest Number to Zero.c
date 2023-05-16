/*
Link: https://leetcode.com/problems/find-closest-number-to-zero/
Problem: 2239. Find Closest Number to Zero
*/

int findClosestNumber(int* nums, int numsSize){
    int idx = 0, diff = INT_MAX, i, t;
    
    for (i = 0; i < numsSize; i++){
        t = abs(nums[i]);
        if (t < diff){
            idx = i;
            diff = t;
        } else if (t == diff && nums[i] > 0 && nums[idx] < 0){
            idx = i;
        }
    }

    return nums[idx];
}