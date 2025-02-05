// for directed graphs find cycle from s
vector<int> find_euler_path(vector<vector<pii> > & g, int n, int m, int s) {
    vector<int> path;
    vector<int> used(m);
    stack<int> st;
    st.push(s);
    while(!st.empty()) {
        int v = st.top();
        if (!g[v].empty()) {
            auto [u, idx] = g[v].back();
            g[v].pop_back();
            if (!used[idx]) {
                used[idx] = 1;
                st.push(u);
            }
        }
        else {
            path.push_back(v);
            st.pop();
        }
    }
    if (path.size() != m + 1)
        path.clear();
    return path;
}
 
