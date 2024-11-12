vector<int> prefix_function(const string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// all occurrences of the string  s  in the text  t
vector<int> kmp(const string& t, const string& s) { 

    string f = s + "#" + t;
    auto pi = prefix_function(f);

    vector<int> res;
    int l = s.size();
    for (int i = l + 1; i < f.size(); ++i) {
        if (pi[i] == l)
            res.push_back(i - (l + 1) - (l - 1));
    }
    return res;
}

