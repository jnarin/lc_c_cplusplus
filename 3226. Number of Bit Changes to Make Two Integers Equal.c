/*
Problem: 3226. Number of Bit Changes to Make Two Integers Equal
Link: https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/
*/

int minChanges(int n, int k) {
    int ans = 0;
    
    while (n || k) {
        if ((n & 1) == 0 && (k & 1) == 1) {
            return -1;
        }
        
        if ((n & 1) == 1 && (k & 1) == 0) {
            ans++;
        }
        
        n >>= 1;
        k >>= 1;
    }
    
    return ans;
}
