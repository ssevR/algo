// find euler circuits in directed graph
// returns one circuit (edge indices) per weakly connected component with edges
// returns empty outer vector if some vertex has indeg != outdeg
vector<vector<int> > euler_circuit_edge_directed(vector<vector<pair<int, int> > > g) {
	int n = g.size();
	int m = 0;
	int edge_cnt = 0;
	vector<int> indeg(n), outdeg(n);
	for (int i = 0; i < n; ++i) {
		for (auto [u, ind] : g[i]) {
			outdeg[i]++;
			indeg[u]++;
			m = max(m, ind + 1);
			edge_cnt++;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (indeg[i] != outdeg[i])
			return {};
	}

	vector<int> used(m);
	int used_edge_cnt = 0;
	vector<vector<int> > circuits;
	circuits.reserve(n);

	for (int s = 0; s < n; ++s) {
		while (!g[s].empty() && used[g[s].back().second])
			g[s].pop_back();
		if (g[s].empty()) continue;

		stack<int> st, edge_st;
		st.push(s);
		edge_st.push(-1);
		circuits.push_back({});

		while (!st.empty()) {
			int v = st.top();
			while (!g[v].empty() && used[g[v].back().second])
				g[v].pop_back();

			if (!g[v].empty()) {
				auto [u, idx] = g[v].back();
				g[v].pop_back();
				if (!used[idx]) {
					used[idx] = 1;
					used_edge_cnt++;
					st.push(u);
					edge_st.push(idx);
				}
			} else {
				int e = edge_st.top();
				edge_st.pop();
				st.pop();
				if (e != -1) circuits.back().push_back(e);
			}
		}

		reverse(circuits.back().begin(), circuits.back().end());
	}

	if (used_edge_cnt != edge_cnt)
		return {};

	return circuits;
}
