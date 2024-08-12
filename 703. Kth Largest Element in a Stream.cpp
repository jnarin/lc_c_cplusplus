/*
Problem: 703. Kth Largest Element in a Stream
Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        numElements_ = k;
        
        for (auto& it : nums) {
            add(it);
        }
    }
    
    int add(int val) {
        pq_.push(val);
        
        while (pq_.size() && pq_.size() > numElements_) {
            pq_.pop();
        }
        
        return pq_.top();
    }
    
private:
    priority_queue<int, vector<int>, std::greater<int>> pq_;
    int numElements_ = 0;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
