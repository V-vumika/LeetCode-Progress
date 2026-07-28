class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        string left;
        left.reserve(s.size() / 2);

        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            left.append(freq[i] / 2, char('a' + i));

            if (freq[i] & 1)
                mid = char('a' + i);
        }

        string ans;
        ans.reserve(s.size());

        ans += left;
        if (mid) ans += mid;

        reverse(left.begin(), left.end());
        ans += left;

        return ans;
    }
};