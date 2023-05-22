/*
Link: https://leetcode.com/problems/top-k-frequent-elements/
Problem: 347. Top K Frequent Elements
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int maxFreq = 0;
        
        for (auto &it : nums){
            freqMap[it]++;
            maxFreq = max(maxFreq, freqMap[it]);
        }
        
        unordered_map<int, vector<int>> m;
        for (auto &it : freqMap){
            m[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for (int i = maxFreq; i >= 0 && k; i--){
            if (m.find(i) != m.end()){
                for (auto &it : m[i]){
                    ans.push_back(it);
                    k--;
                    if (!k){
                        break;
                    }
                }
            }
        }
        
        return ans;        
    }
};
