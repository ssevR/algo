#include <iostream>
#include <vector>
#include <string>


using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> trie(1);

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back(v, ch);
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;

    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (trie[v].link == -1) {
        if (v == 0 || trie[v].p == 0)
            trie[v].link = 0;
        else
            trie[v].link = go(get_link(trie[v].p), trie[v].pch);
    }
    return trie[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (trie[v].go[c] == -1) {
        if (trie[v].next[c] != -1)
            trie[v].go[c] = trie[v].next[c];
        else
            trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return trie[v].go[c];
}

vector<int> cnt;
vector<vector<int> > g;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<string> t(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
        add_string(t[i]);
    }
    cnt.resize(trie.size());
    g.resize(trie.size());

    int cur = 0;
    for (auto c : s) {
        cur = go(cur, c);
        ++cnt[cur];
    }
    for (int i = (int)cnt.size() - 1; i >= 1; --i) {
        int l = get_link(i);
        g[l].push_back(i);
    }
}
