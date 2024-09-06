/*
Problem: 2778. Sum of Squares of Special Elements
Link: https://leetcode.com/problems/sum-of-squares-of-special-elements/
*/

int sumOfSquares(int* nums, int numsSize){
    int ans = 0, i;
    
    for (i = 0; i < numsSize; i++) {
        ans += numsSize % (i + 1) == 0 ? nums[i] * nums[i] : 0;
    }

    return ans;
}
