const int K = 26;

struct Vertex {
    int next[K];
    int p = -1;
    char pch;
    int cnt = 0;
    bool output = false;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

int add_string(string const& s, int ind) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back(v, ch);
        }
        v = trie[v].next[c];
        ++trie[v].cnt;
    }
    trie[v].output = true;
}


