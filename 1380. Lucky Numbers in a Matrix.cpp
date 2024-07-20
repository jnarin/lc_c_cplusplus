/*
Problem: 1380. Lucky Numbers in a Matrix
Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        for (auto& row : matrix) {
            int minIndex = distance(row.begin(), ranges::min_element(row));
            if (row[minIndex] == maxOfColumn(matrix, minIndex)) {
                return {row[minIndex]};
            }
        }
        
        return {};
    }
    
private:
    int maxOfColumn(vector<vector<int>> &matrix, int j) {
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            ans = max(ans, matrix[i][j]);
        }
        
        return ans;
    }
    
};
