class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> sub[9];
        for (int i = 0; i < 9; ++i) 
            for(int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int s = 3 * (i / 3) + j / 3;
                if (row[i].find(board[i][j]) != row[i].end() || 
                    col[j].find(board[i][j]) != col[j].end() || 
                    sub[s].find(board[i][j]) != sub[s].end())
                    return false;
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                sub[s].insert(board[i][j]);
            }
        return true;
    }
};
