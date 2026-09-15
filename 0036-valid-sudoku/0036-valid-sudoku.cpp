class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                
                if (val == '.') continue;
                
                int bit = 1 << (val - '0'); // digit কে bitmask এ কনভার্ট করা
                int boxIndex = (r / 3) * 3 + (c / 3);
                
                if ((rows[r] & bit) || (cols[c] & bit) || (boxes[boxIndex] & bit)) {
                    return false;
                }
                
                rows[r] |= bit;
                cols[c] |= bit;
                boxes[boxIndex] |= bit;
            }
        }
        
        return true;
    }
};