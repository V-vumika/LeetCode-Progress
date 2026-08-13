class Solution {
public:
    struct Node {
        int len;
        int left;
        int right;
        int pref;
        int suff;
        int best;

        Node() {
            len = 0;
            left = right = -1;
            pref = suff = best = 0;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        res.suff = b.suff;

        if (a.pref == a.len && a.right == b.left)
            res.pref = a.len + b.pref;

        if (b.suff == b.len && a.right == b.left)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.right == b.left)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int idx, int l, int r) {

        if (l == r) {
            tree[idx].len = 1;
            tree[idx].left = s[l] - 'a';
            tree[idx].right = s[l] - 'a';
            tree[idx].pref = 1;
            tree[idx].suff = 1;
            tree[idx].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {
            tree[idx].left = ch - 'a';
            tree[idx].right = ch - 'a';
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, ch);
        else
            update(2 * idx + 1, mid + 1, r, pos, ch);

        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};