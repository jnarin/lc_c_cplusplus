/*
Problem: 1009. Complement of Base 10 Integer
Link: https://leetcode.com/problems/complement-of-base-10-integer/
*/

int bitwiseComplement(int n) {
    if (n == 0) {
        return 1;
    }
    

    int mask = 1;
    while (mask <= n) {
        mask <<= 1;
    }
    
    return (mask - 1) - n;
    
}
