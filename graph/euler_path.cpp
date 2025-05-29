// for directed graphs finds path from s to t
// edges indexes should be < m
vector<int> find_euler_path(vector<vector<pii>> &g) {
	int n = g.size();
	int m = 0;
    vector<int> indeg(n, 0), outdeg(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto &edge : g[i]) {
            int u = edge.first;
            outdeg[i]++;
            indeg[u]++;
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
			if (indeg[i] == outdeg[i]) {
				s = t = i;
				break;
			}
		if (s == -1) return {};
	}


    for (int i = 0; i < n; ++i) {
        if (i == s || i == t) continue;
        if (indeg[i] != outdeg[i])
            return {};
    }

    vector<int> path;
    vector<int> used(m, 0); 
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        int v = st.top();
        if (!g[v].empty()) {
            auto [u, idx] = g[v].back();
            g[v].pop_back();
            if (!used[idx]) {
                used[idx] = 1;
                st.push(u);
            }
        } else {
            path.push_back(v);
            st.pop();
        }
    }

    if (path.size() != m + 1)
        return {};

    reverse(path.begin(), path.end());
    if (path.back() != t)
        return {};

    return path;
}

