/*
Problem: 1346. Check If N and Its Double Exist
Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for (auto &it : arr){
            int a = it * 2;
            int b = it / 2;
            if (m.find(a) != m.end()){
                return true;
            }
            
            if (m.find(b) != m.end() && b * 2 == it){
                return true;
            }
            
            m[it]++;
        }
        
        return false;
    }
};
