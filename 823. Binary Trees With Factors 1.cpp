/*
Link: https://leetcode.com/problems/binary-trees-with-factors/
Problem: 823. Binary Trees With Factors
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int r = 0;
        int n = arr.size();
        unordered_map<int, long> m;
        
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++){
            m[arr[i]] = 1;
            for (int j = 0; j < i; j++){
                if (arr[i] % arr[j] == 0){
                    m[arr[i]] = (m[arr[i]] + m[arr[j]] * m[arr[i] / arr[j]]) % MOD;
                }
            }
            
            r = (r + m[arr[i]]) % MOD;
        }
        
        return r;
    }
};