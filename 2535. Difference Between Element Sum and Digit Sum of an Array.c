/*
Problem: 2535. Difference Between Element Sum and Digit Sum of an Array
Link: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
*/

int differenceOfSum(int* nums, int numsSize) {
    int elementSum = 0, digitSum = 0, i, n;
    
    for (i = 0; i < numsSize; i++) {
        n = nums[i];
        elementSum += n;
        
        while (n) {
            digitSum += n % 10;
            n /= 10;
        }
    }
    
    return abs(elementSum - digitSum);    
}
