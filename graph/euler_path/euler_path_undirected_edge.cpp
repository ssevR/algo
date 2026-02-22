//find euler_edge_path in undirected graph
vector<int> find_euler_path(vector<vector<pair<int, int> > > g) {
	int n = g.size();
	int m = 0;
	int mx_ind = 0;
	int s = -1;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() % 2 == 1 || (g[i].size() > 0 && s == -1)) 
			s = i;
		m += g[i].size();
		for (auto [u, ind] : g[i])
			mx_ind = max(mx_ind, ind);
	}
	m /= 2;

	if (s == -1) return vector<int>();
    vector<int> edge_path;
    vector<int> used(mx_ind + 1);

	int cnt_odd = 0;
	for (int i = 0; i < n; ++i)
		cnt_odd += g[i].size() % 2;
	if (cnt_odd > 2) return vector<int>();


    stack<int> st, edge_st;
	st.push(s);
	edge_st.push(-1);

    while(!st.empty()) {
        int v = st.top();
        if (!g[v].empty()) {
            auto [u, idx] = g[v].back();
            g[v].pop_back();
            if (!used[idx]) {
                used[idx] = 1;
                st.push(u);
				edge_st.push(idx);
            }
        }
        else {
            st.pop();
			int e = edge_st.top();
			edge_st.pop();
			if (e != -1) edge_path.push_back(e);
        }
    }
    if (edge_path.size() != m)
        edge_path.clear();
    return edge_path;
}

