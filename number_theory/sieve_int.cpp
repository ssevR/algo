int prime[N];
void sieve_calc() {
    std::iota(prime, prime + N, 0);

    for (int i = 2; i * i < N; ++i) {
        if (prime[i] == i) {
            for (int j = i * i; j < N; j += i) 
                if (prime[j] == j)
                    prime[j] = i;
        }
    }
}
