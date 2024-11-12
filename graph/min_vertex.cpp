// v < p -> vertex in the first part
// s == sz - 2, t == sz - 1
vector<int> min_vertex (mf_graph<int>& mf, int s, int t, int p, int sz) {
    vector<vector<int> > g(sz - 2);

    vector<int> in_matching(p);

    for (auto e : mf.edges()) {
        if (e.from == s || e.to == t)
            continue;

        if (e.flow == 1) {
            g[e.to].push_back(e.from);
            in_matching[e.from] = 1;
        }
        else {
            g[e.from].push_back(e.to);
        }
    }

    vector<int> used(g.size());

    auto dfs = [&](int v, auto&& dfs) -> void {
        used[v] = 1;
        for (auto u : g[v])
            if (!used[u]) 
                dfs(u, dfs);
    };
    for (int v = 0; v < p; ++v) {
        if (!in_matching[v]) {
            dfs(v, dfs);
        }
    }

    vector<int> res;
    for (int v = 0; v < p; ++v) {
        if (!used[v])
            res.push_back(v);

    }
    for (int v = p; v < g.size(); ++v)
        if (used[v]) 
            res.push_back(v);
    return res;
}

