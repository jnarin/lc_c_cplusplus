/*
Link: https://leetcode.com/problems/binary-trees-with-factors/
Problem: 823. Binary Trees With Factors
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = (1e9 + 7), i, j, r;
        vector<long> dp(arr.size(), 1);
        unordered_map<int, int> m;
        
        sort(arr.begin(), arr.end());
        
        for(i = 0; i < arr.size(); i++){
            m[arr[i]] = i;
        }
        
        for(i = 0; i < arr.size(); i++){
            for (j = 0; j < i; j++){
                if (arr[i] % arr[j] == 0){
                    r = arr[i] / arr[j];
                    dp[i] = m.find(r) != m.end() 
                        ? (dp[i] + (dp[j] * dp[m[r]])) % mod 
                        : dp[i];
                }
            }
        }
        
        long ans = 0;
        for (auto &it : dp){
            ans += it;
        }
        
        return static_cast<int>(ans % mod);
    }
};