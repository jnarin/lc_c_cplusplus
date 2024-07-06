/*
 * Problem: 2443. Sum of Number and Its Reverse
 * Link: https://leetcode.com/problems/sum-of-number-and-its-reverse/
 * */

static int getReverse(int num) {
    int reverse = 0;

    while (num) {
        reverse = (reverse * 10) + (num % 10);
        num /= 10;
    }

    return reverse;
}

bool sumOfNumberAndReverse(int num) {
    int i;

    if (num == 0) {
        return true;
    }

    for (i = 0; i < num; i++) {
        int reverse = getReverse(i);
        if (i + reverse == num) {
            return true;
        }
    }

    return false;
}
