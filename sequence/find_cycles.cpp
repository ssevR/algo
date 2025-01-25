//find all cycles in permutation
vector<vector<int> > find_cycles(const vector<int> &p) {
    vector<vector<int> > cycles;
    int n = p.size();
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int cur = i;
            vector<int> v;
            while(!used[cur]) {
                v.push_back(cur);
                used[cur] = 1;
                cur = p[cur];
            }
            cycles.push_back(v);
        }
    }
    return cycles;
}

