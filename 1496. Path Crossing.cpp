/*
 * Link: https://leetcode.com/problems/path-crossing/
 * Problem: 1496. Path Crossing
 * */

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        int x, y;
        string p = "";

        x = 0;
        y = 0;

        p = to_string(x) + ',' + to_string(y);
        s.insert(p);

        for(auto &c : path){
            switch(c){
                case 'N':
                    y++;
                    break;

                case 'S':
                    y--;
                    break;

                case 'E':
                    x++;
                    break;

                case 'W':
                    x--;
                    break;

                default:
                    assert(0);
            }

            p = to_string(x) + ',' + to_string(y);
            if (s.find(p) == s.end()){
                s.insert(p);
            } else {
                return true;
            }
        }

        return false;
    }
};
