struct trie {
	vector<array<int, 2> > d;
	vector<int> cnt;
	int sz = 0;
	trie() {
		d.push_back({-1, -1});
		cnt.push_back(0);
		sz = 1;
	}
	void add(int x, int f = 1) {
		for (int i = 29, cur = 0; i >= 0; --i) {
 
			int ch = 0;
			if ((1 << i) & x) 
				ch = 1;
 
			if (d[cur][ch] == -1) {
				d[cur][ch] = sz;
				d.push_back({-1, -1});
				cnt.push_back(0);
				++sz;
			}
			cur = d[cur][ch];
			cnt[cur] += f;
		}
	};
	int find_max(int x) {
		int y = 0;
		for (int i = 29, cur = 0; i >= 0; --i) {
			int ch = 0;
			if (x & (1 << i)) 
				ch = 0;
			else 
				ch = 1;
			if (d[cur][ch] == -1 || cnt[d[cur][ch]] == 0) 
				ch ^= 1;
			cur = d[cur][ch];
			y |= ch * (1 << i);
		}
		return x ^ y;
	};
};

