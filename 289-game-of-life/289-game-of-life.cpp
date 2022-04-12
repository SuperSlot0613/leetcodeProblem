class Solution {
public:
      vector<vector<int>> dirs = {
        {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1,-1} 
    };

    int getNeighbors(vector<vector<int>>& board, int r, int c) {
        int howManyAlive = 0;
        for(auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr < 0 || nr >= board.size()) continue;
            if(nc < 0 || nc >= board[r].size()) continue;
            
            howManyAlive += board[nr][nc];
        }
        return howManyAlive;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        
        vector<vector<int>> newBoard(ROWS, vector<int>(COLS));
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                int howManyAlive = getNeighbors(board, r, c);
                if(board[r][c] == 0 && howManyAlive == 3) {
                    newBoard[r][c] = 1;
                } else if (board[r][c] == 1 && howManyAlive < 2) {
                    newBoard[r][c] = 0;
                } else if (board[r][c] == 1 && howManyAlive > 3) {
                    newBoard[r][c] = 0;
                } else if (board[r][c] == 1) {
                    newBoard[r][c] = 1;
                }
            }
        }
        board = newBoard;
        return;
    }
};