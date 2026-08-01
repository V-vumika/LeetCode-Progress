class Solution {
public:
    int t[23][23];

    int solve(vector<int>& nums, int i, int j) {

        if (i > j)
            return 0;

        if (i == j)
            return nums[i];

        if (t[i][j] != -1)
            return t[i][j];

        int take_i = nums[i] - solve(nums, i + 1, j);
        int take_j = nums[j] - solve(nums, i, j - 1);

        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {

        memset(t, -1, sizeof(t));

        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};