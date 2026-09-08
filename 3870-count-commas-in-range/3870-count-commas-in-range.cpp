class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long lo = 1000; 

        int d = 4;
        
        while (lo <= n) {
            long long hi = lo * 10 - 1; 
            
            long long rangeHi = min((long long)n, hi);
            long long count = rangeHi - lo + 1;
            int commas = (d - 1) / 3;
            total += count * commas;
            
            lo = hi + 1;
            d++;
        }
        
        return (int)total;
    }
};