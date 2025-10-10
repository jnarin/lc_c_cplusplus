/*
Problem: 3147. Taking Maximum Energy From the Mystic Dungeon
Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
*/

int maximumEnergy(int* energy, int energySize, int k) {
    int dp[energySize], i;

    memcpy(dp, energy, sizeof(int) * energySize);

    for (i = energySize - 1 - k; i >= 0; i--) {
        dp[i] += dp[i + k];
    }

    int max = dp[0];
    for (i = 1; i < energySize; i++) {
        max = (dp[i] > max) ? dp[i] : max;
    }

    return max;
}
