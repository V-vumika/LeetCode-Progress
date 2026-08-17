class Solution {
public:
    int stoneGameV(vector<int>& A) {
        int n = A.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> mx(n, vector<int>(n, 0));

        // mx[i][i] = value of single stone
        for (int i = 0; i < n; i++) {
            mx[i][i] = A[i];
        }

        for (int r = 1; r < n; r++) {

            int mid = r;
            int sum = A[r];
            int right = 0;

            for (int l = r - 1; l >= 0; l--) {

                sum += A[l];

                // Find the point where
                // left sum becomes >= right sum
                while (mid > l &&
                       (right + A[mid]) * 2 <= sum) {

                    right += A[mid];
                    mid--;
                }

                // Equal case
                if (right * 2 == sum) {
                    dp[l][r] = mx[l][mid];
                }

                // Left side is smaller
                if (mid != l) {
                    dp[l][r] = max(
                        dp[l][r],
                        mx[l][mid - 1]
                    );
                }

                // Right side is smaller
                if (mid != r) {
                    dp[l][r] = max(
                        dp[l][r],
                        mx[r][mid + 1]
                    );
                }

                // Update maximum for [l...r]
                mx[l][r] = max(
                    mx[l][r - 1],
                    dp[l][r] + sum
                );

                // Store reverse interval information
                mx[r][l] = max(
                    mx[r][l + 1],
                    dp[l][r] + sum
                );
            }
        }

        return dp[0][n - 1];
    }
};