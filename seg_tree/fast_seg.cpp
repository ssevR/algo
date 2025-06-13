// fast segment.
template <typename T, T (*f)(T, T), T (*e)()>
struct fast_seg {
    int n, shift;
    T t[N];
    fast_seg(T *a, int sz) {
        n = sz;
        shift = (1 << (int)(log2(n) + 1));
        for (int i = shift; i < shift * 2; ++i) {
            if (i - shift < n)
                t[i] = a[i];
            else
                t[i] = e;
        }
        for (int i = shift - 1; i > 0; --i) t[i] = f(t[i * 2], t[i * 2 + 1]);
    }

    T query(int l, int r) {
        T res = e();
        l += shift, r += shift - 1;
        while (l <= r) {
            if (l & 1) {
                res = f(res, t[l]);
            }
            if (!(r & 1)) {
                res = f(res, t[r]);
            }
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        return res;
    }

    void update(int i, T val) {
        t[i += shift] = val;
        while (i /= 2) {
            t[i] = f(t[i * 2], t[i * 2 + 1]);
        }
    }
};
