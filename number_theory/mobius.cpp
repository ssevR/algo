
int prime[N];
int mu[N];
void sieve_calc() {
    std::iota(prime, prime + N, 0);

    for (int i = 2; i * i < N; ++i) {
        if (prime[i] == i) {
            for (int j = i * i; j < N; j += i)
                if (prime[j] == j) prime[j] = i;
        }
    }
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        int cur = i;
        cur /= prime[i];
        if (cur % prime[i] == 0) {
            mu[i] = 0;
        } else {
            mu[i] = -mu[cur];
        }
    }
}
