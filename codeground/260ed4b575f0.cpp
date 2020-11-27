#include <iostream>
#define MOD 1000000007
using namespace std;

int power(long long base, int index) {
	long long r = 1;
	while (index != 0) {
		if (index & 1) r = (r * base) % MOD;
		base = (base * base) % MOD;
		index >>= 1;
	}
	return r;
}

int fac[2000010];
int facinv[2000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fac[0] = 1;
	for (long long i = 1; i <= 2000002; ++i) fac[i] = (fac[i - 1] * i) % MOD;

	facinv[2000002] = power(fac[2000002], MOD - 2);
	for (long long i = 2000001; i >= 1; --i) facinv[i] = (facinv[i + 1] * (i + 1)) % MOD;

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, m;
		cin >> n >> m;

		long long ans = fac[m + n + 2];
		(ans *= facinv[m + 1]) %= MOD;
		(ans *= facinv[n + 1]) %= MOD;
		(ans += MOD - 1) %= MOD;

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}