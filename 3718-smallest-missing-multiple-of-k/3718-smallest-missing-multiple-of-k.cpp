class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool present[101] = {};

        for (int x : nums) {
            present[x] = true;
        }

        for (int multiple = k; ; multiple += k) {
            if (multiple > 100 || !present[multiple]) {
                return multiple;
            }
        }
    }
};