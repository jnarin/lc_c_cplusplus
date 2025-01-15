/*
Problem: 2429. Miniimize XOR
Link: https://leetcode.com/problems/minimize-xor/
*/


static int countSetBits(int n) {
    int c;

    for (c = 0; n; (n >>= 1)) {
        c += n & 1;
    }

    return c;
}

int minimizeXor(int num1, int num2) {
    int num2BitCount = countSetBits(num2), maxBits = 30, i, ans = 0;
    
    if (countSetBits(num1) == num2BitCount) {
        return num1;
    }

    for (i = maxBits; i >= 0; i--) {
        if (num1 >> i & 1) {
            ans |= 1 << i;

            num2BitCount--;
            if (num2BitCount == 0) {
                return ans;
            }
        }
    }

    for (i = 0; i < maxBits; i++) {
        if ((num1 >> i & 1) == 0) {
            ans |= 1 << i;

            num2BitCount--;
            if (num2BitCount == 0) {
                return ans;
            }
        }
    }

    return ans;
}
