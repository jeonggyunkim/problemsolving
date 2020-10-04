#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef pair<int, int> ii;

long long fact[300010];

bool comp(ii& a, ii& b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[1] = 1;
	for (int i = 2; i <= 300000; ++i) fact[i] = (fact[i - 1] * i) % MOD;

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	long long f = 1, s = 1, b = 1;
	int con = 1;

	sort(arr.begin(), arr.end(), comp);
	for (int i = 1; i < n; ++i) {
		if (arr[i].second == arr[i - 1].second) con++;
		else {
			(s *= fact[con]) %= MOD;
			con = 1;
		}
	}
	(s *= fact[con]) %= MOD;

	con = 1;
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; ++i) {
		if (arr[i].first == arr[i - 1].first) con++;
		else {
			(f *= fact[con]) %= MOD;
			con = 1;
		}
	}
	(f *= fact[con]) %= MOD;

	con = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i - 1].second > arr[i].second) b = 0;
		if (arr[i] == arr[i - 1]) con++;
		else {
			(b *= fact[con]) %= MOD;
			con = 1;
		}
	}
	(b *= fact[con]) %= MOD;

	long long ans = 1;
	for (int i = 1; i <= n; ++i) (ans *= i) %= MOD;
	
	ans -= (f + s - b);
	while (ans < 0) ans += MOD;
	ans %= MOD;

	cout << ans;
}