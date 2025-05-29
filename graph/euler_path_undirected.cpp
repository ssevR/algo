//find euler_path in undirected graph
vector<int> find_euler_path(vector<vector<pii> > & g) {
	int n = g.size();
	int m = 0;
	int s = -1;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() % 2 == 1 || (g[i].size() > 0 && s == -1)) 
			s = i;
		m += g[i].size();
	}
	m /= 2;

	if (s == -1) return vector<int>();
    vector<int> path;
    vector<int> used(m);

	int cnt_odd = 0;
	for (int i = 0; i < n; ++i)
		cnt_odd += g[i].size() % 2;
	if (cnt_odd > 2) return vector<int>();


    stack<int> st;
	st.push(s);

    while(!st.empty()) {
        int v = st.top();
        if (!g[v].empty()) {
            auto [u, idx] = g[v].back();
            g[v].pop_back();
            if (!used[idx]) {
                used[idx] = 1;
                st.push(u);
            }
        }
        else {
            path.push_back(v);
            st.pop();
        }
    }
    if (path.size() != m + 1)
        path.clear();
    return path;
}
