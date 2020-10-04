#include <bits/stdc++.h>
#define N 200000
#define MOD 1000000007
using namespace std;

long long fac[200010];
long long inv[200010];

long long power(long long n, int t) {
	long long r = 1;
	while (t) {
		if (t & 1) r = (r * n) % MOD;
		n = (n * n) % MOD;
		t /= 2;
	}
	return r;
}

long long c(int a, int b) {
	if (a == 0 || b == 0) return 1;
	long long ret = 1;
	ret = fac[a + b];
	(ret *= inv[a]) %= MOD;
	(ret *= inv[b]) %= MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fac[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}

	inv[N] = power(fac[N], MOD - 2);
	for (int i = N; i >= 2; --i) {
		inv[i - 1] = (inv[i] * i) % MOD;
	}

	int h, w, a, b;
	cin >> h >> w >> a >> b;

	long long ans = c(h - 1, w - 1);
	for (int i = 1; i <= b; ++i) {
		ans -= (c(w - i, a - 1) * c(i - 1, h - a - 1)) % MOD;
		if (ans < 0) ans += MOD;
	}
	cout << ans;
}