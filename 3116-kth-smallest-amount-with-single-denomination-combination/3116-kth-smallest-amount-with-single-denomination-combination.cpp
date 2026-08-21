class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        int n = coins.size();

        vector<pair<long long, int>> subsets;

        // Precompute LCM and number of selected coins
        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);
                    lcm /= g;

                    if (lcm > 2000000000000000000LL / coins[i]) {
                        ok = false;
                        break;
                    }

                    lcm *= coins[i];
                }
            }

            if (ok)
                subsets.push_back({lcm, bits});
        }

        // Count valid numbers <= x
        auto count = [&](long long x) {
            long long ans = 0;

            for (auto [lcm, bits] : subsets) {
                if (lcm > x)
                    continue;

                long long cnt = x / lcm;

                if (bits & 1)
                    ans += cnt;
                else
                    ans -= cnt;
            }

            return ans;
        };

        // Binary search
        long long low = 1;
        long long high = 1LL * coins[0] * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};