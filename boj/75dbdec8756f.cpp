#include <iostream>
using namespace std;

long long arr[500000], dp[500000], dp2[500000], mx[500000], mx2[500000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	dp[0] = arr[0];
	mx[0] = max(0ll, dp[0]);
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		mx[i] = max(mx[i - 1], dp[i]);
	}
	dp2[n - 1] = arr[n - 1];
	mx2[n - 1] = max(0ll, dp2[n - 1]);
	for (int i = n - 2; i >= 0; --i) {
		dp2[i] = max(dp2[i + 1] + arr[i], arr[i]);
		mx2[i] = max(mx2[i + 1], dp2[i]);
	}

	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans = max(ans, mx[i] + mx2[i + 1]);
	}
	for (int i = 0; i < n; ++i) ans += arr[i];
	cout << ans;
}