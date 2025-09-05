/*
Problem: 2749. Minimum Operations to Make the Integer Zero
Link: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
*/


static int countBits(long n) {
    int ans;

    for (ans = 0; n; ans++) {
        n &= (n - 1);
    }
    
    return ans;
}

int makeTheIntegerZero(int num1, int num2) {
    for (long ops = 0; ops <= 60; ops++) {
        long val = num1 - ops * num2;

        if (val < 0) {
            break;
        }

        if (countBits(val) <= ops && ops <= val) {
            return (int)ops;
        }
    }

    return -1;
}
