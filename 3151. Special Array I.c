/*
Problem: 3151. Special Array I
Link: https://leetcode.com/problems/special-array-i/
*/

bool isArraySpecial(int* nums, int numsSize) {
    int i;
    
    for (i = 1; i < numsSize; i++) {
        if ((nums[i - 1] & 1) == (nums[i] & 1)) {
            return false;
        }
    }
    
    return true;
}
