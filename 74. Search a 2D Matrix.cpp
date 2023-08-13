/*
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 * Prboblem: 74. Search a 2D Matrix
 * */

#define MID(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        pair<int, int> l, r;

        /* First identify the row in which the value falls using
        bsearch*/
        l = {0, 0};
        r = {matrix.size() - 1, matrix[0].size() - 1};

        while (l <= r){
            int m = MID(l.first, r.first);

            if (target == matrix[m][r.second]){
                return true;
            }

            if (target < matrix[m][r.second]){
                r.first = m - 1;
            } else {
                l.first = m + 1;
            }
        }

        /* We have a potential row into which the target
        can fit in - now we perform a bsearch on 1-D array
        (that row) to check if value is present or not */

        if (l.first < 0 || l.first >=matrix.size()){
            return false;
        }

        int x = 0, y = matrix[l.first].size() - 1;

        while (x <= y){
            int m = MID(x, y);
            if (matrix[l.first][m] == target){
                return true;
            }

            if (target < matrix[l.first][m]){
                y = m - 1;
            } else {
                x = m + 1;
            }
        }

        return false;
    }
};
