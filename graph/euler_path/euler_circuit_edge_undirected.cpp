//find euler circuit in undirected graph
// returns one circuit (edge indices) per connected component with edges
// returns empty outer vector if any vertex has odd degree
vector<vector<int> >  euler_circuit_edge(vector<vector<pair<int, int> > > g) {
	int n = g.size();

	int m = 0;
	vector<vector<int> > circuits;
	circuits.reserve(n);
	for (int i = 0; i < n; ++i) {
		if (g[i].size() % 2)
			return {};
		for (auto [v, ind] : g[i])
			m = max(m, ind + 1);
	}

    vector<int> used(m);
	vector<int> usedv(n);

	for (int s = 0; s < n; ++s) {
		if (usedv[s] || g[s].empty()) continue;

    	stack<int> st, edge_st;
		st.push(s);
		edge_st.push(-1);
		circuits.push_back({});

		while(!st.empty()) {
			int v = st.top();
			usedv[v] = 1;
			while(!g[v].empty() && used[g[v].back().second])
				g[v].pop_back();

			if (!g[v].empty()) {
				auto [u, idx] = g[v].back();
				g[v].pop_back();
				used[idx] = 1;
				st.push(u);
				edge_st.push(idx);
			}
			else {
				int e = edge_st.top();

				st.pop();
				edge_st.pop();
				if (e != -1) circuits.back().push_back(e);
			}
		}
	}

	return circuits;

}

