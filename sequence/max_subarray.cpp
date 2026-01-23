//be aware of overflow for int!
template <typename T>
T find_max_subarray(const vector<T>& a, int* l = nullptr, int* r = nullptr) {
	int n = a.size();
	T cur = 0, mi = 0, res = a[0];
	int mi_ind = 0;

	for (int i = 0; i < n; ++i) {
		cur += a[i];
		if (cur - mi > res) {
			res = cur - mi;
			if (l && r) {
				*l = mi_ind;
				*r = i + 1;
			}
		}
		if (cur < mi) {
			mi = cur;
			mi_ind = i + 1;
		}
	}
	return res;
}

