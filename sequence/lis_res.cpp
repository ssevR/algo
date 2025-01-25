//source: https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
//checker: https://judge.yosupo.jp/problem/longest_increasing_subsequence
//const int INF = 1e9 + 100;

// return indexes
vector<int> calc_lis(const vector<int>& x) {
    int n = x.size();
    vector<pair<int, int> > dp(n, make_pair(INF, INF));
    //vector<int> res(n); //see lis.cpp

    vector<int> prev(n, -1);

    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(dp.begin(), dp.end(), make_pair(x[i], -INF)) - dp.begin();
        dp[ind] = make_pair(x[i], i);
        if (ind) {
            prev[i] = dp[ind - 1].second;
        }
    }

    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i].first < INF) {
            len = i + 1;
        }
    }

    vector<int> lis;

    int cur = dp[len - 1].second;
    while(cur != -1) {
        lis.push_back(cur);
        cur = prev[cur];
    }
    reverse(lis.begin(), lis.end());

    return lis;
}
