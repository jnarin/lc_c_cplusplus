/*
Link: https://leetcode.com/problems/reverse-integer/
Problem: 7. Reverse Integer
Approach:
If input value is INT_MIN, it cannot be processed further (removing sign will cause integer overflow) - return error
Check sign and store sign, convert the value to positive 
Extract value in one's position, multiply previous reversed value by 10 and add value in one's position
Remove value in one's position
Apply sign
*/
int reverse(int x){
    
    bool sign;
    
    if (x == INT_MIN){
        return 0;
    }
    
    sign = x < 0 ? true : false;
    x = sign ? x * -1 : x;
    
    int r = 0;
    
    while (x){
        if (r > INT_MAX/10){
            return 0;
        }
        
        r = (r * 10) + (x % 10);
        x /= 10;
    }
    
    return sign ? r * -1 : r;
    

}