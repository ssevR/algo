struct line {
    ll k, b;
    ll operator()(const ll x) const {
        return x * k + b;
    }
};

struct li_chao {
    vector<line> tree;
    int size;
    int shift;

    void init(int n) {
        shift = 1 << (int(log2(n) + 1));
        size = shift * 2;
        tree.assign(size, line{0ll, LINF}); // LINF == 1e18
    }

    void insert(int i, int lx, int rx, line L) {
        int mx = (lx + rx) / 2;
        if (L(lx) < tree[i](lx)) 
            swap(L, tree[i]);
        if (lx == rx || L(rx) >= tree[i](rx))
            return;
        if (L(mx) < tree[i](mx)) {
            swap(L, tree[i]);
            insert(2 * i, lx, mx, L);
        }
        else {
            insert(2 * i + 1, mx + 1, rx, L);
        }
    }
    ll query(int i, int lx, int rx, int pos) {
        if (lx == rx)
            return tree[i](pos);
        int mx = (lx + rx) / 2;
        if (pos <= mx) 
            return min(tree[i](pos), query(2 * i, lx, mx, pos));
        else 
            return min(tree[i](pos), query(2 * i + 1, mx + 1, rx, pos));
    }

    void insert(line L) {
        insert(1, 0, shift - 1, L);
    }
    ll query(int x) {
        return query(1, 0, shift - 1, x);
    }
};

