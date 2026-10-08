class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int numWords = words.size();
        int wordLen = words[0].size();
        if (n < numWords * wordLen) return result;

        
        unordered_map<string, int> id;
        vector<int> need;
        for (auto& w : words) {
            auto it = id.find(w);
            if (it == id.end()) {
                id[w] = need.size();
                need.push_back(1);
            } else {
                need[it->second]++;
            }
        }
        int k = need.size();

        
        int m = n - wordLen + 1;
        vector<int> wid(m, -1);
        for (int i = 0; i < m; i++) {
            auto it = id.find(s.substr(i, wordLen));
            if (it != id.end()) wid[i] = it->second;
        }

        
        for (int offset = 0; offset < wordLen; offset++) {
            vector<int> window(k, 0);
            int left = offset, count = 0;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                int r = wid[right];

                if (r == -1) {
    
                    while (left < right) {
                        window[wid[left]]--;
                        left += wordLen;
                    }
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[r]++;
                count++;

                while (window[r] > need[r]) {
                    window[wid[left]]--;
                    count--;
                    left += wordLen;
                }

                if (count == numWords) {
                    result.push_back(left);
                    window[wid[left]]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return result;
    }
};