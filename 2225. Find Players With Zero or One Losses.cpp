/*
 * Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/
 * Problem: 2225. Find Players With Zero or One Losses
 * */

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winners, losers;

        for (auto& it : matches){
            winners[it[0]]++;
            losers[it[1]]++;
        }

        vector<vector<int>> ans(2);
        for (auto& it : losers){
            if (winners.find(it.first) != winners.end()){
                winners.erase(it.first);
            }

            if (it.second == 1){
                ans[1].emplace_back(it.first);
            }
        }

        for (auto& it : winners){
            ans[0].emplace_back(it.first);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};
