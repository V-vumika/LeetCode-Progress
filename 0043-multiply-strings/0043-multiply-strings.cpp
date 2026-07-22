class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        string ans(n + m, '0');

        for (int i = n - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = m - 1; j >= 0; --j) {
                int cur = (ans[i + j + 1] - '0') +
                          (num1[i] - '0') * (num2[j] - '0') +
                          carry;

                ans[i + j + 1] = (cur % 10) + '0';
                carry = cur / 10;
            }
            ans[i] += carry;
        }

        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0') i++;
        return ans.substr(i);
    }
};