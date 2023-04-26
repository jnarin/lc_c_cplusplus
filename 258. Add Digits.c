/*
Link: https://leetcode.com/problems/add-digits/
Problem: 258. Add Digits
*/

int addDigits(int num){
    
    if (num == 0) {
        return num;
    }
    
    int t = num % 9;
    
    return t == 0 ? 9 : t;
}