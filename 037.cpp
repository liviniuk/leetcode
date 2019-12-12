// Traverse the board recursively (from left to right, row by row).
// Check AllDiff constraint only for the current cell (in constant time - using lookup tables).
// Recursively proceed or backtrack if AllDiff violated.

class Solution {
private:
    static const char EMPTY = '.';
    static const int N = 9; // board size
    static const int C = sqrt(N); // subgrid size
    
    bool horizontal[N][N] = {false};
    bool vertical[N][N] = {false};
    bool subgrid[N][N] = {false};
    
    bool recursiveSolved(vector<vector<char>>& board, int row, int col) {
        if (col == N) {
            col = 0;
            ++row;
            
            if (row == N)
                return true;
        }
        
        if (board[row][col] != EMPTY)
            return recursiveSolved(board, row, col + 1);
        
        int s = C * (row / C) + col / C;
        
        for (int num = 0; num < N; ++num) {
            // Check if num would satisfy AllDiff constraints if placed at [row,col]
            if (horizontal[row][num] == false && vertical[col][num] == false && subgrid[s][num] == false) {
                board[row][col] = '1' + num;
                horizontal[row][num] = vertical[col][num] = subgrid[s][num] = true;
                
                if (recursiveSolved(board, row, col + 1))
                    return true;
                
                board[row][col] = EMPTY;
                horizontal[row][num] = vertical[col][num] = subgrid[s][num] = false;
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] != EMPTY) {
                    int num = board[i][j] - '1';
                    int s = C * (i / C) + j / C;
                    horizontal[i][num] = vertical[j][num] = subgrid[s][num] = true;
                }
        
        recursiveSolved(board, 0, 0);
    }
};
