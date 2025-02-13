/*
Problem: 3066. Minimum Operations to Exceed Threshold Value II
Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;

        for (auto& it : nums) {
            pq.push(it);
        }

        int ans = 0;
        
        while (pq.size()) {
            if (pq.top() >= k) {
                return ans;
            }

            long x = pq.top(); pq.pop();
            long y = pq.top(); pq.pop();
            long z = min(x, y) * 2 + max(x, y);
            pq.push(z);

            ans++;
        }
        
        assert(0);
        return -1;
    }
};
