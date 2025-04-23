/*
Problem: 1399. Count Largest Group
Link: https://leetcode.com/problems/count-largest-group/
*/

int countLargestGroup(int n) {
    int i, sum, num, maxCount = 0, ans = 0, count[37] = {0}; // 9 * 4 = 36, max digit sum for n <= 10^4

    for (i = 1; i <= n; i++) {
        sum = 0;
        num = i;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        count[sum]++;

        if (count[sum] > maxCount) {
            maxCount = count[sum];
            ans = 1;
        } else if (count[sum] == maxCount) {
            ans++;
        }
    }

    return ans;
}
