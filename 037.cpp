// Traverse the board recursively (from left to right, row by row).
// Check AllDiff constraint only for the current cell.
// Recursively proceed or backtrack if AllDiff violated.

class Solution {
private:
    static const char EMPTY = '.';
    static const int N = 9; // board size
    static const int C = sqrt(N); // subgrid size
    
    bool recursiveSolved(vector<vector<char>>& board, int row, int col) {
        if (col == N) {
            col = 0;
            ++row;
            
            if (row == N)
                return true;
        }
        
        if (board[row][col] != EMPTY)
            return recursiveSolved(board, row, col + 1);
        
        
        for (int i = 1; i <= N; ++i) {
            char num = '0' + i;
            
            // Check constraints -> backtrack or proceed recursively
            if (satisfiesConstraints(board, row, col, num)) {
                board[row][col] = num;
                
                if (recursiveSolved(board, row, col + 1))
                    return true;
                
                board[row][col] = EMPTY;
            }
        }
        
        return false;
    }
    
    bool satisfiesConstraints(vector<vector<char>>& board, int row, int col, char num) {
        // Check AllDiff constraints of row and column in parallel
        for (int i = 0; i < N; ++i)
            if (board[row][i] == num or board[i][col] == num)
                return false;
        
        // Check AllDiff constraints of the local subgrid
        int left = row - row % C;
        int right = row - row % C + C;
        int top = col - col % C;
        int bottom = col - col % C + C;
        
        for (int i = left; i < right; ++i)
            for (int j = top; j < bottom; ++j)
                if (board[i][j] == num)
                    return false;
        
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Traverse rows from left to right.
        // Check constraint only for the current cell.
        // Recursively proceed or backtrack if AllDiff violated.
        recursiveSolved(board, 0, 0);
    }
};
