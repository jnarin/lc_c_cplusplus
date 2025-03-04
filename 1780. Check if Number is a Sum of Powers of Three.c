/*
Problem: 1780. Check if Number is a Sum of Powers of Three
Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
*/

bool checkPowersOfThree(int n) {
    int r;

    while (n > 1) {
        r = n % 3;
        if (r == 2) {
            return false;
        }

        n /= 3;
    }
    
    return true;
}
