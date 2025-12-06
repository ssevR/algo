template <typename T, T (*f)(T, T), T(*e)()> struct sparse_tree {
    int n;
    int k;
    vector<vector<T> > st;
    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    sparse_tree(const vector<T>& a) {
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

pair<int, int> f(pair<int, int> lhs, pair<int, int> rhs) {
	return min(lhs, rhs);
}

pair<int, int> e() {
	return {INF, INF};
}



struct lca {
	vector<vector<int> > g;
	int n;
	unique_ptr<struct sparse_tree<pair<int, int>, f, e> > st;
	vector<pair<int, int> > euler_path;
	vector<int> used, lvl, tin;
	int tim = 0;

	void dfs(int v) {
		used[v] = 1;
		euler_path.emplace_back(lvl[v], v);
		tin[v] = tim++;

		for (auto u : g[v])
			if (!used[u]) {
				lvl[u] = lvl[v] + 1;
		    	dfs(u);
				euler_path.emplace_back(lvl[v], v);
				tin[v] = tim++;

			}

	};

	lca(const vector<vector<int> >& ng) : g(ng) {
		tim = 0;
		n = g.size();
		used.assign(n, 0);
		lvl.assign(n, 0);
		tin.assign(n, 0);
		euler_path.reserve(2 * n - 1);
		dfs(0);
		st = make_unique<sparse_tree<pair<int, int>, f, e> > (euler_path);
	}
	int find_lca(int a, int b) {
		if (tin[a] > tin[b])
			swap(a, b);
		return st->prod(tin[a], tin[b] + 1).second;
	}
};

