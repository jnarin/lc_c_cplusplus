/*
 * Link: https://leetcode.com/problems/powx-n/
 * Problem: 50. Pow(x, n)
 * */

double myPow(double x, int n){
    long t = n;
    if (n < 0){
        x = 1/x;
        t = labs(t);
    }
    
    if (t == 0){
        return 1;
    }
    
    if ((t & 1) == 0){
        double d = myPow(x, t >> 1);
        return d * d;
    }
    
    return x * myPow(x, t - 1);
}
