class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int imax = 0, icount = 0;
        int dmax = 0, dcount = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                icount++;
                dcount = 0;
            } else if (nums[i] > nums[i + 1]) {
                dcount++;
                icount = 0;
            } else {
                icount = 0;
                dcount = 0;
            }

            imax = max(imax, icount);
            dmax = max(dmax, dcount);
        }

        return max(imax + 1, dmax + 1);
    }
};