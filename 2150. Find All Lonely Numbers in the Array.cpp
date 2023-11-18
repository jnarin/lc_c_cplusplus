/*
 * Link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
 * Problem: 2150. Find All Lonely Numbers in the Array
 * */

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;

        for (auto &it : nums){
            m[it]++;
        }

        vector<int> ans;

        for (auto &[num, freq] : m){
            if (freq > 1){
                continue;
            }

            if (m.find(num + 1) == m.end() && m.find(num - 1) == m.end()){
                ans.push_back(num);
            }
        }

        return ans;
    }
};

