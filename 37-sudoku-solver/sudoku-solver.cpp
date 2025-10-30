class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  // Empty cell found
                    for (char c = '1'; c <= '9'; c++) {  // Try digits 1–9
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;  // Place the digit
                            
                            if (solve(board)) return true;  // Continue recursively
                            else board[i][j] = '.';  // Backtrack
                        }
                    }
                    return false;  // No valid digit found
                }
            }
        }
        return true;  // All cells filled correctly
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row and column
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            // Check 3×3 subgrid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == c) return false;
        }
        return true;
    }
};
