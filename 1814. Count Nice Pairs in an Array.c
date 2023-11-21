/*
Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/
Problem: 1814. Count Nice Pairs in an Array
*/
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long> m;
        int ans = 0;
        const int mod = 1e9 + 7;
        
        /* If nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]),
        nums[i] - rev(nums[i]) == nums[j] = rev(nums[j]) */
        
        for (int i = 0; i < nums.size(); i++){
            m[nums[i] - reverseInt(nums[i])]++;            
        }
        
        for (auto &it : m){
            ans = (ans + ((it.second * (it.second - 1)) / 2)) % mod;
        }
        
        return ans;        
        
    }
    
private:
    int reverseInt(int n){
        int ans = 0;
        
        while (n){
            ans = (ans * 10) + (n % 10);
            n /= 10;
        }
        
        return ans;
    }
};