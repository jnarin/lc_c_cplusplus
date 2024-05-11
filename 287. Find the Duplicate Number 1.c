/*
Link: https://leetcode.com/problems/find-the-duplicate-number/
Problem: 287. Find the Duplicate Number
*/
int findDuplicate(int* nums, int numsSize){
    int i, t = numsSize << 1;
    
    for (i = 0; i < numsSize; i++){
        nums[nums[i] % numsSize] += numsSize;
    }
    
    for (i = 0; i < numsSize; i++){
        if (nums[i] >= t){
            return i;
        }
    }
    
    return INT_MAX;
}