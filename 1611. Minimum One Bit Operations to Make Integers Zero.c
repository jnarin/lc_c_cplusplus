/*
Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
Problem: 1611. Minimum One Bit Operations to Make Integers Zero
*/

int minimumOneBitOperations(int n) {
    if (n <= 1){
        return n;
    }
    
    int bit = 0;
    while ((1 << bit) <= n){
        bit++;
    }
    
    bit--;
    
    return ((1 << bit + 1) - 1) - minimumOneBitOperations(n - (1 << bit));     
}
