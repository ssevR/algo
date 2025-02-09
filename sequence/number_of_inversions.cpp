
// :r algo/seg_tree/sum_fw.cpp
ll number_of_inversions(const vector<int>& perm) {
    int n = perm.size();
    fenwick_tree<int> fw(n);

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += fw.sum(perm[i], n);
        fw.add(perm[i], 1);
    }

    return res;
}
