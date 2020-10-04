#include <iostream>
using namespace std;

int MOD;

long long fac[2001] = {1, 1}, facinv[2001] = {1, 1}, inv[2001] = {0, 1};

long long findInv(int n) {
	if (inv[n] > 0) return inv[n];
	return inv[n] = ((MOD - MOD / n) * findInv(MOD % n)) % MOD;
}

long long comb(int n, int k) {
	long long r = (fac[n] * facinv[n - k]) % MOD;
	r = (r * facinv[k]) % MOD;
	return r;
}

int lucas_comb(long long n, long long k) {
	int r = 1;
	while (n || k) {
		r = (r * comb(n % MOD, k % MOD)) % MOD;
		n /= MOD; k /= MOD;
	}
	return r;
}

int main() {
	long long n, k;
	cin >> n >> k >> MOD;

	for (int i = 2; i < MOD; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
		findInv(i);
		facinv[i] = (facinv[i - 1] * inv[i]) % MOD;
	}

	cout << lucas_comb(n, k);
}