class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats as a bitmask for each row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Initially every row can accommodate 2 groups
        int ans = 2 * n;

        for (auto &[row, mask] : mp) {
            bool left  = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));
            bool mid   = !(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)));

            int groups;

            if (left && right) {
                groups = 2;
            }
            else if (left || right || mid) {
                groups = 1;
            }
            else {
                groups = 0;
            }

            // This row was initially counted as 2
            ans -= (2 - groups);
        }

        return ans;
    }
};