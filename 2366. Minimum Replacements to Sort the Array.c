/*
Link: https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
Problem: 2366. Minimum Replacements to Sort the Array
*/
long long minimumReplacement(int* nums, int numsSize){
    long long ans = 0;
    int maxNum = nums[numsSize - 1], i, t;
    
    for (i = numsSize - 2; i >=0; i--){
        t = (nums[i] - 1) / maxNum;
        ans += t;
        maxNum = nums[i] / (t + 1);
    }

    return ans;
}