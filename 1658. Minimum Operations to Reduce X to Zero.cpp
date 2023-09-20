/*
Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
Problem: 1658. Minimum Operations to Reduce X to Zero
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum, i, ans, val;
        unordered_map<int, int> m;
        
        sum = val = 0;
        ans = -1;
        
        for (i = 0; i < n; i++){
            sum += nums[i];
            m[sum] = i;
        }
        
        if (sum < x){
            return ans;
        }
        
        m[0] = ans = 0;
        sum -= x;
        
        for (i = 0; i < n; i++){
            val += nums[i];
            if (m.find(val - sum) != m.end()){
                ans = val - sum == 0 
                    ? max(ans, i - m[val - sum] + 1)
                    : max(ans, i - m[val - sum]);
            }
        }
        
        return ans == 0 
            ? (sum == 0 ? n : -1)  
            : n - ans;
    }
};