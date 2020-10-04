#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	long long sum = 0;
	long long pow2 = 1;

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		long long t = (pow2 * i) % MOD;
		t = (MOD + t - sum) % MOD;

		ans += (t * arr[n - i]);
		ans %= MOD;

		sum = (sum + t) % MOD;
		pow2 = (pow2 * 2) % MOD;
	}

	cout << ans;
}