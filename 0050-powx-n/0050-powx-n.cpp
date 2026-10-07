class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        long double base = x;
        
        if (N < 0) {
            base = 1.0L / base;
            N = -N;
        }
        
        return (double)fastPow(base, N);
    }
    
private:
    long double fastPow(long double x, long long n) {
        if (n == 0) return 1.0L;
        
        long double half = fastPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};