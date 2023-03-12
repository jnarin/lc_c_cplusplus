/*
Link: https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/
Problem: 2481. Minimum Cuts to Divide a Circle
Approach:
If n == 1, number of cuts is 0 - the entire circle by itself satisfies the condition
If n is even, (n / 2) cuts are needed
If n is odd, n cuts are needed
*/

int numberOfCuts(int n){
    return (n & 1) ? ((n != 1) ? n : 0 ) : (n >> 1);
}
