/*
 * Link: https://leetcode.com/problems/destination-city/
 * Problem: 1436. Destination City
 * */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> m;

        for (auto &it : paths){
            m[it[0]]++;
            if (m.find(it[1]) == m.end()){
                m[it[1]] = 0;
            }
        }

        string ans = "";
        for (auto &it : m){
            if (it.second == 0){
                ans = it.first;
                break;
            }
        }

        return ans;
    }
};
