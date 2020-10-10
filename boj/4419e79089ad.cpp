#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll power(ll base, ll index) {
	ll r = 1;
	while (index != 0) {
		if (index & 1) r = (r * base) % MOD;
		base = (base * base) % MOD;
		index >>= 1;
	}
	return r;
}

int main() {
	ll n, m;
	cin >> n >> m;

	ll ans = 1;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			ll t = (power(i, cnt * m + 1) + MOD - 1) % MOD;
			t = (t * power(i - 1, MOD - 2)) % MOD;
			ans = (ans * t) % MOD;
		}
	}
	if (n != 1) {
		ll t = (power(n, m + 1) + MOD - 1) % MOD;
		t = (t * power(n - 1, MOD - 2)) % MOD;
		ans = (ans * t) % MOD;
	}
	cout << ans;
}