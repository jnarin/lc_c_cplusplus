/*
 * Link: https://leetcode.com/problems/sliding-window-maximum/
 * Problem: 239. Sliding Window Maximum
 * */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int i = 0;
        vector<int> r;
        /* Push k elements from nums into pq. Top of the queue
        has the hightest element of this window */
        while (i < nums.size() && i < k){
            pq.push({nums[i], i});
            i++;
        }

        if (pq.size()) r.push_back(pq.top().first);

        while (i < nums.size()){
            /* Check the top element in queue, if it is not in the
            window range, remove it. We do not care about other
            elements in the queue. */
            while (pq.size() && pq.top().second <= i - k){
                pq.pop();
            }

            /* Add new element into the queue */
            pq.push({nums[i], i});

            /* Append result vector with highest value */
            r.push_back(pq.top().first);
            i++;
        }

        return r;
    }
};

