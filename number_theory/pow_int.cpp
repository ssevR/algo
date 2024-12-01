// returns biggest x such that a >= x^2

ll sqrt_ll(ll a) {
    ll x = sqrtl(a) + 1;
    while(x * x > a)
        --x;
    return x;
}

// returns biggest x such that a >= x^3
ll cub_ll(ll a) {
    ll x = powl(a, 1.0/3) + 1;
    while(x * x * x > a)
        --x;
    return x;
}
