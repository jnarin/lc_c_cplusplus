/*
 * Problem: 79. Word Search
 * Link: https://leetcode.com/problems/word-search/
 * */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        R = board.size();
        C = board[0].size();

        for (int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if (dfs(board, r, c, word, 0) == true){
                    return true;
                }
            }
        }

        return false;
    }

private:
    int R, C;
    vector<pair<int, int>> path; // visited r, c

    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int pos){
        bool ret = true;
        if (pos >= word.length()) {
            return ret;
        }

        if (
            r < 0 || r >= R || c < 0 || c >= C
            || word[pos] != board[r][c] || visited(r, c)
            ){
                return !ret;
        }

        path.push_back({r, c});
        ret = dfs(board, r + 1, c, word, pos + 1)
            || dfs(board, r - 1, c, word, pos + 1)
            || dfs(board, r, c + 1, word, pos + 1)
            || dfs(board, r, c - 1, word, pos + 1);

        path.pop_back();

        return ret;
    }

    bool visited(int r, int c){
        for (auto& it : path){
            if (it.first == r && it.second == c) return true;
        }

        return false;
    }
};
