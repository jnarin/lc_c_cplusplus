/*
Problem: 3783. Mirror Distance of an Integer
Link: https://leetcode.com/problems/mirror-distance-of-an-integer/
*/

static int reverseNum(int n) {
    int reverse = 0;

    while (n) {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }

    return reverse;
}

int mirrorDistance(int n) {
    return abs(reverseNum(n) - n);
}
