int find_centroid(vector<vector<int> >& g) {
    int n = g.size();
    if (n == 1)
        return 0;

    vector<int> sz(n);
    auto dfs = [&](int v, int p, auto&& dfs) -> int {
        sz[v] = 1;

        int mx = 0;

        for (auto u : g[v]) {
            if (u == p)
                continue;
            auto tmp = dfs(u, v, dfs);
            sz[v] += sz[u];
            if (tmp != -1) {
                return tmp;
            }
            mx = max(mx, sz[u]);
        }
        if (mx <= n/2 && n - sz[v] <= n/2) {
            return v;
        }
        return -1;
    };
    return dfs(0, -1, dfs);
}
