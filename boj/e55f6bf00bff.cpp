#include <iostream>
#define MOD 1000000000
using namespace std;

void mul(long long a[4], long long b[4]) {
	long long c[4];
	c[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
	c[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
	c[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
	c[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
	for (int i = 0; i < 4; ++i) a[i] = c[i];
}

void pow(long long a[4], long long b) {
	if (b == 1) return;
	if (b & 1) {
		long long c[4];
		for (int i = 0; i < 4; ++i) c[i] = a[i];
		pow(a, b - 1);
		mul(a, c);
	}
	else {
		mul(a, a);
		pow(a, b / 2);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;

	bool neg = false;
	if (n == 0) {
		cout << 0 << '\n' << 0;
		return 0;
	}
	else if (n < 0) {
		n = -n;
		if (n % 2 == 0) neg = true;
	}

	long long base[4] = {0, 1, 1, 1};
	pow(base, n);

	if (neg) cout << -1 << '\n';
	else cout << 1 << '\n';
	cout << base[1];

	return 0;
}