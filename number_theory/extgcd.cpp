// x * a + b * y == gcd(a, b)

ll extgcd(ll a, ll b, ll &x,ll &y)
{
	if (!b) {
		x = 1,y = 0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y),t=x;
	x = y,y = t - a/b * y;
	return g;
}
