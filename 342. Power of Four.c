/*
Link: https://leetcode.com/problems/power-of-four/
Problem: 342. Power of Four
*/
bool isPowerOfFour(int n){
    return (n > 0) && ((n & (n - 1)) == 0) && ((n % 3) == 1);
}