//sum of greatest k numbers
// sum[] is T type!!
template <typename T> 
struct ksum {
	T sum[2] = {T(), T()};
	multiset<T> s[2];

	size_t k = 0;
	size_t sz = 0;

	void balance() {
		assert(k <= sz);
		while(s[0].size() > k) {
			T x = *s[0].begin();
			s[0].erase(s[0].begin());
			s[1].insert(x);

			sum[0] -= x;
			sum[1] += x;
		}
		while(s[0].size() < k) {
			T x = *s[1].rbegin();
			s[1].erase(prev(s[1].end()));
			s[0].insert(x);

			sum[0] += x;
			sum[1] -= x;
		}
	}
	void increase(int add = 1) {
		assert(add >= 0 || k >= -add);
		k += add;
		balance();
	}
	void decrease(int add = 1) {
		increase(-add);
	}
	void set(int f) {
		increase(f - int(k));
	}

	void insert(T x) {
		if (!s[0].empty() && x > (*s[0].begin())) {
			s[0].insert(x);
			sum[0] += x;
			++sz;
			balance();
		}
		else {
			s[1].insert(x);
			sum[1] += x;
			++sz;
		}
	}
	bool erase(T x) {
		auto it1 = s[1].find(x);
		if (it1 != s[1].end()) {
			s[1].erase(it1);
			sum[1] -= x;
			--sz;
			assert(k <= sz);
			return true;
		}
		auto it0 = s[0].find(x);
		if (it0 != s[0].end()) {
			s[0].erase(it0);
			sum[0] -= x;
			--sz;
			balance();
			return true;
		}
		return false;
	}
};

