/*
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Problem: 215. Kth Largest Element in an Array
 * */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &n : nums){
            pq.push(n);
            while (pq.size() > k){
                pq.pop();
            }
        }

        assert(pq.size());

        return pq.top();

    }
};


