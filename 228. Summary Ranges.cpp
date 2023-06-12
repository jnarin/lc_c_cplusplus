/*
Link: https://leetcode.com/problems/summary-ranges/
Problem: 228. Summary Ranges
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if (nums.size() == 0){
            return ans;
        }
        
        int i = 0;
        
        while (i < nums.size()){
            string s = "";
            bool range = false;
            
            s += to_string(nums[i]);
            
            while (i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]){
                range = true;
                i++;
            }
            
            if (range == false){
                ans.push_back(s);
                i++;
                continue;
            }
            
            s += "->";
            s += to_string(nums[i]);
            ans.push_back(s);
            i++;
        }
        
        return ans;
        
    }
};