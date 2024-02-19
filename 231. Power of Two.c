/*
Link: https://leetcode.com/problems/power-of-two/
Problem: 231. Power of Two
*/

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;    
}