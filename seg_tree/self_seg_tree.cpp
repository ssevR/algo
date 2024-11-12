//https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C

struct seg_tree {
    vector<int> tree;
    int size;
    int shift;
    const int NO_OP = INT32_MIN;
 
    void init(int n) {
        shift = (1 << int(log2(n) + 1));
        size = shift * 2;
        tree.assign(size, NO_OP);
    }
 
    void init(vector <int> a) {
        shift = (1 << int(log2(a.size()) + 1));
        size = shift * 2;
        tree.assign(size, NO_OP);
        for (int i = shift; i < shift * 2; ++i) {
            if (i - shift < a.size())
                tree[i] = a[i - shift];
        }
    }
 
    void push(int x) {
        if (tree[x] == NO_OP || x >= shift) {
            return;
        }
 
        tree[x * 2] = tree[x];
        tree[x * 2 + 1] = tree[x];
        tree[x] = NO_OP;
    }
 
    void add(int l, int r, int val, int x, int lx, int rx) {
        push(x);
        if (r < lx || l > rx || lx > rx) {
            return;
        }
 
        if (l <= lx && rx <= r) {
            tree[x] = val;
            return;
        }
 
        int mx = (lx + rx) / 2;
        add(l, r, val, x * 2, lx, mx);
        add(l, r, val, x * 2 + 1, mx + 1, rx);
    }
 
    int get(int i) {
        int res = tree[i += shift];
        while(i /= 2) {
            if (tree[i] != NO_OP) {
                res = tree[i];
            }
        }
 
        if (res == NO_OP) {
            res = 0;
        }
 
        return res;
    }
};
 
