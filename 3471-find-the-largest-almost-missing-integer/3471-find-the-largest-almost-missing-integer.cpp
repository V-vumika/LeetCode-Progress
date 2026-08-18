class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int count[51] = {0};

        for (int ele : nums) {
            count[ele]++;
        }

        // For k == nums.size()
        if (k == nums.size()) {

            int maxValue = -1;

            for (int ele : nums) {
                maxValue = max(maxValue, ele);
            }

            return maxValue;
        }

        // For k == 1
        if (k == 1) {

            for (int i = 50; i >= 0; i--) {

                if (count[i] == 1) {
                    return i;
                }
            }
        }

        int ans = -1;

        // Check first element
        if (count[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        // Check last element
        if (count[nums[nums.size() - 1]] == 1) {
            ans = max(ans, nums[nums.size() - 1]);
        }

        return ans;
    }
};