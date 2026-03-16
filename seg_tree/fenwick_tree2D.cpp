template <typename T>
struct fenwick_tree2D {
    vector<vector<T>> bit;
    int n, m;

	FenwickTree2D(int n_, int m_) : n(n_), m(m_), bit(n_, vector<T>(m_, 0)) {}


	//inclusive
    T sum(int x, int y) {
		if (x < 0 || y < 0) return 0;
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }
	T sum(int x1, int y1, int x2, int y2) {
		if (x1 > x2 || y1 > y2) return 0;

		return sum(x2,y2)
			 - sum(x1-1,y2)
			 - sum(x2,y1-1)
			 + sum(x1-1,y1-1);
	};

	void add(int x, int y, T delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

