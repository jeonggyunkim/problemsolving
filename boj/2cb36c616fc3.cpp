#include <iostream>
#define MOD 1000000007
using namespace std;

int power(long long base, int index, int mod) {
	long long r = 1;
	while (index != 0) {
		if (index & 1) r = (r * base) % mod;
		base = (base * base) % mod;
		index >>= 1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m;

	long long s, n;
	long long ans = 0;
	while (m--) {
		cin >> n >> s;
		ans += s * power(n, MOD - 2, MOD);
		ans %= MOD;
	}
	cout << ans;
}