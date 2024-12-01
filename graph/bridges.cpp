// find all bridges of undirected graph with no multiedges
 
vector<pair<int, int> > find_bridges (vector<vector<int> >& g) {
    int n = g.size();
    vector<int> tin(n), low(n), used(n);
    vector<pair<int, int> > res;
    int timer = 0;
 
    auto dfs = [&](int v, int p, auto&& dfs) -> void {
        used[v] = 1;
        tin[v] = low[v] = ++timer;
        for (auto u : g[v]) {
            if (u == p)
                continue;
            else if (used[u]) {
                low[v] = min(low[v], tin[u]);
            }
            else {
                dfs(u, v, dfs);
                if (low[u] > tin[v]) {
                    res.emplace_back(v, u);
                }
                low[v] = min(low[v], low[u]);
            }
        }
    };
    for (int i = 0; i < n; ++i) 
        if (!used[i]) dfs(i, -1, dfs);
    return res;
}
