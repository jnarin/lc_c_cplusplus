/*
Problem: 773. Sliding Puzzle
Link: https://leetcode.com/problems/sliding-puzzle/
*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = convertBoardToString(board);
        string target = "123450";

        if (start == target) {
            return 0;
        }

        unordered_set<string> visited;
        queue<string> q;
        int ans = 0;

        q.push(start);
        visited.insert(start);

        while (q.size()) {
            ans++;
            for (int n = q.size(); n > 0; n--) {
                string s = q.front();
                q.pop();

                int i = s.find('0');
                
                for (int d : {1, -1, 3, -3}) {
                    int j = i + d;
                    
                    if (j < 0 || j >= 6 || (i == 2 && j == 3) || (i == 3 && j == 2)) {
                        continue;
                    }
                    
                    swap(s[i], s[j]);
                    
                    if (s == target) {
                        return ans;
                    }
                    
                    if (visited.count(s) == 0) {
                        q.push(s);
                        visited.insert(s);
                    }
                    
                    swap(s[i], s[j]);
                }
            }
        }
        
        return -1;
    }

private:
    string convertBoardToString(vector<vector<int>>& board) {
        string result = "";
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                result += to_string(board[i][j]);
            }

        }
        return result;
    }
};
