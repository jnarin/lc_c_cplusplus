/*
Problem: 846. Hand of Straights
Link: https://leetcode.com/problems/hand-of-straights/
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        
        for (int c : hand) {
            m[c]++;
        }
        
        for(auto& [s, _] : m) {
            int v = m[s];
            if (v > 0) {
                for (int i = s; i < s + groupSize; i++) {
                    m[i] -= v;
                    if (m[i] < 0) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
