/*
Problem: 3622. Check Divisibility by Digit Sum and Product
Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
*/

bool checkDivisibility(int n) {
    int val = n, sum = 0, product = 1;

    while (val) {
        int r = val % 10;

        sum += r;
        product *= r;

        val /= 10;
    }
    
    return (n % (sum + product) == 0);
}
