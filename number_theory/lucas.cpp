mint C(int n, int k, int p) {
	if (k < 0 || k > n) return 0;

	if (k == 0)
		return 1;
	int ni = n % p, ki  = k % p;
	return _C[ni][ki] * C(n / 3, k / 3, p);
}
