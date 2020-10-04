#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;

long long num(int n) {
	long long ret = 0;
	long long p = 1;
	for (int i = n; i >= 1; --i) {
		p *= i;
		p %= MOD;
		ret = (ret + p) % MOD;
	}
	ret++;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	long long N = 0, C = 0, NC = 0, CN = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		bool nn = 0, cc = 0, nc = 0;
		for (char u: s) {
			if (u == 'N') nn = 1;
			if (u == 'C') {
				if (nn) nc = 1;
				cc = 1;
			}
		}
		if (nc) NC++;
		else {
			if (nn && cc) CN++;
			else if (nn) N++;
			else C++;
		}
	}

	long long ans = num(n);

	N = num(N);
	C = num(C);
	ans -= (N * C) % MOD;
	if (ans < 0) ans += MOD;

	long long sub = 1;
	sub = (sub * N) % MOD;
	sub = (sub * C) % MOD;
	sub = (sub * CN) % MOD;

	ans -= sub;
	if (ans < 0) ans += MOD;
	cout << ans % MOD;
}