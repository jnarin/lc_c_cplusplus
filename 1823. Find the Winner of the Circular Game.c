/* 
Problem: 1823. Find the Winner of the Circular Game
Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

int findTheWinner(int n, int k) {
    int ans = 0, i;
    
    for (i = 2; i <=n; i++) {
        ans  = (ans + k) % i;
    }
    
    return ans + 1;
}