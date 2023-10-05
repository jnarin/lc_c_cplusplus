/*
Link: https://leetcode.com/problems/majority-element-ii/
Problem: 229. Majority Element II
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freqMap; // value, count
        
        for (auto &it : nums){
            freqMap[it]++;
        }
        
        for (auto &[val, freq] : freqMap){
            if (freq > nums.size() / 3){
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};