// https://neerc.ifmo.ru/wiki/index.php?title=%D0%98%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%BE%D0%B1%D1%85%D0%BE%D0%B4%D0%B0_%D0%B2_%D0%B3%D0%BB%D1%83%D0%B1%D0%B8%D0%BD%D1%83_%D0%B4%D0%BB%D1%8F_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA%D0%B0_%D1%82%D0%BE%D1%87%D0%B5%D0%BA_%D1%81%D0%BE%D1%87%D0%BB%D0%B5%D0%BD%D0%B5%D0%BD%D0%B8%D1%8F
// for undirected graph 
// returns vector of size n

vector<int> cut_points(vector<vector<int> >& g) {
    int n = g.size();
    int timer = 0;
    vector<int> used(n);
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> is_art(n);

    auto dfs = [&](int v, int p, auto&&dfs) -> void {
        used[v] = 1;
        low[v] = tin[v] = ++timer;

        int children = 0;
        for (auto u : g[v]) {
            if (u == p)
                continue;
            else if (used[u])
                low[v] = min(low[v], tin[u]);
            else {
                ++children;
                dfs(u, v, dfs);
                if (p != -1 && low[u] >= tin[v]) 
                    is_art[v] = 1;
                low[v] = min(low[v], low[u]);
            }
        }
        if (p == -1 && children > 1) {
            is_art[v] = 1;
        }
    };

    for (int i = 0; i < n; ++i)
        if (!used[i]) dfs(i, -1, dfs);

    vector<int> res;
    for (int i = 0; i < n; ++i)
        if (is_art[i])
            res.push_back(i);

    return res;
}

