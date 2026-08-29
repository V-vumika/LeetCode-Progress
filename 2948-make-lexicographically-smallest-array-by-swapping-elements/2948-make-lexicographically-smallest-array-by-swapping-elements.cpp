class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // value + original index
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            
            int j = i;

            while (j + 1 < n &&
                   v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(v[k].second);
            }

            sort(indices.begin(), indices.end());

            int p = 0;

            for (int k = i; k <= j; k++) {
                ans[indices[p]] = v[k].first;
                p++;
            }

            i = j + 1;
        }

        return ans;
    }
};