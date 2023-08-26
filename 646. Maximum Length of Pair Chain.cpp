/*
 * Link: https://leetcode.com/problems/maximum-length-of-pair-chain/
 * Problem: 646. Maximum Length of Pair Chain
 * */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0, t = INT_MIN;

        sort(pairs.begin(), pairs.end(),
            [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        for (auto &it : pairs){
            if (it[0] > t){
                ans++;
                t = it[1];
            }
        }

        return ans;
    }
};
