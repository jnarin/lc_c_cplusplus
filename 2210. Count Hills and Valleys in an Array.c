/*
Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
Problem: 2210. Count Hills and Valleys in an Array
*/
int countHillValley(int* nums, int numsSize){
    int ans = 0, l = nums[0], i;
    
    for (i = 1; i < numsSize - 1; i++){
        if ((l < nums[i] && nums[i] > nums[i + 1])
            || (l > nums[i] && nums[i] < nums[i + 1])){
            ans++;
            l = nums[i];
        }
    }
    
    return ans;
}