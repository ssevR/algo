bool find_cycle(const vector<vector<int> >& g, vector<int>& cycle) {
    cycle.clear();
    int n = (int)g.size();

    vector<int> pr(n), color(n);

    auto dfs = [&](int v, vector<int>& cycle, auto&& dfs) -> bool { 
        color[v] = 1;
        for (auto u : g[v]) {
            if (color[u] == 0) {
                pr[u] = v;
                if (dfs(u, cycle, dfs)) { return true; };
            }
            else if (color[u] == 1) {
                int cur = v;
                while(cur != u) {
                    cycle.push_back(cur);
                    cur = pr[cur];
                }
                cycle.push_back(u);
                //cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());

                return true;
            }
        }
        color[v] = 2;

        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            if (dfs(i, cycle, dfs)) { return true; };
        }
    }

    return false;
}
