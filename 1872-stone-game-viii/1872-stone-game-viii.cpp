class Solution {
public:
    int n;
    long long t[100001];

    long long solve(int i, vector<long long>& prefixSum) {
        
        if (i == n - 1) {
            return prefixSum[n - 1];
        }

        if (t[i] != LLONG_MIN) {
            return t[i];
        }

        long long take = prefixSum[i] - solve(i + 1, prefixSum);

        long long skip = solve(i + 1, prefixSum);

        return t[i] = max(take, skip);
    }

    long long stoneGameVIII(vector<int>& stones) {

        n = stones.size();

        vector<long long> prefixSum(n);

        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        for (int i = 0; i < n; i++) {
            t[i] = LLONG_MIN;
        }

        // i = 0 is NOT a valid first move
        return solve(1, prefixSum);
    }
};