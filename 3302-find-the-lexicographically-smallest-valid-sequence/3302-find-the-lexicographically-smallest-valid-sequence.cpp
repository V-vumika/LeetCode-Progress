class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> right(n);
        int j = m - 1;
        int cnt = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                ++cnt;
                --j;
            }
            right[i] = cnt;
        }

        vector<int> ans;
        ans.reserve(m);

        bool changed = false;
        j = 0;

        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }
            else if (!changed &&
                     i + 1 < n &&
                     right[i + 1] >= m - j - 1) {
                ans.push_back(i);
                ++j;
                changed = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};