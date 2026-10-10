class Solution {
public:
    int totalNQueens(int n) {
        int full = (1 << n) - 1; 
        return solve(full, 0, 0, 0);
    }
    
private:
    int solve(int full, int cols, int diag1, int diag2) {
        if (cols == full) return 1; 
        
        int count = 0;
        int available = full & ~(cols | diag1 | diag2); 
        
        while (available) {
            int bit = available & -available; 
            available &= available - 1;       
            
            count += solve(full,
                           cols | bit,
                           ((diag1 | bit) << 1) & full,
                           (diag2 | bit) >> 1);
        }
        
        return count;
    }
};