mint fact[N];
mint ifact[N];
mint inv[N];
 
 
mint C(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
 
    return fact[n] * ifact[k] * ifact[n - k];

}

void calc_init() {
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
        inv[i] = inv[MOD % i] * (MOD - MOD / i);
        ifact[i] = inv[i] * ifact[i - 1];
    }
}

mint _C[M][M];
void calc_C() {
    _C[0][0] = 1;
    for (int i = 1; i < M; ++i) {
        _C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            _C[i][j] = _C[i - 1][j - 1] + _C[i - 1][j];
    }
}
