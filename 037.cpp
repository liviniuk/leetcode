// Traverse the board recursively (from left to right, row by row).
// Check AllDiff constraint only for the current cell (in constant time - using lookup tables).
// Recursively proceed or backtrack if AllDiff violated.

class Solution {
private:
    static const char EMPTY = '.';
    static const int N = 9; // board size
    static const int C = sqrt(N); // subgrid size
    
    int N_BITS = (1 << N) - 1; // first N bits
    vector<int> horizontal = vector<int>(N, N_BITS);
    vector<int> vertical = vector<int>(N, N_BITS);
    vector<int> subgrid = vector<int>(N, N_BITS);
    
    vector<vector<int>> bitBoard = vector<vector<int>>(N, vector<int>(N, 0));
    
    void flipBits(int row, int col, int bit) {
        horizontal[row] ^= bit;
        vertical[col] ^= bit;
        subgrid[C * (row / C) + col / C] ^= bit;
        bitBoard[row][col] ^= bit;
    }
    
    bool recursiveSolved(int row, int col) {
        if (col == N) {
            col = 0;
            ++row;
            
            if (row == N)
                return true;
        }
        
        if (bitBoard[row][col] != 0)
            return recursiveSolved(row, col + 1);
        
        int s = C * (row / C) + col / C;
        int options = horizontal[row] & vertical[col] & subgrid[s];
        
        while (options) {
            int next = ((options - 1) ^ options) & options; // the smallest (last) bit in options is the next option to try
            options ^= next; // remove next bit from options
            flipBits(row, col, next);
            if (recursiveSolved(row, col + 1))
                return true;
            flipBits(row, col, next);
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] != EMPTY) {
                    int bit = 1 << (board[i][j] - '1');
                    flipBits(i, j, bit);
                }
        
        recursiveSolved(0, 0);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                int num = 0; 
                while ((bitBoard[i][j] >> num) > 0) 
                    num++;
                board[i][j] = (char)('0' + num);
            }
    }
};
