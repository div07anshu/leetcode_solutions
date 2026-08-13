using vi = vector<int>;

class Solution {
public:
    struct Node {
        char lc, rc;
        int pref, suff, best, len;

        Node() {
            lc = rc = '#';
            pref = suff = best = len = 0;
        }

        Node(char c) {
            lc = rc = c;
            pref = suff = best = len = 1;
        }
    };

    vector<Node> seg;

    Node merge(Node& L, Node& R) {
        if (L.len == 0)
            return R;
        if (R.len == 0)
            return L;

        Node res;

        res.len = L.len + R.len;
        res.lc = L.lc;
        res.rc = R.rc;

        res.pref = L.pref;
        res.suff = R.suff;
        res.best = max(L.best, R.best);

        if (L.rc == R.lc) {
            res.best = max(res.best, L.suff + R.pref);

            if (L.pref == L.len) {
                res.pref = L.len + R.pref;
            }

            if (R.suff == R.len) {
                res.suff = R.len + L.suff;
            }
        }

        return res;
    }

    void build(int idx, int l, int r, string& s) {
        if (l == r) {
            seg[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, c);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, c);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s, string qchar, vi& qi) {

        int n = s.size();
        seg.resize(4 * n + 5);
        build(1, 0, n - 1, s);
        vector<int> ans;

        for (int i = 0; i < qi.size(); i++) {
            int pos = qi[i];
            char c = qchar[i];
            update(1, 0, n - 1, pos, c);
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};