/*
Link: https://leetcode.com/problems/implement-stack-using-queues/
Problem: 225. Implement Stack using Queues
Follow-up: Can you implement the stack using only one queue?
*/
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int i, s = q.size();
        
        q.push(x);
        for (i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        
        return ans;
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */