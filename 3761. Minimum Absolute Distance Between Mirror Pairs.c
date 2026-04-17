/*
Problem: 3761. Minimum Absolute Distance Between Mirror Pairs
Link: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
*/
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.contains(nums[i])) {
                ans = min(ans, i - m[nums[i]]);
            }

            m[reverseNum(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }

private:
    int reverseNum(int num) {
        int reverse = 0;
        while (num) {
            reverse = reverse * 10 + (num % 10);
            num /= 10;
        }

        return reverse;
    }
};
