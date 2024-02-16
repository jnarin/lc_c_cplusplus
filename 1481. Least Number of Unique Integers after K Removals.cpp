/*
Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
Problem: 1481. Least Number of Unique Integers after K Removals
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        
        for (auto& it : arr) {
            m[it]++;
        }
        
        vector<int> freq;
        for (auto& [_, f] : m) {
            freq.push_back(f);
        }
        
        sort(freq.begin(), freq.end());
        
        for (int i = 0; i < freq.size(); i++) {
            k -= freq[i];
            
            if (k < 0) {
                return freq.size() - i;
            }
        }
        
        return 0;
    }
};