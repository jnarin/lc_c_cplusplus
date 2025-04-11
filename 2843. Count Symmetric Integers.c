/*
Problem: 2843. Count Symmetric Integers
Link: https://leetcode.com/problems/count-symmetric-integers/
*/

#define MAX_DIGITS  (10000)

static bool checkSymmetricNum(char *num, int len) {
    if (len & 1) {
        return false;
    }

    int i, mid = len >> 1, a = 0, b = 0;

    for (i = 0; i < mid; i++) {
        a += num[i] - '0';
        b += num[i + mid] - '0';
    }

    return a == b;
}

int countSymmetricIntegers(int low, int high){
    char num[MAX_DIGITS + 1] = {0};
    int len, i, ans = 0;

    for (i = low; i <= high; i++) {
        snprintf(num, MAX_DIGITS, "%d", i);
        len = strlen(num);

        if (checkSymmetricNum(num, len)) {
            ans++;
        }
    }

    return ans;
}
