/*
Link: https://leetcode.com/problems/sum-of-square-numbers/
Problem: 633. Sum of Square Numbers
*/
bool judgeSquareSum(int c){
    unsigned int a, b, t;
    
    a = 0;
    b = sqrt(c);
    
    while (a <= b){
        t = (a * a) + (b * b);
        
        if (c == t){
            return true;
        }
        
        if (t > c){
            b--;
        } else {
            a++;
        }
    }
    
    return false;
}