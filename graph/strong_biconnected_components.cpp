// https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BA%D0%BE%D0%BC%D0%BF%D0%BE%D0%BD%D0%B5%D0%BD%D1%82_%D1%80%D1%91%D0%B1%D0%B5%D1%80%D0%BD%D0%BE%D0%B9_%D0%B4%D0%B2%D1%83%D1%81%D0%B2%D1%8F%D0%B7%D0%BD%D0%BE%D1%81%D1%82%D0%B8
// no multiedges/self edges
vector<int> edge_bi_con(const vector<vector<int> >& g) {
	int n = g.size();
	int max_color = 0;
	vector<int> colors(n, -1), up(n), tin(n), pr(n, -1), used(n);
	stack<int> st;

	int tim = 0;


	auto paint = [&](int v) -> void {
		int last = -1;
		while(last != v && !st.empty()) {
			colors[st.top()] = max_color;
			last = st.top();
			st.pop();
		}
		++max_color;
	};

	auto dfs = [&](int v, auto&&dfs) -> void {
		used[v] = 1;
		st.push(v);
		tin[v] = up[v] = ++tim;
		for (auto u : g[v]) {
			if (pr[v] == u) continue;
			if (used[u]) {
				up[v] = min(up[v], tin[u]);
			}
			else {
				pr[u] = v;
				dfs(u, dfs);
				up[v] = min(up[v], up[u]);
				if (up[u] > tin[v]) 
					paint(u);
			}
		}
	};
	if (n == 0) return colors;
	for (int v = 0; v < n; ++v) {
		if (used[v]) continue;
		dfs(v, dfs);
		if (st.empty()) continue;

		while (!st.empty()) {
			colors[st.top()] = max_color;
			st.pop();
		}
		++max_color;
	}

	return colors;
}

