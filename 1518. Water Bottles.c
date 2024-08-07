/*
 * Problem: 1518. Water Bottles
 * Link: https://leetcode.com/problems/water-bottles/
 * */

int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;

    while (numBottles >= numExchange) {
        ans += numBottles / numExchange ;
        numBottles = (numBottles / numExchange) + (numBottles % numExchange);
    }

    return ans;
}
