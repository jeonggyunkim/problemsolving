#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int arr[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	int ans = 0;
	long long p = 11;
	while (arr[0]) {
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += arr[i] % 10;
			arr[i] /= 10;
		}
		sum = (sum * p) % MOD;
		sum = (sum * n) % MOD;
		ans += sum;
		ans %= MOD;
		p = (p * 100) % MOD;
	}
	cout << ans;
}