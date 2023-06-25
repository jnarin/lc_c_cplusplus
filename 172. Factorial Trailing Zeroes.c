/*
 * Link: https://leetcode.com/problems/factorial-trailing-zeroes/
 * Problem: 172. Factorial Trailing Zeroes
 * */

int trailingZeroes(int n){
    int ans = 0;

    while (n){
        n = n / 5;
        ans += n;
    }

    return ans;
}

