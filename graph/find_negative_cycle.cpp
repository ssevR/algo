pair<bool, vector<int> >  find_negative_cycle(const vector<vector<pii> >& g) {
    int n = g.size();
    vector<ll> dist(n, 0);

    vector<int> pr(n);

    for (int i = 0; i < n; ++i) 
        for (int v = 0; v < n; ++v)
            for (auto [u, w] : g[v]) 
                if (dist[u] > dist[v] + w) {
                    dist[u] = dist[v] + w;  //watchout overflow if w is long long
                    pr[u] = v;
                }
        for (int v = 0; v < n; ++v)
            for (auto [u, w] : g[v]) 
                if (dist[u] > dist[v] + w) {
                    int cur = v;
                    for (int i = 0; i < n; ++i)
                        cur = pr[cur];

                    vector<int> res;

                    int beg = cur;
                    do {
                        res.push_back(cur);
                        cur = pr[cur];
                    } while(beg != cur);

                    reverse(res.begin(), res.end());
                    return {true, res};
                }
    return {false, vector<int>()};
}
