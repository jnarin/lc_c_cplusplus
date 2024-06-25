/*
Problem: 330. Patching Array
Link: https://leetcode.com/problems/patching-array/
*/



int minPatches(int* nums, int numsSize, int n){
    long x = 1;
    int ans = 0;
    int i = 0;
    
    while (x <= n){
        if (i < numsSize && nums[i] <= x){
            x += nums[i];
            i++;
        } else {
            x += x;
            ans++;
        }
    }
    
    return ans;
}