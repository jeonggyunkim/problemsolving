#include <iostream>
#define MOD 1000000007
#define N 4000000
using namespace std;

int fac[N + 1] = {1, 1}, facinv[N + 1] = {1, 1}, inv[N + 1] = {0, 1};

int findInv(int n) {
	if (inv[n] > 0) return inv[n];
	return inv[n] = (((long long)MOD - MOD / n) * findInv(MOD % n)) % MOD;
}

int comb(int n, int k) {
	long long r = ((long long)fac[n] * facinv[n - k]) % MOD;
	r = (r * facinv[k]) % MOD;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= N; ++i) {
		fac[i] = ((long long)fac[i - 1] * i) % MOD;
		findInv(i);
		facinv[i] = ((long long)facinv[i - 1] * inv[i]) % MOD;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int n, k;
		cin >> n >> k;
		cout << comb(n, k) << '\n';
	}
}