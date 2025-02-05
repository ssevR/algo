// for undirected graphs finds path from s to t
vector<int> find_euler_path(vector<vector<pii>> &g, int n, int m, int s, int t) {
    vector<int> indeg(n, 0), outdeg(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto &edge : g[i]) {
            int u = edge.first;
            outdeg[i]++;
            indeg[u]++;
        }
    }
    if (outdeg[s] != indeg[s] + 1)
        return {};
    if (indeg[t] != outdeg[t] + 1)
        return {};
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

