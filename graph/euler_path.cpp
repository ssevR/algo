//returns empty vector if path doesnt exist
//directed graph
//no multi edges!!
vector<int> find_euler_path(const vector<vector<int> > & g) {
    int n = (int)g.size();

    vector<unordered_set<int> > gs(n);
    for (int i = 0; i < n; ++i) {
        for (auto u : g[i]) {
            gs[i].insert(u);
        }
    }

    int st = -1;
    int cnt_odd = 0;
    int cnt_edges = 0;


    for (int i = 0; i < n; ++i) {
        if (g[i].size() % 2) {
            ++cnt_odd;
            st = i;
        }
        cnt_edges += g[i].size();
    }
    cnt_edges /= 2;

    if (cnt_odd > 2) {
        return vector<int>();
    }
    else if (st == -1) {
        for (int i = 0; i < n; ++i) {
            if (g[i].size()) {
                st = i;
                break;
            }
        }
        if (st == -1) {
            return vector<int>();
        }

    }

    stack<int> s;
    s.push(0);
    vector<int> res;
    while(!s.empty()) {
        int v = s.top();
        bool found_edge = false;
        for (auto u : gs[v]) {

            s.push(u);
            found_edge = true;
            gs[v].erase(u);
            gs[u].erase(v);
            break;
        }
        if (!found_edge) {
            s.pop();
            res.push_back(v);
        }
    }

    if (res.size() == cnt_edges + 1) {
        return res;
    }
    else {
        return vector<int>();
    }

}
