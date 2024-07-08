/*
Problem: 3099. Harshad Number
Link: https://leetcode.com/problems/harshad-number/
*/

int sumOfTheDigitsOfHarshadNumber(int x) {
    int n = x, sum = 0;
    
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    
    return x % sum == 0 ? sum : -1;   
}