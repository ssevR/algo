template <typename T, T (*f)(T, T), T (*e)()>
struct mergetree {
    int n;
    int shift;
    vector<multiset<T>> t;
    mergetree(int sz) {
        n = sz;
        shift = (1 << (int)(log2(n) + 1));
        t.assign(2 * shift, multiset<T>());
    }

    int query(int l, int r, T x) {
        if (l >= r) return e();

        T res = e();
        l += shift, r += shift - 1;
        while (l <= r) {
            if (l & 1) {
                // do someting
            }
            if (!(r & 1)) {
                // do someting
            }
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        return res;
    }

    void insert(int i, T val) {
        t[i += shift].insert(val);
        while (i /= 2) {
            t[i].insert(val);
        }
    }
    void erase(int i, T val) {
        t[i += shift].erase(val);
        while (i /= 2) {
            t[i].erase(val);
        }
    }
};
