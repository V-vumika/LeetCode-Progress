class Solution {
public:
    struct Node {
        int len;
        int pref;
        int suff;
        int mx;
        char lc, rc;

        Node() {
            len = pref = suff = mx = 0;
            lc = rc = '#';
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        res.suff = b.suff;

        // Prefix can extend
        if (a.pref == a.len && a.rc == b.lc) {
            res.pref = a.len + b.pref;
        }

        // Suffix can extend
        if (b.suff == b.len && a.rc == b.lc) {
            res.suff = b.len + a.suff;
        }

        // Maximum inside either half
        res.mx = max(a.mx, b.mx);

        // Join both halves
        if (a.rc == b.lc) {
            res.mx = max(res.mx, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].mx = 1;
            seg[node].lc = s[l];
            seg[node].rc = s[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            seg[node].lc = ch;
            seg[node].rc = ch;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, ch);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, ch);
        }

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(seg[1].mx);
        }

        return ans;
    }
};