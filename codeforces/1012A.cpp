#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, nn;
	cin >> n;
	nn = n * 2;

	vector<int> arr(nn);
	for (int i = 0; i < nn; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end());
	long long ans, now;
	ans = arr[nn - 1] - arr[n];
	ans *= arr[n - 1] - arr[0];
	for (int i = 1; i < n; ++i) {
		now = arr[n - 1 + i] - arr[i];
		now *= arr[nn - 1] - arr[0];
		ans = min(ans, now);
	}

	cout << ans;
}