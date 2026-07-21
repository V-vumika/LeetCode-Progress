class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        vector<int> zero;

        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;

            if (s[i] == '1')
                ones += (j - i);
            else
                zero.push_back(j - i);

            i = j;
        }

        int best = 0;
        for (int i = 0; i + 1 < zero.size(); i++)
            best = max(best, zero[i] + zero[i + 1]);

        return ones + best;
    }
};