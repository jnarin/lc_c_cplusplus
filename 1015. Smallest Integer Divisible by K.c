/*
Problem: 1015. Smallest Integer Divisible by K
Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/
*/

int smallestRepunitDivByK(int k) {
    int r = 0, n = 1;

    if (k & 1) {
        while (n <= k) {
            if ((r = (r * 10 + 1) % k) == 0) {
                return n;
            }

            n++;
        }
    }

    return -1;   
}
