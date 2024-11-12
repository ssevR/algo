
const int INF = 1e9;
const int N = 2e5 + 10;
const int F = 5;

int P[5] = {INF + 7, INF + 9, INF + 21, INF + 33, INF + 87};
int MOD[5] = {INF + 93, INF + 97, INF + 103, INF + 123, INF + 181};
int P_inv[F];
int POW[F][N];

int mul(int a, int b, int MOD) {
    return 1ll * a * b % MOD;
}
int add(int a, int b, int MOD) {
    return ((a + b) % MOD + MOD) % MOD;
}

int bpow(int a, int p, int MOD){
    int res = 1;

    for (;p; p /= 2, a = mul(a, a, MOD))
        if (p & 1)
            res = mul(res, a, MOD);

    return res;
}

int main() {
    for (int i = 0; i < F; ++i) {
        P_inv[i] = bpow(P[i], MOD[i] - 2, MOD[i]);
        POW[i][0] = 1;
        for (int j = 1; j < N; ++j)
            POW[i][j] = mul(POW[i][j - 1], P[i], MOD[i]);
    }
}
