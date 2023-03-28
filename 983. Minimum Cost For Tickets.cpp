/*
Link: https://leetcode.com/problems/minimum-cost-for-tickets/
Problem: 983. Minimum Cost For Tickets
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        queue<pair<int, int>> days7, days30;
        
        for (int d : days){
            while (days7.size()){
                if (days7.front().first + 7 <= d){
                    days7.pop();
                } else {
                    break;
                }
            }
            
            while (days30.size()){
                if (days30.front().first + 30 <= d){
                    days30.pop();
                } else {
                    break;
                }
            }
            
            days7.push({d, ans + costs[1]});
            days30.push({d, ans + costs[2]});
            
            ans = min(ans + costs[0], days7.front().second);
            ans = min(ans, days30.front().second);
        }
        
        return ans;
    }
};