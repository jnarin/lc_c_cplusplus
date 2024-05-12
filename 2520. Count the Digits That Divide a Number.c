/*
 * Problem: 2520. Count the Digits That Divide a Number
 * Link: https://leetcode.com/problems/count-the-digits-that-divide-a-number/
 * */

int countDigits(int num) {
    int ans = 0, t = num, d;

    while (t) {
        d = t % 10;

        if (d) {
            ans = num % d ? ans : ans + 1;
        }

        t /= 10;
    }

    return ans;
}
