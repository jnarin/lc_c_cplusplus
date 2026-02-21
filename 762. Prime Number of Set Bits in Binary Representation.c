/*
Problem: 762. Prime Number of Set Bits in Binary Representation
Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
*/

static int countSetBits(int n) {
    int c;

    for (c = 0; n; c++) {
        n &= n - 1;
    }

    return c;
}

static int isPrime(int n) {
    int i;

    if (n == 2) {
        return 1;
    }

    if (n <= 1 || (n & 1) == 0) {
        return 0;
    }

    for (i = 3; i * i <= n; i++) {
        if ((n % i) == 0) {
            return 0;
        }
    }

    return 1;
} 

int countPrimeSetBits(int left, int right) {
    int ans = 0, i, setBits;

    for (i = left; i <= right; i++) {
        ans += isPrime(countSetBits(i));
    }
    
    return ans;
}
