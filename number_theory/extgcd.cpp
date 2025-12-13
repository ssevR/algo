// x * a + b * y == gcd(a, b)
// if a b are long long use __int128

ll extgcd(ll a, ll b, ll &x,ll &y)
{
	if (!b) {
		x = 1,y = 0;
		return a;
	}
	ll g=extgcd(b,a%b,x,y),t=x;
	x = y,y = t - a/b * y;
	return g;
}
