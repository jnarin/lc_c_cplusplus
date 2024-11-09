/*
Problem: 3133. Minimum Array End
Link: https://leetcode.com/problems/minimum-array-end/
*/

long long minEnd(int n, int x) {
    long long ans = x;
    int i;
    
    n--;
    for (i = 0; i < 31; i++) {
        if (((x >> i) & 1) ^ 1) {
            ans |= (n & 1) << i;
            n >>= 1;
        }
    }
    
    ans |= (long long)n << 31;
    
    return ans;
}
