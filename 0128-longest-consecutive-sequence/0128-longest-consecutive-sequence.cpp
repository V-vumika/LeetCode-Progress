class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int cnt = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};