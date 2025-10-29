/*
Problem: 3370. Smallest Number With All Set Bits
Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/
*/

int smallestNumber(int n) {
    int t = 1;

    while (t <= n) {
        t <<= 1;
    }
    
    return t - 1;
}
