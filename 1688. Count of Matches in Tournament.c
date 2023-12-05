/*
Link: https://leetcode.com/problems/count-of-matches-in-tournament/
Problem: 1688. Count of Matches in Tournament
*/

int numberOfMatches(int n){
    int ans = 0;
    
    while (1){
        if (n <= 1){
            break;
        }
		
		ans += (n >> 1);
        
        n = (n & 1) ?  (n + 1) >> 1 : n >> 1;
    }

    return ans;
}