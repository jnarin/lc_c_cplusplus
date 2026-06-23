/*
Problem: 3699. Number of ZigZag Arrays I
Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/
*/

static void reverse(int *arr, int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

static long arraySum(int *arr, int size) {
    long sum = 0, i;

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int zigZagArrays(int n, int l, int r) {
    const int MOD = 1e9 + 7;
    int m = r - l + 1;
    int dp[m], i, j, sum, t;

    for (i = 0; i < m; i++) {
        dp[i] = 1;
    }

    for (i = 2; i <= n; i++){
        reverse(dp, m);
        sum = 0;
        
        for (j = 0; j < m; j++) {
            t = sum;
            sum = (sum + dp[j]) % MOD;
            dp[j] = t;
        }
    }

    return ((arraySum(dp, m) % MOD) << 1) % MOD;
}
