/*
Link: https://leetcode.com/problems/fibonacci-number/
Problem: 509. Fibonacci Number
*/


/*
Ref. https://codeconfessions.substack.com/p/a-linear-algebra-trick-for-fibonacci-numbers 
which in turn references he Art of Computer Programming, Volume 1 (page 79)
Time and Space complexity: O(1)
*/

int fib(int n){
    float   sqrRoot5 = sqrt(5),
            invSqrRoot5 = 1/sqrRoot5,
            x = (1 + sqrRoot5) / 2,
            y = (1 - sqrRoot5) / 2;
    
    return (int)(invSqrRoot5 * (pow(x, n) - pow(y, n)));
}