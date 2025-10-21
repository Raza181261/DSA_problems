class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j) {
        int M = board.size();
        int N = board[0].size();

        if (i < 0 || j < 0 || i >= M || j >= N || board[i][j] != 'O')
            return;

        board[i][j] = '#';

        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        int m = board.size();
        int n = board[0].size();

        // capture all borders O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') // left side of row
                DFS(board, i, 0);
            if (board[i][n-1] == 'O') // right side of row
                DFS(board, i, n-1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') // top side of column
                DFS(board, 0, j);
            if (board[m-1][j] == 'O') // bottom side of column
                DFS(board, m-1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};