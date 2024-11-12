void ternary() {
	for (int C = 2; C < 200; C++) {
		int l = 1, r = 2e8;
		while (r - l > C) {
			int midl = l + (r - l) / C;
			int midr = r - (r - l) / C;
			if (f(midl) > f(midr)) l = midl;
			else r = midr;
		}
		for (int i = l; i <= r; i++) res = min(res, f(i));
	}
	cout << ans;
}
