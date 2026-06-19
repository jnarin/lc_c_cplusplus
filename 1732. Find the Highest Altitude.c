/*
Link: https://leetcode.com/problems/find-the-highest-altitude/
Problem: 1732. Find the Highest Altitude
*/

int largestAltitude(int* gain, int gainSize) {
    int g = 0, i, ans = 0;

    for (i = 0; i < gainSize; i++) {
        g += gain[i];
        ans = g > ans ? g : ans;
    }
    
    return ans;
}
