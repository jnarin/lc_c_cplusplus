/*
Problem: 3169. Count Days Without Meetings
Link: https://leetcode.com/problems/count-days-without-meetings/
*/

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            vector<vector<int>> m = merge(meetings);

            int r = 0;
            for (int i = 0; i < m.size(); i++){
                r += m[i][1] - m[i][0] + 1;
            }

            return days - r;
        }
        
    private:
        vector<vector<int>> merge(vector<vector<int>>& x) {
            vector<vector<int>> r;
            if (x.size() < 1){
                return r;
            }
            
            sort(x.begin(), x.end());
            
            r.push_back({x[0][0], x[0][1]});
            for (int i = 1; i < x.size(); i++){
                int y = r.size() - 1;
                if (x[i][0] <= r[y][1]){
                    if (x[i][1] > r[y][1]){
                        r[y] = {r[y][0], x[i][1]};
                    }
                } else {
                    r.push_back({x[i][0], x[i][1]});
                }
            }
            
            return r;
        }
    };
