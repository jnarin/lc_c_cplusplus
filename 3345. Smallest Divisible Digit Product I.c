/*
Problem: 3345. Smallest Divisible Digit Product I
Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/
*/

int smallestNumber(int n, int t) {
    int ans = n;

    while (1) {
        int product = 1;
        int temp = ans;

        while (temp > 0) {
            product *= (temp % 10);
            temp /= 10;
        }

        if (product % t == 0) {
            return ans;
        }

        ans++;
    }
    
    return -1;
}
