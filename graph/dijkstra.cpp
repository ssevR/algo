vector<long long> dij(int st, vector<vector<pair<int, int> > >& g) {
    int n = g.size();
    vector<long long> dist(n, LINF); // LINF = 1e18

    priority_queue<pair<long long, int > , vector<pair<long long, int> >, greater<> > q;

    q.push({0, st});
    while(!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        if (dist[v] < LINF)
            continue;
        dist[v] = d;

        for (auto [u, w] : g[v])
            q.push({d + w, u});
    }

    return dist;
}
