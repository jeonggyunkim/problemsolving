#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long power(long long base, long long index) {
	long long r = 1;
	while (index) {
		if (index & 1) r = (r * base) % MOD;
		base = (base * base) % MOD;
		index >>= 1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long x, k;
	cin >> x >> k;

	if (x == 0) {
		cout << 0;
		return 0;
	}

	long long a0 = (2 * x - 1) % MOD;
	long long b = power(2, k);

	long long ans = (a0 * b + 1) % MOD;
	cout << ans;
}