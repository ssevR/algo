template<typename T>
vector<T> dij(int st, vector<vector<pair<int, T> > >& g, T inf) {
    int n = g.size();
    vector<T> dist(n, inf); // LINF = 1e18

    priority_queue<pair<T, int > , vector<pair<T, int> >, greater<> > q;

    q.push({T(0), st});
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
