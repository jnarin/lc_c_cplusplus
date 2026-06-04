/*
Problem: 3751. Total Waviness of Numbers in Range I
Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
*/

static int numberWaviness(int n) {
    int nums[32] = {0}, idx = 0;

    while (n) {
        nums[idx++] = n % 10;
        n /= 10;
    }

    if (idx < 3) {
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < idx - 1; i++) {
        ans += nums[i] > nums[i - 1] && nums[i] > nums[i + 1]; // Peak
        ans += nums[i] < nums[i - 1] && nums[i] < nums[i + 1]; // Valley
    }

    return ans;
}

int totalWaviness(int num1, int num2) {
    int ans = 0;

    for (int i = num1; i <= num2; i++) {
        ans += numberWaviness(i);
    }

    return ans;
}
