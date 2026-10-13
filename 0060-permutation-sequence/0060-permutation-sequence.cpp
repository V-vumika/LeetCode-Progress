class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i; 
        }
        
        string digits;
        for (int i = 1; i <= n; i++) {
            digits += char('0' + i);
        }
        
        k--; 
        string result;
        
        for (int i = n - 1; i >= 0; i--) {
            int idx = k / fact[i];
            k %= fact[i];
            
            result += digits[idx];
            digits.erase(digits.begin() + idx);
        }
        
        return result;
    }
};