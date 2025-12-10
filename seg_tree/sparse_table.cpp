template <typename T, T (*f)(T, T), T(*e)()> struct sparse_table {
    int n;
    int k;
    vector<vector<T> > st;
    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    sparse_table(const vector<T>& a) {
        n = a.size();
        k = log2_floor(n) + 1;
        st = vector(k, vector<T>(n, e()));
        copy(a.begin(), a.end(), st[0].begin());

        for (int i = 1; i < k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }


    T prod(int l, int r) {
        if (l < 0 || r > n || l > r) throw out_of_range("out of range");
        if (l == r) return e();
        int i = log2_floor(r - l);
        return f(st[i][l], st[i][r - (1 << i)]);
    }
};
