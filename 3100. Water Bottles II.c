/*
Problem: 3100. Water Bottles II
Link: https://leetcode.com/problems/water-bottles-ii/
*/

int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = numBottles;

    while (numBottles >= numExchange) {
        numBottles = (numBottles - numExchange + 1);
        numExchange++;
        ans++;
    }

    return ans;    
}
