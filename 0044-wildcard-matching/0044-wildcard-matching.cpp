class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1;   
        int match = 0;      
        int m = s.length(), n = p.length();
        
        while (i < m) {
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
              
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
               
                starIdx = j;
                match = i;
                j++;
            } else if (starIdx != -1) {
                
                j = starIdx + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }
        
        while (j < n && p[j] == '*') {
            j++;
        }
        
        return j == n;
    }
};