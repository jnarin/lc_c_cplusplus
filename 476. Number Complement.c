/*
Problem: 476. Number Complement
Link: https://leetcode.com/problems/number-complement/
*/

int findComplement(int num) {
    int ans = 0, pos = 0;
    
    while (num) {
        if ((num & 1) == 0) {
            ans |= 1 << pos;
        }
        
        num >>= 1;
        pos++;
    }
    
    return ans;
}
