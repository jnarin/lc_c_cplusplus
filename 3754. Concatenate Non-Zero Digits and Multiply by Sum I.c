/*
Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I
Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i
*/
long long reverse(long long n) {
    long long ans = 0;

    while (n) {
        ans = (ans * 10) + (n % 10);
        n /= 10;
    }

    return ans;
}


long long sumAndMultiply(int n) {
    long long x = 0, sum = 0;

    while (n) {
        int t = n % 10;
        if (t) {
            x = (x * 10) + t;
            sum += t;
        }
        
        n /= 10;
    }

    return reverse(x) * sum;
}
