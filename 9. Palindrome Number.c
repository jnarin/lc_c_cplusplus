/*
Problem: 9. Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/
*/

bool isPalindrome(int x) {

    if (x < 0) {
        return false;
    }
    
    int rev = 0;
    int y = x;
    
    while (y){
        int t = y % 10;
        if (rev >= INT_MAX / 10){
            return false;
        }
        
        rev = (rev * 10) + t;
        y /= 10;
    }
            
    return rev == x;
}
