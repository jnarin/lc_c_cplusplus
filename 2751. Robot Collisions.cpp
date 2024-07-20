/*
Problem: 2751. Robot Collisions
Link: https://leetcode.com/problems/robot-collisions/
*/

struct Robot {
    int idx, pos, health;
    char dir;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        vector<Robot> robots, st;
        int i;
        
        for (i = 0; i < positions.size(); i++) {
            robots.push_back({i, positions[i], healths[i], directions[i]});
        }
        
        ranges::sort(robots, [](const Robot& a, const Robot &b) {
            return a.pos < b.pos;
        });
        
        
        for (auto &r : robots) {
            if (r.dir == 'R') {
                st.push_back(r);
                continue;
            }
            
            while (st.size() && st.back().dir == 'R' && r.health){
                if (st.back().health == r.health) {
                    st.pop_back();
                    r.health = 0;
                } else if (st.back().health < r.health) {
                    st.pop_back();
                    r.health -= r.health ? 1 : 0;
                } else {
                    st.back().health -= st.back().health ? 1 : 0;
                    r.health = 0;
                }
            }
            
            if (r.health) {
                st.push_back(r);
            }
        }
        
        ranges::sort(st, [](const Robot& a, const Robot& b) {
            return a.idx < b.idx;
        });
        
        for (auto& r : st) {
            ans.push_back(r.health);
        }
        
        return ans;
    }
};
