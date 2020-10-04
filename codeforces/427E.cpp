#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> arr(n);
	vector<ll> suml(n);
	vector<ll> sumr(n);

	for (int i = 0; i < n; ++i) cin >> arr[i];

	suml[0] = 0;
	for (int i = 1; i < n; ++i) suml[i] = suml[i - 1] + ((i + m - 1) / m) * (arr[i] - arr[i - 1]);

	sumr[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		int j = n - 1 - i;
		sumr[i] = sumr[i + 1] + ((j + m - 1) / m) * (arr[i + 1] - arr[i]);
	}

	long long ans = 987654321987654321LL;
	for (int i = 0; i < n; ++i) {
		long long now = suml[i] + sumr[i];
		ans = min(ans, now);
	}
	cout << ans * 2;
}