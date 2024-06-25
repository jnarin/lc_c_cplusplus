/*
Problem: 502. IPO
Link: https://leetcode.com/problems/ipo/
*/

struct X {
    int pro, cap;
    X(int a, int b) : pro(a), cap(b) {}
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto compareC = [](const X& a, const X& b) {return a.cap > b.cap; };
        auto compareP = [](const X& a, const X& b) {return a.pro < b.pro; };

        priority_queue<X, vector<X>, decltype(compareC)> minHeap(compareC);
        priority_queue<X, vector<X>, decltype(compareP)> maxHeap(compareP);

        int i;

        for (i = 0; i < capital.size(); i++){
            minHeap.emplace(profits[i], capital[i]);
        }

        while (k--){
            while (minHeap.size() && minHeap.top().cap <= w){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (maxHeap.size() == 0){
                break;
            }

            w += maxHeap.top().pro;
            maxHeap.pop();
        }

        return w;
    }
};