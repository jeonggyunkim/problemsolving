#include <iostream>
#define MOD 1000003
#define N 100000
using namespace std;

int fac[N + 1], facinv[N + 1];

int power(long long base, int index) {
	long long r = 1;
	while (index != 0) {
		if (index & 1) r = (r * base) % MOD;
		base = (base * base) % MOD;
		index >>= 1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fac[0] = 1;
	for (long long i = 1; i <= N; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	facinv[N] = power(fac[N], MOD - 2);
	for (long long i = N - 1; i >= 0; --i) {
		facinv[i] = (facinv[i + 1] * (i + 1)) % MOD;
	}
	
	int tc;
	cin >> tc;

	while (tc--) {
		int n, r, k;
		cin >> n >> r >> k;

		long long ans = 1;
		(ans *= fac[r]) %= MOD;
		(ans *= facinv[k]) %= MOD;
		(ans *= facinv[r - k]) %= MOD;
		(ans *= power(2 * n - 1, r - k)) %= MOD;
		cout << ans << '\n';
	}
}