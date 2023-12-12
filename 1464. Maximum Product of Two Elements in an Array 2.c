/*
Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Problem: 1464. Maximum Product of Two Elements in an Array


Keep track of the two max elements in the array
Time Complexity: O(n), Space Complexity: O(1)
*/

int maxProduct(int* nums, int numsSize) {
    int t[2] = {INT_MIN, INT_MIN}, i;
    
    for (i = 0; i < numsSize; i++){
        if (nums[i] > t[0]){
            t[1] = t[0];
            t[0] = nums[i];
        } else if (nums[i] > t[1]){
            t[1] = nums[i];
        }
    }
    
    return (t[0] - 1) * (t[1] - 1);    
}