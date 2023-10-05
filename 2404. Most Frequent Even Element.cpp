/*
Link: https://leetcode.com/problems/most-frequent-even-element/
Problem: 2404. Most Frequent Even Element
*/
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freqMap; // value, frequency
        int ans = -1, f = -1;
        
        for (auto &it : nums){
            if ((it & 1) == 0){
                freqMap[it]++;
            }
        }
        
        for (auto &[val, freq] : freqMap){
            if (freq > f){
                ans = val;
                f = freq;
            } else if (freq == f){
                ans = val < ans ? val : ans;
            }
        }
        
        return ans;
    }
};