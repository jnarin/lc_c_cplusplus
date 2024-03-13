/*
Link: https://leetcode.com/problems/find-the-pivot-integer/
Problem: 2485. Find the Pivot Integer
*/

int pivotInteger(int n) {
    int i, ans = -1, t = (n * (n + 1)) >> 1;
    
    for (i = 1; i <= n; i++) {
        int a = (i * (i + 1)) >> 1;
        int b = t - a + i;
        
        if (a == b) {
            ans = i;
            break;
        }
    }
    
    return ans;
}