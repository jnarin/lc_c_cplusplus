/*
Link: https://leetcode.com/problems/climbing-stairs/
Problem: 70. Climbing Stairs
*/

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    
    int i, a = 1, b = 2, ans;
    
    for (i = 2; i < n; i++) {
        ans = a + b;
        a = b;
        b = ans;
    }
    
    return ans;
}