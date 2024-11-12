// returns false if negative cycle does exist
bool ford_bellman(int st, const vector<vector<pii> >& g, vector<ll>& dist) {
    fill(dist.begin(), dist.end(), LINF); // LINF == 1e18
    dist[st] = 0;

    int n = g.size();
    for (int i = 0; i < n; ++i) 
        for (int v = 0; v < n; ++v)
            for (auto [u, w] : g[v]) 
                if (dist[u] > dist[v] + w) {
                    dist[u] = dist[v] + w;  //watchout overflow if w is long long
                }
        for (int v = 0; v < n; ++v)
            for (auto [u, w] : g[v]) 
                if (dist[u] < LINF/2 && dist[u] > dist[v] + w) { // dist[u] < LINF/2 means is u reachable from v
                    return false;
                }
    return true;

}
