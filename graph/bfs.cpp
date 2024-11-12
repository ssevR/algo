
vector<int> bfs(int st, const vector<vector<int> > & g) {
    int n = g.size();
    vector<int> used(n);

    queue<int> q;
    q.push(st);

    vector<int> dist(n, INF); // INF == 1e9
    used[st] = 1;
    dist[st] = 0;


    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (!used[u]) {
                used[u] = 1;
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    
    return dist;
}
