template<typename T>
vector<T> bfs01(int st, const vector<vector<pair<int, T> > >& g, T inf) {
    int n = g.size();
    vector<T> dist(n, inf); // LINF = 1e18

	vector<int> used(n);
    //priority_queue<pair<T, int > , vector<pair<T, int> >, greater<> > q;
	//
	deque<int> q;
	q.push_front(st);
	dist[st] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
		if (used[v]) 
			continue;
		used[v] = 1;
        for (auto [u, w] : g[v]) {
			T nd = dist[v] + w;
			if (!used[u] && nd < dist[u]) {
				dist[u] = nd;
				if (w == 0)
					q.push_front(u);
				else
					q.push_back(u);
			}
		}
    }

    return dist;
}
