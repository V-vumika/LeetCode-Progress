class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int bit = 1 << (board[r][c] - '0');
                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[(r / 3) * 3 + (c / 3)] |= bit;
                }
            }
        }
        
        backtrack(board, rows, cols, boxes, 0);
    }
    
private:
    bool backtrack(vector<vector<char>>& board, int rows[], int cols[], int boxes[], int pos) {
        if (pos == 81) return true; 
        
        int r = pos / 9;
        int c = pos % 9;
        
        if (board[r][c] != '.') {
            return backtrack(board, rows, cols, boxes, pos + 1); 
        }
        
        int b = (r / 3) * 3 + (c / 3);
        
        for (int d = 1; d <= 9; d++) {
            int bit = 1 << d;
            
            if ((rows[r] & bit) || (cols[c] & bit) || (boxes[b] & bit)) continue;
            
            board[r][c] = '0' + d;
            rows[r] |= bit;
            cols[c] |= bit;
            boxes[b] |= bit;
            
            if (backtrack(board, rows, cols, boxes, pos + 1)) return true;
            
            board[r][c] = '.';
            rows[r] &= ~bit;
            cols[c] &= ~bit;
            boxes[b] &= ~bit;
        }
        
        return false; 
    }
};