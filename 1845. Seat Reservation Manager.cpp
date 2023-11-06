/*
Link: https://leetcode.com/problems/seat-reservation-manager/
Problem: 1845. Seat Reservation Manager
*/

class SeatManager {
public:
    SeatManager(int n) {
        for (int seat = 1; seat <= n; seat++){
            pq.push(seat);
        }
        
    }
    
    int reserve() {
        int ans = pq.top();
        pq.pop();
        
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);        
    }
    
private:
    priority_queue<int, vector<int>, std::greater<>> pq;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */