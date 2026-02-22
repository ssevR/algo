// for directed graphs finds path from s to t
vector<int> find_euler_path_edge(vector<vector<pair<int, int> >> g) {
	int n = g.size();
	int m = 0;
	int mx_ind = 0;
    vector<int> indeg(n, 0), outdeg(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto [u, ind] : g[i]) {
            outdeg[i]++;
            indeg[u]++;
			mx_ind = max(mx_ind, ind);
        }
		m += g[i].size();
    }
	int s = -1, t = -1;
	for (int i = 0; i < n; ++i)
		if (outdeg[i] == indeg[i] + 1) {
			s = i;
			break;
		}
	for (int i = 0; i < n; ++i) 
		if (outdeg[i] + 1 == indeg[i]) {
			t = i;
			break;
		}
	if (s == -1 || t == -1) {
		for (int i = 0; i < n; ++i)
			if (indeg[i] == outdeg[i] && indeg[i] + outdeg[i] > 0) {
				s = t = i;
				break;
			}
		if (s == -1) {
			for (int i = 0; i < n; ++i)
				if (indeg[i] == outdeg[i]) {
					s = t = i;
					break;
				}
		}
		if (s == -1) return {};
	}


    for (int i = 0; i < n; ++i) {
        if (i == s || i == t) continue;
        if (indeg[i] != outdeg[i])
            return {};
    }

    vector<int> edge_path;
    vector<int> used(mx_ind + 1, 0); 
    stack<int> st;
	stack<int> edge_st;
	edge_st.push(-1);
    st.push(s);
	int last_vertex = -1;

	while (!st.empty()) {
		int v = st.top();
		if (!g[v].empty()) {
			auto [u, idx] = g[v].back();
			g[v].pop_back();
			if (!used[idx]) {
				used[idx] = 1;
				st.push(u);
					edge_st.push(idx);
			}
		} else {
				if (last_vertex == -1)
					last_vertex = v;

				int e = edge_st.top();
				edge_st.pop();
				if (e != -1) edge_path.push_back(e);
			st.pop();
		}
	}

	if (edge_path.size() != m || last_vertex != t) {
		return {};
	}

	reverse(edge_path.begin(), edge_path.end());

	return edge_path;
}
