/*
Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/
Problem: 1822. Sign of the Product of an Array
*/

int arraySign(int* nums, int numsSize){
    int i, ans = 1;
    
    for (i = 0; i < numsSize; i++){
        if (nums[i] == 0){
            return 0;
        }
        
        ans *= nums[i] > 0 ? 1 : -1;
    }
    
    return ans;
}