// if graph is not bipartite return empty vector
vector<int> bipartition(const vector<vector<int>>&g) {
	vector<int> colors(g.size(), -1);

	auto dfs = [&](int v, auto&& dfs) -> bool{
		for (auto u : g[v]) {
			if (colors[u] == -1) {
				colors[u] = (colors[v]^1);
				if (!dfs(u, dfs)) return false;
			}
			else if (colors[u] == colors[v]) {
				return false;
			}
		}
		return true;
	};

	for (int i = 0; i < g.size(); ++i)
		if (colors[i] == -1) {
			colors[i] = 0;
			if (!dfs(i, dfs)) return {};
		}

	return colors;
}
